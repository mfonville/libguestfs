/* libguestfs
 * Copyright (C) 2010-2012 Red Hat Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

/* Wrapper for running external command, loosely based on libvirt's
 * virCommand interface.  Read the comments at the top of each
 * function for detailed information on how to use this interface.  In
 * outline what you have to do is:
 *
 * (1) Create a new command handle:
 *
 *   struct command *cmd;
 *   cmd = guestfs___new_command (g);
 *
 * (2) EITHER add arguments:
 *
 *   guestfs___cmd_add_arg (cmd, "qemu-img");
 *   guestfs___cmd_add_arg (cmd, "info");
 *   guestfs___cmd_add_arg (cmd, filename);
 *
 * NB: You don't need to add a NULL argument at the end.
 *
 * (3) OR construct a command using a mix of quoted and unquoted
 * strings.  (This is useful for system(3)/popen("r")-style shell
 * commands, with the added safety of allowing args to be quoted
 * properly).
 *
 *   guestfs___cmd_add_string_unquoted (cmd, "qemu-img info ");
 *   guestfs___cmd_add_string_quoted (cmd, filename);
 *
 * (4) Set various flags, such as whether you want to capture
 * errors in the regular libguestfs error log.
 *
 * (5) Run the command.  This is what does the fork call, optionally
 * loops over the output, and then does a waitpid and returns the
 * exit status of the command.
 *
 *   r = guestfs___cmd_run (cmd);
 *   if (r == -1)
 *     // error
 *   // else test r using the WIF* functions
 *
 * (6) Close the handle:
 *
 *   guestfs___cmd_close (cmd);
 *
 * (or use CLEANUP_CMD_CLOSE).
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/select.h>

#include "guestfs.h"
#include "guestfs-internal.h"

enum command_style {
  COMMAND_STYLE_NOT_SELECTED = 0,
  COMMAND_STYLE_EXECV = 1,
  COMMAND_STYLE_SYSTEM = 2
};

struct command;

static void add_line_buffer (struct command *cmd, const char *buf, size_t len);
static void close_line_buffer (struct command *cmd);
static void add_unbuffered (struct command *cmd, const char *buf, size_t len);
static void add_whole_buffer (struct command *cmd, const char *buf, size_t len);
static void close_whole_buffer (struct command *cmd);

struct buffering {
  char *buffer;
  size_t len;
  void (*add_data) (struct command *cmd, const char *buf, size_t len);
  void (*close_data) (struct command *cmd);
};

struct command
{
  guestfs_h *g;

  enum command_style style;
  union {
    /* COMMAND_STYLE_EXECV */
    struct {
      char **args;
      size_t len, alloc;
    } argv;
    /* COMMAND_STYLE_SYSTEM */
    struct {
      char *str;
      size_t len, alloc;
    } string;
  };

  /* Capture errors to the error log (defaults to true). */
  bool capture_errors;
  int errorfd;

  /* Supply a callback to receive stdout. */
  cmd_stdout_callback stdout_callback;
  void *stdout_data;
  int outfd;
  struct buffering outbuf;

  /* For programs that send output to stderr.  Hello qemu. */
  bool stderr_to_stdout;

  /* PID of subprocess (if > 0). */
  pid_t pid;
};

/* Create a new command handle. */
struct command *
guestfs___new_command (guestfs_h *g)
{
  struct command *cmd;

  cmd = safe_calloc (g, 1, sizeof *cmd);
  cmd->g = g;
  cmd->capture_errors = true;
  cmd->errorfd = -1;
  cmd->outfd = -1;
  return cmd;
}

/* Add single arg (for execv-style command execution). */
static void
add_arg_no_strdup (struct command *cmd, char *arg)
{
  assert (cmd->style != COMMAND_STYLE_SYSTEM);
  cmd->style = COMMAND_STYLE_EXECV;

  if (cmd->argv.len >= cmd->argv.alloc) {
    if (cmd->argv.alloc == 0)
      cmd->argv.alloc = 16;
    else
      cmd->argv.alloc *= 2;
    cmd->argv.args = safe_realloc (cmd->g, cmd->argv.args,
                                   cmd->argv.alloc * sizeof (char *));
  }
  cmd->argv.args[cmd->argv.len] = arg;
  cmd->argv.len++;
}

static void
add_arg (struct command *cmd, const char *arg)
{
  assert (arg != NULL);
  add_arg_no_strdup (cmd, safe_strdup (cmd->g, arg));
}

void
guestfs___cmd_add_arg (struct command *cmd, const char *arg)
{
  add_arg (cmd, arg);
}

void
guestfs___cmd_add_arg_format (struct command *cmd, const char *fs, ...)
{
  va_list args;
  char *arg;

  va_start (args, fs);
  int err = vasprintf (&arg, fs, args);
  va_end (args);

  if (err < 0)
    cmd->g->abort_cb ();

  add_arg_no_strdup (cmd, arg);
}

/* Add strings (for system(3)-style command execution). */
static void
add_string (struct command *cmd, const char *str, size_t len)
{
  assert (cmd->style != COMMAND_STYLE_EXECV);
  cmd->style = COMMAND_STYLE_SYSTEM;

  if (cmd->string.len >= cmd->string.alloc) {
    if (cmd->string.alloc == 0)
      cmd->string.alloc = 256;
    else
      cmd->string.alloc += MAX (cmd->string.alloc, len);
    cmd->string.str = safe_realloc (cmd->g, cmd->string.str, cmd->string.alloc);
  }

  memcpy (&cmd->string.str[cmd->string.len], str, len);
  cmd->string.len += len;
}

void
guestfs___cmd_add_string_unquoted (struct command *cmd, const char *str)
{
  add_string (cmd, str, strlen (str));
}

/* Add a string enclosed in double quotes, with any special characters
 * within the string which need escaping done.  This is used to add a
 * single argument to a system(3)-style command string.
 */
void
guestfs___cmd_add_string_quoted (struct command *cmd, const char *str)
{
  add_string (cmd, "\"", 1);

  for (; *str; str++) {
    if (*str == '$' ||
        *str == '`' ||
        *str == '\\' ||
        *str == '"')
      add_string (cmd, "\\", 1);
    add_string (cmd, str, 1);
  }

  add_string (cmd, "\"", 1);
}

/* Set a callback which will capture stdout.
 *
 * If flags contains CMD_STDOUT_FLAG_LINE_BUFFER (the default), then
 * the callback is called line by line on the output.  If there is a
 * trailing \n then it is automatically removed before the callback is
 * called.  The line buffer is \0-terminated.
 *
 * If flags contains CMD_STDOUT_FLAG_UNBUFFERED, then buffers are
 * passed to the callback as it is received from the command.  Note in
 * this case the buffer is NOT \0-terminated, so you need to may
 * attention to the length field in the callback.
 *
 * If flags contains CMD_STDOUT_FLAG_WHOLE_BUFFER, then the callback
 * is called exactly once, with the entire buffer.  Note in this case
 * the buffer is NOT \0-terminated, so you need to may attention to
 * the length field in the callback.
 */
void
guestfs___cmd_set_stdout_callback (struct command *cmd,
                                   cmd_stdout_callback stdout_callback,
                                   void *stdout_data, unsigned flags)
{
  cmd->stdout_callback = stdout_callback;
  cmd->stdout_data = stdout_data;

  /* Buffering mode. */
  if ((flags & 3) == CMD_STDOUT_FLAG_LINE_BUFFER) {
    cmd->outbuf.add_data = add_line_buffer;
    cmd->outbuf.close_data = close_line_buffer;
  }
  else if ((flags & 3) == CMD_STDOUT_FLAG_UNBUFFERED) {
    cmd->outbuf.add_data = add_unbuffered;
    cmd->outbuf.close_data = NULL;
  }
  else if ((flags & 3) == CMD_STDOUT_FLAG_WHOLE_BUFFER) {
    cmd->outbuf.add_data = add_whole_buffer;
    cmd->outbuf.close_data = close_whole_buffer;
  }
  else
    abort ();
}

/* Equivalent to adding 2>&1 to the end of the command.  This is
 * incompatible with the capture_errors flag, because it doesn't make
 * sense to combine them.
 */
void
guestfs___cmd_set_stderr_to_stdout (struct command *cmd)
{
  cmd->stderr_to_stdout = true;
}

/* Clear the capture_errors flag.  This means that any errors will go
 * to stderr, instead of being captured in the event log, and that is
 * usually undesirable.
 */
void
guestfs___cmd_clear_capture_errors (struct command *cmd)
{
  cmd->capture_errors = false;
}

/* Finish off the command by either NULL-terminating the argv array or
 * adding a terminating \0 to the string, or die with an internal
 * error if no command has been added.
 */
static void
finish_command (struct command *cmd)
{
  switch (cmd->style) {
  case COMMAND_STYLE_EXECV:
    add_arg_no_strdup (cmd, NULL);
    break;

  case COMMAND_STYLE_SYSTEM:
    add_string (cmd, "\0", 1);
    break;

  case COMMAND_STYLE_NOT_SELECTED:
  default:
    abort ();
  }
}

static void
debug_command (struct command *cmd)
{
  size_t i, last;

  switch (cmd->style) {
  case COMMAND_STYLE_EXECV:
    debug (cmd->g, "command: run: %s", cmd->argv.args[0]);
    last = cmd->argv.len-1;     /* omit final NULL pointer */
    for (i = 1; i < last; ++i) {
      if (i < last-1 &&
          cmd->argv.args[i][0] == '-' && cmd->argv.args[i+1][0] != '-') {
        debug (cmd->g, "command: run: \\ %s %s",
               cmd->argv.args[i], cmd->argv.args[i+1]);
        i++;
      }
      else
        debug (cmd->g, "command: run: \\ %s", cmd->argv.args[i]);
    }
    break;

  case COMMAND_STYLE_SYSTEM:
    debug (cmd->g, "command: run: %s", cmd->string.str);
    break;

  case COMMAND_STYLE_NOT_SELECTED:
  default:
    abort ();
  }
}

static int
run_command (struct command *cmd)
{
  struct sigaction sa;
  int i, fd, max_fd, r;
  int errorfd[2] = { -1, -1 };
  int outfd[2] = { -1, -1 };
  char status_string[80];

  /* Set up a pipe to capture command output and send it to the error log. */
  if (cmd->capture_errors) {
    if (pipe2 (errorfd, O_CLOEXEC) == -1) {
      perrorf (cmd->g, "pipe2");
      goto error;
    }
  }

  /* Set up a pipe to capture stdout for the callback. */
  if (cmd->stdout_callback) {
    if (pipe2 (outfd, O_CLOEXEC) == -1) {
      perrorf (cmd->g, "pipe2");
      goto error;
    }
  }

  cmd->pid = fork ();
  if (cmd->pid == -1) {
    perrorf (cmd->g, "fork");
    goto error;
  }

  /* In parent, return to caller. */
  if (cmd->pid > 0) {
    if (cmd->capture_errors) {
      close (errorfd[1]);
      errorfd[1] = -1;
      cmd->errorfd = errorfd[0];
      errorfd[0] = -1;
    }

    if (cmd->stdout_callback) {
      close (outfd[1]);
      outfd[1] = -1;
      cmd->outfd = outfd[0];
      outfd[0] = -1;
    }

    return 0;
  }

  /* Child process. */
  if (cmd->capture_errors) {
    close (errorfd[0]);
    if (!cmd->stdout_callback)
      dup2 (errorfd[1], 1);
    dup2 (errorfd[1], 2);
    close (errorfd[1]);
  }

  if (cmd->stdout_callback) {
    close (outfd[0]);
    dup2 (outfd[1], 1);
    close (outfd[1]);
  }

  if (cmd->stderr_to_stdout)
    dup2 (1, 2);

  /* Remove all signal handlers.  See the justification here:
   * https://www.redhat.com/archives/libvir-list/2008-August/msg00303.html
   * We don't mask signal handlers yet, so this isn't completely
   * race-free, but better than not doing it at all.
   */
  memset (&sa, 0, sizeof sa);
  sa.sa_handler = SIG_DFL;
  sa.sa_flags = 0;
  sigemptyset (&sa.sa_mask);
  for (i = 1; i < NSIG; ++i)
    sigaction (i, &sa, NULL);

  /* Close all other file descriptors.  This ensures that we don't
   * hold open (eg) pipes from the parent process.
   */
  max_fd = sysconf (_SC_OPEN_MAX);
  if (max_fd == -1)
    max_fd = 1024;
  if (max_fd > 65536)
    max_fd = 65536;          /* bound the amount of work we do here */
  for (fd = 3; fd < max_fd; ++fd)
    close (fd);

  /* Clean up the environment. */
  setenv ("LC_ALL", "C", 1);

  /* Set the umask for all subcommands to something sensible (RHBZ#610880). */
  umask (022);

  /* Run the command. */
  switch (cmd->style) {
  case COMMAND_STYLE_EXECV:
    execvp (cmd->argv.args[0], cmd->argv.args);
    perror (cmd->argv.args[0]);
    _exit (EXIT_FAILURE);

  case COMMAND_STYLE_SYSTEM:
    r = system (cmd->string.str);
    if (r == -1) {
      perror ("system");
      _exit (EXIT_FAILURE);
    }
    if (WIFEXITED (r))
      _exit (WEXITSTATUS (r));
    fprintf (stderr, "%s\n",
             guestfs___exit_status_to_string (r, cmd->string.str,
                                              status_string,
                                              sizeof status_string));
    _exit (EXIT_FAILURE);

  case COMMAND_STYLE_NOT_SELECTED:
  default:
    abort ();
  }
  /*NOTREACHED*/

 error:
  if (errorfd[0] >= 0)
    close (errorfd[0]);
  if (errorfd[1] >= 0)
    close (errorfd[1]);
  if (outfd[0] >= 0)
    close (outfd[0]);
  if (outfd[1] >= 0)
    close (outfd[1]);

  return -1;
}

/* The loop which reads errors and output and directs it either
 * to the log or to the stdout callback as appropriate.
 */
static int
loop (struct command *cmd)
{
  fd_set rset, rset2;
  int maxfd = -1, r;
  size_t nr_fds = 0;
  char buf[BUFSIZ];
  ssize_t n;

  FD_ZERO (&rset);

  if (cmd->errorfd >= 0) {
    FD_SET (cmd->errorfd, &rset);
    maxfd = MAX (cmd->errorfd, maxfd);
    nr_fds++;
  }

  if (cmd->outfd >= 0) {
    FD_SET (cmd->outfd, &rset);
    maxfd = MAX (cmd->outfd, maxfd);
    nr_fds++;
  }

  while (nr_fds > 0) {
    rset2 = rset;
    r = select (maxfd+1, &rset2, NULL, NULL, NULL);
    if (r == -1) {
      if (errno == EINTR || errno == EAGAIN)
        continue;
      perrorf (cmd->g, "select");
      return -1;
    }

    if (cmd->errorfd >= 0 && FD_ISSET (cmd->errorfd, &rset2)) {
      /* Read output and send it to the log. */
      n = read (cmd->errorfd, buf, sizeof buf);
      if (n > 0)
        guestfs___call_callbacks_message (cmd->g, GUESTFS_EVENT_APPLIANCE,
                                          buf, n);
      else if (n == 0) {
        if (close (cmd->errorfd) == -1)
          perrorf (cmd->g, "close: errorfd");
        FD_CLR (cmd->errorfd, &rset);
        cmd->errorfd = -1;
        nr_fds--;
      }
      else if (n == -1) {
        perrorf (cmd->g, "read: errorfd");
        close (cmd->errorfd);
        FD_CLR (cmd->errorfd, &rset);
        cmd->errorfd = -1;
        nr_fds--;
      }
    }

    if (cmd->outfd >= 0 && FD_ISSET (cmd->outfd, &rset2)) {
      /* Read the output, buffer it up to the end of the line, then
       * pass it to the callback.
       */
      n = read (cmd->outfd, buf, sizeof buf);
      if (n > 0) {
        if (cmd->outbuf.add_data)
          cmd->outbuf.add_data (cmd, buf, n);
      }
      else if (n == 0) {
        if (cmd->outbuf.close_data)
          cmd->outbuf.close_data (cmd);
        if (close (cmd->outfd) == -1)
          perrorf (cmd->g, "close: outfd");
        FD_CLR (cmd->outfd, &rset);
        cmd->outfd = -1;
        nr_fds--;
      }
      else if (n == -1) {
        perrorf (cmd->g, "read: outfd");
        close (cmd->outfd);
        FD_CLR (cmd->outfd, &rset);
        cmd->outfd = -1;
        nr_fds--;
      }
    }
  }

  return 0;
}

static int
wait_command (struct command *cmd)
{
  int status;

  if (waitpid (cmd->pid, &status, 0) == -1) {
    perrorf (cmd->g, "waitpid");
    return -1;
  }

  cmd->pid = 0;

  return status;
}

/* Fork, run the command, loop over the output, and waitpid.
 *
 * Returns the exit status.  Test it using WIF* macros.
 *
 * On error: Calls error(g) and returns -1.
 */
int
guestfs___cmd_run (struct command *cmd)
{
  finish_command (cmd);

  if (cmd->g->verbose)
    debug_command (cmd);

  if (run_command (cmd) == -1)
    return -1;

  if (loop (cmd) == -1)
    return -1;

  return wait_command (cmd);
}

void
guestfs___cmd_close (struct command *cmd)
{
  size_t i;

  if (!cmd)
    return;

  switch (cmd->style) {
  case COMMAND_STYLE_NOT_SELECTED:
    /* nothing */
    break;

  case COMMAND_STYLE_EXECV:
    for (i = 0; i < cmd->argv.len; ++i)
      free (cmd->argv.args[i]);
    free (cmd->argv.args);
    break;

  case COMMAND_STYLE_SYSTEM:
    free (cmd->string.str);
    break;

  default:
    abort ();
  }

  if (cmd->errorfd >= 0)
    close (cmd->errorfd);

  if (cmd->outfd >= 0)
    close (cmd->outfd);

  free (cmd->outbuf.buffer);

  if (cmd->pid > 0)
    waitpid (cmd->pid, NULL, 0);

  free (cmd);
}

void
guestfs___cleanup_cmd_close (void *ptr)
{
  guestfs___cmd_close (* (struct command **) ptr);
}

/* Deal with buffering stdout for the callback. */
static void
process_line_buffer (struct command *cmd, int closed)
{
  guestfs_h *g = cmd->g;
  char *p;
  size_t len, newlen;

  while (cmd->outbuf.len > 0) {
    /* Length of the next line. */
    p = strchr (cmd->outbuf.buffer, '\n');
    if (p != NULL) {            /* Got a whole line. */
      len = p - cmd->outbuf.buffer;
      newlen = cmd->outbuf.len - len - 1;
    }
    else if (closed) {          /* Consume rest of input even if no \n found. */
      len = cmd->outbuf.len;
      newlen = 0;
    }
    else                        /* Need to wait for more input. */
      break;

    /* Call the callback with the next line. */
    cmd->outbuf.buffer[len] = '\0';
    cmd->stdout_callback (g, cmd->stdout_data, cmd->outbuf.buffer, len);

    /* Remove the consumed line from the buffer. */
    cmd->outbuf.len = newlen;
    memmove (cmd->outbuf.buffer, cmd->outbuf.buffer + len + 1, newlen);

    /* Keep the buffer \0 terminated. */
    cmd->outbuf.buffer[newlen] = '\0';
  }
}

static void
add_line_buffer (struct command *cmd, const char *buf, size_t len)
{
  guestfs_h *g = cmd->g;
  size_t oldlen;

  /* Append the new content to the end of the current buffer.  Keep
   * the buffer \0 terminated to make things simple when processing
   * the buffer.
   */
  oldlen = cmd->outbuf.len;
  cmd->outbuf.len += len;
  cmd->outbuf.buffer = safe_realloc (g, cmd->outbuf.buffer,
                                     cmd->outbuf.len + 1 /* for \0 */);
  memcpy (cmd->outbuf.buffer + oldlen, buf, len);
  cmd->outbuf.buffer[cmd->outbuf.len] = '\0';

  process_line_buffer (cmd, 0);
}

static void
close_line_buffer (struct command *cmd)
{
  process_line_buffer (cmd, 1);
}

static void
add_unbuffered (struct command *cmd, const char *buf, size_t len)
{
  cmd->stdout_callback (cmd->g, cmd->stdout_data, buf, len);
}

static void
add_whole_buffer (struct command *cmd, const char *buf, size_t len)
{
  guestfs_h *g = cmd->g;
  size_t oldlen;

  /* Append the new content to the end of the current buffer. */
  oldlen = cmd->outbuf.len;
  cmd->outbuf.len += len;
  cmd->outbuf.buffer = safe_realloc (g, cmd->outbuf.buffer, cmd->outbuf.len);
  memcpy (cmd->outbuf.buffer + oldlen, buf, len);
}

static void
close_whole_buffer (struct command *cmd)
{
  cmd->stdout_callback (cmd->g, cmd->stdout_data,
                        cmd->outbuf.buffer, cmd->outbuf.len);
}