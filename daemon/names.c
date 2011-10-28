/* libguestfs generated file
 * WARNING: THIS FILE IS GENERATED FROM:
 *   generator/generator_*.ml
 * ANY CHANGES YOU MAKE TO THIS FILE WILL BE LOST.
 *
 * Copyright (C) 2009-2011 Red Hat Inc.
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
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <config.h>

#include "daemon.h"

/* This array is indexed by proc_nr.  See guestfs_protocol.x. */
const char *function_names[] = {
  [1] = "mount",
  [2] = "sync",
  [3] = "touch",
  [4] = "cat",
  [5] = "ll",
  [6] = "ls",
  [7] = "list_devices",
  [8] = "list_partitions",
  [9] = "pvs",
  [10] = "vgs",
  [11] = "lvs",
  [12] = "pvs_full",
  [13] = "vgs_full",
  [14] = "lvs_full",
  [15] = "read_lines",
  [16] = "aug_init",
  [26] = "aug_close",
  [17] = "aug_defvar",
  [18] = "aug_defnode",
  [19] = "aug_get",
  [20] = "aug_set",
  [21] = "aug_insert",
  [22] = "aug_rm",
  [23] = "aug_mv",
  [24] = "aug_match",
  [25] = "aug_save",
  [27] = "aug_load",
  [28] = "aug_ls",
  [29] = "rm",
  [30] = "rmdir",
  [31] = "rm_rf",
  [32] = "mkdir",
  [33] = "mkdir_p",
  [34] = "chmod",
  [35] = "chown",
  [36] = "exists",
  [37] = "is_file",
  [38] = "is_dir",
  [39] = "pvcreate",
  [40] = "vgcreate",
  [41] = "lvcreate",
  [42] = "mkfs",
  [43] = "sfdisk",
  [44] = "write_file",
  [45] = "umount",
  [46] = "mounts",
  [47] = "umount_all",
  [48] = "lvm_remove_all",
  [49] = "file",
  [50] = "command",
  [51] = "command_lines",
  [52] = "stat",
  [53] = "lstat",
  [54] = "statvfs",
  [55] = "tune2fs_l",
  [56] = "blockdev_setro",
  [57] = "blockdev_setrw",
  [58] = "blockdev_getro",
  [59] = "blockdev_getss",
  [60] = "blockdev_getbsz",
  [61] = "blockdev_setbsz",
  [62] = "blockdev_getsz",
  [63] = "blockdev_getsize64",
  [64] = "blockdev_flushbufs",
  [65] = "blockdev_rereadpt",
  [66] = "upload",
  [67] = "download",
  [68] = "checksum",
  [69] = "tar_in",
  [70] = "tar_out",
  [71] = "tgz_in",
  [72] = "tgz_out",
  [73] = "mount_ro",
  [74] = "mount_options",
  [75] = "mount_vfs",
  [76] = "debug",
  [77] = "lvremove",
  [78] = "vgremove",
  [79] = "pvremove",
  [80] = "set_e2label",
  [81] = "get_e2label",
  [82] = "set_e2uuid",
  [83] = "get_e2uuid",
  [84] = "fsck",
  [85] = "zero",
  [86] = "grub_install",
  [87] = "cp",
  [88] = "cp_a",
  [89] = "mv",
  [90] = "drop_caches",
  [91] = "dmesg",
  [92] = "ping_daemon",
  [93] = "equal",
  [94] = "strings",
  [95] = "strings_e",
  [96] = "hexdump",
  [97] = "zerofree",
  [98] = "pvresize",
  [99] = "sfdisk_N",
  [100] = "sfdisk_l",
  [101] = "sfdisk_kernel_geometry",
  [102] = "sfdisk_disk_geometry",
  [103] = "vg_activate_all",
  [104] = "vg_activate",
  [105] = "lvresize",
  [106] = "resize2fs",
  [107] = "find",
  [108] = "e2fsck_f",
  [109] = "sleep",
  [110] = "ntfs_3g_probe",
  [111] = "sh",
  [112] = "sh_lines",
  [113] = "glob_expand",
  [114] = "scrub_device",
  [115] = "scrub_file",
  [116] = "scrub_freespace",
  [117] = "mkdtemp",
  [118] = "wc_l",
  [119] = "wc_w",
  [120] = "wc_c",
  [121] = "head",
  [122] = "head_n",
  [123] = "tail",
  [124] = "tail_n",
  [125] = "df",
  [126] = "df_h",
  [127] = "du",
  [128] = "initrd_list",
  [129] = "mount_loop",
  [130] = "mkswap",
  [131] = "mkswap_L",
  [132] = "mkswap_U",
  [133] = "mknod",
  [134] = "mkfifo",
  [135] = "mknod_b",
  [136] = "mknod_c",
  [137] = "umask",
  [138] = "readdir",
  [139] = "sfdiskM",
  [140] = "zfile",
  [141] = "getxattrs",
  [142] = "lgetxattrs",
  [143] = "setxattr",
  [144] = "lsetxattr",
  [145] = "removexattr",
  [146] = "lremovexattr",
  [147] = "mountpoints",
  [148] = "mkmountpoint",
  [149] = "rmmountpoint",
  [150] = "read_file",
  [151] = "grep",
  [152] = "egrep",
  [153] = "fgrep",
  [154] = "grepi",
  [155] = "egrepi",
  [156] = "fgrepi",
  [157] = "zgrep",
  [158] = "zegrep",
  [159] = "zfgrep",
  [160] = "zgrepi",
  [161] = "zegrepi",
  [162] = "zfgrepi",
  [163] = "realpath",
  [164] = "ln",
  [165] = "ln_f",
  [166] = "ln_s",
  [167] = "ln_sf",
  [168] = "readlink",
  [169] = "fallocate",
  [170] = "swapon_device",
  [171] = "swapoff_device",
  [172] = "swapon_file",
  [173] = "swapoff_file",
  [174] = "swapon_label",
  [175] = "swapoff_label",
  [176] = "swapon_uuid",
  [177] = "swapoff_uuid",
  [178] = "mkswap_file",
  [179] = "inotify_init",
  [180] = "inotify_add_watch",
  [181] = "inotify_rm_watch",
  [182] = "inotify_read",
  [183] = "inotify_files",
  [184] = "inotify_close",
  [185] = "setcon",
  [186] = "getcon",
  [187] = "mkfs_b",
  [188] = "mke2journal",
  [189] = "mke2journal_L",
  [190] = "mke2journal_U",
  [191] = "mke2fs_J",
  [192] = "mke2fs_JL",
  [193] = "mke2fs_JU",
  [194] = "modprobe",
  [195] = "echo_daemon",
  [196] = "find0",
  [197] = "case_sensitive_path",
  [198] = "vfs_type",
  [199] = "truncate",
  [200] = "truncate_size",
  [201] = "utimens",
  [202] = "mkdir_mode",
  [203] = "lchown",
  [204] = "lstatlist",
  [205] = "lxattrlist",
  [206] = "readlinklist",
  [207] = "pread",
  [208] = "part_init",
  [209] = "part_add",
  [210] = "part_disk",
  [211] = "part_set_bootable",
  [212] = "part_set_name",
  [213] = "part_list",
  [214] = "part_get_parttype",
  [215] = "fill",
  [216] = "available",
  [217] = "dd",
  [218] = "filesize",
  [219] = "lvrename",
  [220] = "vgrename",
  [221] = "initrd_cat",
  [222] = "pvuuid",
  [223] = "vguuid",
  [224] = "lvuuid",
  [225] = "vgpvuuids",
  [226] = "vglvuuids",
  [227] = "copy_size",
  [228] = "zero_device",
  [229] = "txz_in",
  [230] = "txz_out",
  [231] = "ntfsresize",
  [232] = "vgscan",
  [233] = "part_del",
  [234] = "part_get_bootable",
  [235] = "part_get_mbr_id",
  [236] = "part_set_mbr_id",
  [237] = "checksum_device",
  [238] = "lvresize_free",
  [239] = "aug_clear",
  [240] = "get_umask",
  [241] = "debug_upload",
  [242] = "base64_in",
  [243] = "base64_out",
  [244] = "checksums_out",
  [245] = "fill_pattern",
  [246] = "write",
  [247] = "pwrite",
  [248] = "resize2fs_size",
  [249] = "pvresize_size",
  [250] = "ntfsresize_size",
  [251] = "available_all_groups",
  [252] = "fallocate64",
  [253] = "vfs_label",
  [254] = "vfs_uuid",
  [255] = "lvm_set_filter",
  [256] = "lvm_clear_filter",
  [257] = "luks_open",
  [258] = "luks_open_ro",
  [259] = "luks_close",
  [260] = "luks_format",
  [261] = "luks_format_cipher",
  [262] = "luks_add_key",
  [263] = "luks_kill_slot",
  [264] = "is_lv",
  [265] = "findfs_uuid",
  [266] = "findfs_label",
  [267] = "is_chardev",
  [268] = "is_blockdev",
  [269] = "is_fifo",
  [270] = "is_symlink",
  [271] = "is_socket",
  [272] = "part_to_dev",
  [273] = "upload_offset",
  [274] = "download_offset",
  [275] = "pwrite_device",
  [276] = "pread_device",
  [277] = "lvm_canonical_lv_name",
  [278] = "mkfs_opts",
  [279] = "getxattr",
  [280] = "lgetxattr",
  [281] = "resize2fs_M",
  [282] = "internal_autosync",
  [283] = "is_zero",
  [284] = "is_zero_device",
  [285] = "list_9p",
  [286] = "mount_9p",
  [287] = "list_dm_devices",
  [288] = "ntfsresize_opts",
  [289] = "btrfs_filesystem_resize",
  [290] = "write_append",
  [291] = "compress_out",
  [292] = "compress_device_out",
  [293] = "part_to_partnum",
  [294] = "copy_device_to_device",
  [295] = "copy_device_to_file",
  [296] = "copy_file_to_device",
  [297] = "copy_file_to_file",
};
