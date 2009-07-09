/* libguestfs - the guestfsd daemon
 * Copyright (C) 2009 Red Hat Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../src/guestfs_protocol.h"
#include "daemon.h"
#include "actions.h"

char *
do_df ()
{
  int r;
  char *out, *err;

  NEED_ROOT (NULL);

  r = command (&out, &err, "df", NULL);
  if (r == -1) {
    reply_with_error ("df: %s", err);
    free (out);
    free (err);
    return NULL;
  }

  free (err);

  return out;			/* Caller frees. */
}

char *
do_df_h ()
{
  int r;
  char *out, *err;

  NEED_ROOT (NULL);

  r = command (&out, &err, "df", "-h", NULL);
  if (r == -1) {
    reply_with_error ("df -h: %s", err);
    free (out);
    free (err);
    return NULL;
  }

  free (err);

  return out;			/* Caller frees. */
}
