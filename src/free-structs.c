/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/ *.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
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

#include "guestfs.h"
#include "guestfs-internal.h"
#include "guestfs_protocol.h"

/* Structure-freeing functions.  These rely on the fact that the
 * structure format is identical to the XDR format.  See note in
 * generator.ml.
 */

GUESTFS_DLL_PUBLIC void
guestfs_free_int_bool (struct guestfs_int_bool *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_int_bool, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_int_bool_list (struct guestfs_int_bool_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_int_bool_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_pv (struct guestfs_lvm_pv *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_pv, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_pv_list (struct guestfs_lvm_pv_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_pv_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_vg (struct guestfs_lvm_vg *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_vg, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_vg_list (struct guestfs_lvm_vg_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_vg_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_lv (struct guestfs_lvm_lv *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_lv, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_lvm_lv_list (struct guestfs_lvm_lv_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_lvm_lv_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_stat (struct guestfs_stat *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_stat, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_stat_list (struct guestfs_stat_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_stat_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_statvfs (struct guestfs_statvfs *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_statvfs, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_statvfs_list (struct guestfs_statvfs_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_statvfs_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_dirent (struct guestfs_dirent *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_dirent, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_dirent_list (struct guestfs_dirent_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_dirent_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_version (struct guestfs_version *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_version, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_version_list (struct guestfs_version_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_version_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_xattr (struct guestfs_xattr *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_xattr, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_xattr_list (struct guestfs_xattr_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_xattr_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_inotify_event (struct guestfs_inotify_event *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_inotify_event, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_inotify_event_list (struct guestfs_inotify_event_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_inotify_event_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_partition (struct guestfs_partition *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_partition, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_partition_list (struct guestfs_partition_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_partition_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_application (struct guestfs_application *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_application, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_application_list (struct guestfs_application_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_application_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_application2 (struct guestfs_application2 *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_application2, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_application2_list (struct guestfs_application2_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_application2_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_isoinfo (struct guestfs_isoinfo *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_isoinfo, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_isoinfo_list (struct guestfs_isoinfo_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_isoinfo_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_mdstat (struct guestfs_mdstat *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_mdstat, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_mdstat_list (struct guestfs_mdstat_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_mdstat_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_btrfssubvolume (struct guestfs_btrfssubvolume *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfssubvolume, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_btrfssubvolume_list (struct guestfs_btrfssubvolume_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_btrfssubvolume_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_xfsinfo (struct guestfs_xfsinfo *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_xfsinfo, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_xfsinfo_list (struct guestfs_xfsinfo_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_xfsinfo_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_utsname (struct guestfs_utsname *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_utsname, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_utsname_list (struct guestfs_utsname_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_utsname_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_hivex_node (struct guestfs_hivex_node *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_hivex_node, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_hivex_node_list (struct guestfs_hivex_node_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_hivex_node_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_hivex_value (struct guestfs_hivex_value *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_hivex_value, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_hivex_value_list (struct guestfs_hivex_value_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_hivex_value_list, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_internal_mountable (struct guestfs_internal_mountable *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_internal_mountable, (char *) x);
    free (x);
  }
}

GUESTFS_DLL_PUBLIC void
guestfs_free_internal_mountable_list (struct guestfs_internal_mountable_list *x)
{
  if (x) {
    xdr_free ((xdrproc_t) xdr_guestfs_int_internal_mountable_list, (char *) x);
    free (x);
  }
}

/* Cleanup functions used by CLEANUP_* macros. */

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_int_bool (void *ptr)
{
  guestfs_free_int_bool (* (struct guestfs_int_bool **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_int_bool_list (void *ptr)
{
  guestfs_free_int_bool_list (* (struct guestfs_int_bool_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_lvm_pv (void *ptr)
{
  guestfs_free_lvm_pv (* (struct guestfs_lvm_pv **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_lvm_pv_list (void *ptr)
{
  guestfs_free_lvm_pv_list (* (struct guestfs_lvm_pv_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_lvm_vg (void *ptr)
{
  guestfs_free_lvm_vg (* (struct guestfs_lvm_vg **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_lvm_vg_list (void *ptr)
{
  guestfs_free_lvm_vg_list (* (struct guestfs_lvm_vg_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_lvm_lv (void *ptr)
{
  guestfs_free_lvm_lv (* (struct guestfs_lvm_lv **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_lvm_lv_list (void *ptr)
{
  guestfs_free_lvm_lv_list (* (struct guestfs_lvm_lv_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_stat (void *ptr)
{
  guestfs_free_stat (* (struct guestfs_stat **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_stat_list (void *ptr)
{
  guestfs_free_stat_list (* (struct guestfs_stat_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_statvfs (void *ptr)
{
  guestfs_free_statvfs (* (struct guestfs_statvfs **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_statvfs_list (void *ptr)
{
  guestfs_free_statvfs_list (* (struct guestfs_statvfs_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_dirent (void *ptr)
{
  guestfs_free_dirent (* (struct guestfs_dirent **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_dirent_list (void *ptr)
{
  guestfs_free_dirent_list (* (struct guestfs_dirent_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_version (void *ptr)
{
  guestfs_free_version (* (struct guestfs_version **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_version_list (void *ptr)
{
  guestfs_free_version_list (* (struct guestfs_version_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_xattr (void *ptr)
{
  guestfs_free_xattr (* (struct guestfs_xattr **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_xattr_list (void *ptr)
{
  guestfs_free_xattr_list (* (struct guestfs_xattr_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_inotify_event (void *ptr)
{
  guestfs_free_inotify_event (* (struct guestfs_inotify_event **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_inotify_event_list (void *ptr)
{
  guestfs_free_inotify_event_list (* (struct guestfs_inotify_event_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_partition (void *ptr)
{
  guestfs_free_partition (* (struct guestfs_partition **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_partition_list (void *ptr)
{
  guestfs_free_partition_list (* (struct guestfs_partition_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_application (void *ptr)
{
  guestfs_free_application (* (struct guestfs_application **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_application_list (void *ptr)
{
  guestfs_free_application_list (* (struct guestfs_application_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_application2 (void *ptr)
{
  guestfs_free_application2 (* (struct guestfs_application2 **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_application2_list (void *ptr)
{
  guestfs_free_application2_list (* (struct guestfs_application2_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_isoinfo (void *ptr)
{
  guestfs_free_isoinfo (* (struct guestfs_isoinfo **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_isoinfo_list (void *ptr)
{
  guestfs_free_isoinfo_list (* (struct guestfs_isoinfo_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_mdstat (void *ptr)
{
  guestfs_free_mdstat (* (struct guestfs_mdstat **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_mdstat_list (void *ptr)
{
  guestfs_free_mdstat_list (* (struct guestfs_mdstat_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_btrfssubvolume (void *ptr)
{
  guestfs_free_btrfssubvolume (* (struct guestfs_btrfssubvolume **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_btrfssubvolume_list (void *ptr)
{
  guestfs_free_btrfssubvolume_list (* (struct guestfs_btrfssubvolume_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_xfsinfo (void *ptr)
{
  guestfs_free_xfsinfo (* (struct guestfs_xfsinfo **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_xfsinfo_list (void *ptr)
{
  guestfs_free_xfsinfo_list (* (struct guestfs_xfsinfo_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_utsname (void *ptr)
{
  guestfs_free_utsname (* (struct guestfs_utsname **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_utsname_list (void *ptr)
{
  guestfs_free_utsname_list (* (struct guestfs_utsname_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_hivex_node (void *ptr)
{
  guestfs_free_hivex_node (* (struct guestfs_hivex_node **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_hivex_node_list (void *ptr)
{
  guestfs_free_hivex_node_list (* (struct guestfs_hivex_node_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_hivex_value (void *ptr)
{
  guestfs_free_hivex_value (* (struct guestfs_hivex_value **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_hivex_value_list (void *ptr)
{
  guestfs_free_hivex_value_list (* (struct guestfs_hivex_value_list **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_internal_mountable (void *ptr)
{
  guestfs_free_internal_mountable (* (struct guestfs_internal_mountable **) ptr);
}

GUESTFS_DLL_PUBLIC void
guestfs___cleanup_free_internal_mountable_list (void *ptr)
{
  guestfs_free_internal_mountable_list (* (struct guestfs_internal_mountable_list **) ptr);
}

