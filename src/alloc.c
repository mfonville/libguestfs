/* libguestfs
 * Copyright (C) 2009-2013 Red Hat Inc.
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

#include <config.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "guestfs.h"
#include "guestfs-internal.h"

#include "hash.h"

void *
guestfs___safe_malloc (guestfs_h *g, size_t nbytes)
{
  void *ptr = malloc (nbytes);
  if (nbytes > 0 && !ptr) g->abort_cb ();
  return ptr;
}

/* Return 1 if an array of N objects, each of size S, cannot exist due
   to size arithmetic overflow.  S must be positive and N must be
   nonnegative.  This is a macro, not an inline function, so that it
   works correctly even when SIZE_MAX < N.

   By gnulib convention, SIZE_MAX represents overflow in size
   calculations, so the conservative dividend to use here is
   SIZE_MAX - 1, since SIZE_MAX might represent an overflowed value.
   However, malloc (SIZE_MAX) fails on all known hosts where
   sizeof (ptrdiff_t) <= sizeof (size_t), so do not bother to test for
   exactly-SIZE_MAX allocations on such hosts; this avoids a test and
   branch when S is known to be 1.  */
# define xalloc_oversized(n, s) \
    ((size_t) (sizeof (ptrdiff_t) <= sizeof (size_t) ? -1 : -2) / (s) < (n))

/* Technically we should add an autoconf test for this, testing for the desired
   functionality, like what's done in gnulib, but for now, this is fine.  */
#if defined(__GLIBC__)
#define HAVE_GNU_CALLOC (__GLIBC__ >= 2)
#else
#define HAVE_GNU_CALLOC 0
#endif

/* Allocate zeroed memory for N elements of S bytes, with error
   checking.  S must be nonzero.  */
void *
guestfs___safe_calloc (guestfs_h *g, size_t n, size_t s)
{
  /* From gnulib's calloc function in xmalloc.c.  */
  void *p;
  /* Test for overflow, since some calloc implementations don't have
     proper overflow checks.  But omit overflow and size-zero tests if
     HAVE_GNU_CALLOC, since GNU calloc catches overflow and never
     returns NULL if successful.  */
  if ((! HAVE_GNU_CALLOC && xalloc_oversized (n, s))
      || (! (p = calloc (n, s)) && (HAVE_GNU_CALLOC || n != 0)))
    g->abort_cb ();
  return p;
}

void *
guestfs___safe_realloc (guestfs_h *g, void *ptr, size_t nbytes)
{
  void *p = realloc (ptr, nbytes);
  if (nbytes > 0 && !p) g->abort_cb ();
  return p;
}

char *
guestfs___safe_strdup (guestfs_h *g, const char *str)
{
  char *s = strdup (str);
  if (!s) g->abort_cb ();
  return s;
}

char *
guestfs___safe_strndup (guestfs_h *g, const char *str, size_t n)
{
  char *s = strndup (str, n);
  if (!s) g->abort_cb ();
  return s;
}

void *
guestfs___safe_memdup (guestfs_h *g, const void *ptr, size_t size)
{
  void *p = malloc (size);
  if (!p) g->abort_cb ();
  memcpy (p, ptr, size);
  return p;
}

char *
guestfs___safe_asprintf (guestfs_h *g, const char *fs, ...)
{
  va_list args;
  char *msg;

  va_start (args, fs);
  int err = vasprintf (&msg, fs, args);
  va_end (args);

  if (err == -1)
    g->abort_cb ();

  return msg;
}

/* These functions are used internally by the CLEANUP_* macros.
 * Don't call them directly.
 */

void
guestfs___cleanup_free (void *ptr)
{
  free (* (void **) ptr);
}

void
guestfs___cleanup_free_string_list (void *ptr)
{
  guestfs___free_string_list (* (char ***) ptr);
}

void
guestfs___cleanup_hash_free (void *ptr)
{
  Hash_table *h = * (Hash_table **) ptr;

  if (h)
    hash_free (h);
}

void
guestfs___cleanup_unlink_free (void *ptr)
{
  char *filename = * (char **) ptr;

  if (filename) {
    unlink (filename);
    free (filename);
  }
}

#ifdef HAVE_LIBXML2

#include <libxml/tree.h>
#include <libxml/xpath.h>
#include <libxml/xmlwriter.h>

void
guestfs___cleanup_xmlBufferFree (void *ptr)
{
  xmlBufferPtr xb = * (xmlBufferPtr *) ptr;

  if (xb)
    xmlBufferFree (xb);

}

void
guestfs___cleanup_xmlFreeDoc (void *ptr)
{
  xmlDocPtr doc = * (xmlDocPtr *) ptr;

  if (doc)
    xmlFreeDoc (doc);
}

void
guestfs___cleanup_xmlFreeTextWriter (void *ptr)
{
  xmlTextWriterPtr xo = * (xmlTextWriterPtr *) ptr;

  if (xo)
    xmlFreeTextWriter (xo);
}

void
guestfs___cleanup_xmlXPathFreeContext (void *ptr)
{
  xmlXPathContextPtr ctx = * (xmlXPathContextPtr *) ptr;

  if (ctx)
    xmlXPathFreeContext (ctx);
}

void
guestfs___cleanup_xmlXPathFreeObject (void *ptr)
{
  xmlXPathObjectPtr obj = * (xmlXPathObjectPtr *) ptr;

  if (obj)
    xmlXPathFreeObject (obj);
}

#endif /* HAVE_LIBXML2 */
