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

#ifndef PHP_GUESTFS_PHP_H
#define PHP_GUESTFS_PHP_H 1

#ifdef ZTS
#include "TSRM.h"
#endif

#define PHP_GUESTFS_PHP_EXTNAME "guestfs_php"
#define PHP_GUESTFS_PHP_VERSION "1.0"

PHP_MINIT_FUNCTION (guestfs_php);

#define PHP_GUESTFS_HANDLE_RES_NAME "guestfs_h"

PHP_FUNCTION (guestfs_create);
PHP_FUNCTION (guestfs_last_error);
PHP_FUNCTION (guestfs_acl_delete_def_file);
PHP_FUNCTION (guestfs_acl_get_file);
PHP_FUNCTION (guestfs_acl_set_file);
PHP_FUNCTION (guestfs_add_cdrom);
PHP_FUNCTION (guestfs_add_domain);
PHP_FUNCTION (guestfs_add_drive);
PHP_FUNCTION (guestfs_add_drive_ro);
PHP_FUNCTION (guestfs_add_drive_ro_with_if);
PHP_FUNCTION (guestfs_add_drive_with_if);
PHP_FUNCTION (guestfs_aug_clear);
PHP_FUNCTION (guestfs_aug_close);
PHP_FUNCTION (guestfs_aug_defnode);
PHP_FUNCTION (guestfs_aug_defvar);
PHP_FUNCTION (guestfs_aug_get);
PHP_FUNCTION (guestfs_aug_init);
PHP_FUNCTION (guestfs_aug_insert);
PHP_FUNCTION (guestfs_aug_load);
PHP_FUNCTION (guestfs_aug_ls);
PHP_FUNCTION (guestfs_aug_match);
PHP_FUNCTION (guestfs_aug_mv);
PHP_FUNCTION (guestfs_aug_rm);
PHP_FUNCTION (guestfs_aug_save);
PHP_FUNCTION (guestfs_aug_set);
PHP_FUNCTION (guestfs_available);
PHP_FUNCTION (guestfs_available_all_groups);
PHP_FUNCTION (guestfs_base64_in);
PHP_FUNCTION (guestfs_base64_out);
PHP_FUNCTION (guestfs_blkid);
PHP_FUNCTION (guestfs_blockdev_flushbufs);
PHP_FUNCTION (guestfs_blockdev_getbsz);
PHP_FUNCTION (guestfs_blockdev_getro);
PHP_FUNCTION (guestfs_blockdev_getsize64);
PHP_FUNCTION (guestfs_blockdev_getss);
PHP_FUNCTION (guestfs_blockdev_getsz);
PHP_FUNCTION (guestfs_blockdev_rereadpt);
PHP_FUNCTION (guestfs_blockdev_setbsz);
PHP_FUNCTION (guestfs_blockdev_setro);
PHP_FUNCTION (guestfs_blockdev_setrw);
PHP_FUNCTION (guestfs_btrfs_device_add);
PHP_FUNCTION (guestfs_btrfs_device_delete);
PHP_FUNCTION (guestfs_btrfs_filesystem_balance);
PHP_FUNCTION (guestfs_btrfs_filesystem_resize);
PHP_FUNCTION (guestfs_btrfs_filesystem_sync);
PHP_FUNCTION (guestfs_btrfs_fsck);
PHP_FUNCTION (guestfs_btrfs_set_seeding);
PHP_FUNCTION (guestfs_btrfs_subvolume_create);
PHP_FUNCTION (guestfs_btrfs_subvolume_delete);
PHP_FUNCTION (guestfs_btrfs_subvolume_list);
PHP_FUNCTION (guestfs_btrfs_subvolume_set_default);
PHP_FUNCTION (guestfs_btrfs_subvolume_snapshot);
PHP_FUNCTION (guestfs_canonical_device_name);
PHP_FUNCTION (guestfs_cap_get_file);
PHP_FUNCTION (guestfs_cap_set_file);
PHP_FUNCTION (guestfs_case_sensitive_path);
PHP_FUNCTION (guestfs_cat);
PHP_FUNCTION (guestfs_checksum);
PHP_FUNCTION (guestfs_checksum_device);
PHP_FUNCTION (guestfs_checksums_out);
PHP_FUNCTION (guestfs_chmod);
PHP_FUNCTION (guestfs_chown);
PHP_FUNCTION (guestfs_command);
PHP_FUNCTION (guestfs_command_lines);
PHP_FUNCTION (guestfs_compress_device_out);
PHP_FUNCTION (guestfs_compress_out);
PHP_FUNCTION (guestfs_config);
PHP_FUNCTION (guestfs_copy_device_to_device);
PHP_FUNCTION (guestfs_copy_device_to_file);
PHP_FUNCTION (guestfs_copy_file_to_device);
PHP_FUNCTION (guestfs_copy_file_to_file);
PHP_FUNCTION (guestfs_copy_size);
PHP_FUNCTION (guestfs_cp);
PHP_FUNCTION (guestfs_cp_a);
PHP_FUNCTION (guestfs_dd);
PHP_FUNCTION (guestfs_debug);
PHP_FUNCTION (guestfs_debug_drives);
PHP_FUNCTION (guestfs_debug_upload);
PHP_FUNCTION (guestfs_device_index);
PHP_FUNCTION (guestfs_df);
PHP_FUNCTION (guestfs_df_h);
PHP_FUNCTION (guestfs_disk_format);
PHP_FUNCTION (guestfs_disk_has_backing_file);
PHP_FUNCTION (guestfs_disk_virtual_size);
PHP_FUNCTION (guestfs_dmesg);
PHP_FUNCTION (guestfs_download);
PHP_FUNCTION (guestfs_download_offset);
PHP_FUNCTION (guestfs_drop_caches);
PHP_FUNCTION (guestfs_du);
PHP_FUNCTION (guestfs_e2fsck);
PHP_FUNCTION (guestfs_e2fsck_f);
PHP_FUNCTION (guestfs_echo_daemon);
PHP_FUNCTION (guestfs_egrep);
PHP_FUNCTION (guestfs_egrepi);
PHP_FUNCTION (guestfs_equal);
PHP_FUNCTION (guestfs_exists);
PHP_FUNCTION (guestfs_fallocate);
PHP_FUNCTION (guestfs_fallocate64);
PHP_FUNCTION (guestfs_fgrep);
PHP_FUNCTION (guestfs_fgrepi);
PHP_FUNCTION (guestfs_file);
PHP_FUNCTION (guestfs_file_architecture);
PHP_FUNCTION (guestfs_filesize);
PHP_FUNCTION (guestfs_filesystem_available);
PHP_FUNCTION (guestfs_fill);
PHP_FUNCTION (guestfs_fill_dir);
PHP_FUNCTION (guestfs_fill_pattern);
PHP_FUNCTION (guestfs_find);
PHP_FUNCTION (guestfs_find0);
PHP_FUNCTION (guestfs_findfs_label);
PHP_FUNCTION (guestfs_findfs_uuid);
PHP_FUNCTION (guestfs_fsck);
PHP_FUNCTION (guestfs_fstrim);
PHP_FUNCTION (guestfs_get_append);
PHP_FUNCTION (guestfs_get_attach_method);
PHP_FUNCTION (guestfs_get_autosync);
PHP_FUNCTION (guestfs_get_cachedir);
PHP_FUNCTION (guestfs_get_direct);
PHP_FUNCTION (guestfs_get_e2attrs);
PHP_FUNCTION (guestfs_get_e2generation);
PHP_FUNCTION (guestfs_get_e2label);
PHP_FUNCTION (guestfs_get_e2uuid);
PHP_FUNCTION (guestfs_get_libvirt_requested_credential_challenge);
PHP_FUNCTION (guestfs_get_libvirt_requested_credential_defresult);
PHP_FUNCTION (guestfs_get_libvirt_requested_credential_prompt);
PHP_FUNCTION (guestfs_get_libvirt_requested_credentials);
PHP_FUNCTION (guestfs_get_memsize);
PHP_FUNCTION (guestfs_get_network);
PHP_FUNCTION (guestfs_get_path);
PHP_FUNCTION (guestfs_get_pgroup);
PHP_FUNCTION (guestfs_get_pid);
PHP_FUNCTION (guestfs_get_qemu);
PHP_FUNCTION (guestfs_get_recovery_proc);
PHP_FUNCTION (guestfs_get_selinux);
PHP_FUNCTION (guestfs_get_smp);
PHP_FUNCTION (guestfs_get_state);
PHP_FUNCTION (guestfs_get_tmpdir);
PHP_FUNCTION (guestfs_get_trace);
PHP_FUNCTION (guestfs_get_umask);
PHP_FUNCTION (guestfs_get_verbose);
PHP_FUNCTION (guestfs_getcon);
PHP_FUNCTION (guestfs_getxattr);
PHP_FUNCTION (guestfs_getxattrs);
PHP_FUNCTION (guestfs_glob_expand);
PHP_FUNCTION (guestfs_grep);
PHP_FUNCTION (guestfs_grepi);
PHP_FUNCTION (guestfs_grub_install);
PHP_FUNCTION (guestfs_head);
PHP_FUNCTION (guestfs_head_n);
PHP_FUNCTION (guestfs_hexdump);
PHP_FUNCTION (guestfs_hivex_close);
PHP_FUNCTION (guestfs_hivex_commit);
PHP_FUNCTION (guestfs_hivex_node_add_child);
PHP_FUNCTION (guestfs_hivex_node_children);
PHP_FUNCTION (guestfs_hivex_node_delete_child);
PHP_FUNCTION (guestfs_hivex_node_get_child);
PHP_FUNCTION (guestfs_hivex_node_get_value);
PHP_FUNCTION (guestfs_hivex_node_name);
PHP_FUNCTION (guestfs_hivex_node_parent);
PHP_FUNCTION (guestfs_hivex_node_set_value);
PHP_FUNCTION (guestfs_hivex_node_values);
PHP_FUNCTION (guestfs_hivex_open);
PHP_FUNCTION (guestfs_hivex_root);
PHP_FUNCTION (guestfs_hivex_value_key);
PHP_FUNCTION (guestfs_hivex_value_type);
PHP_FUNCTION (guestfs_hivex_value_utf8);
PHP_FUNCTION (guestfs_hivex_value_value);
PHP_FUNCTION (guestfs_initrd_cat);
PHP_FUNCTION (guestfs_initrd_list);
PHP_FUNCTION (guestfs_inotify_add_watch);
PHP_FUNCTION (guestfs_inotify_close);
PHP_FUNCTION (guestfs_inotify_files);
PHP_FUNCTION (guestfs_inotify_init);
PHP_FUNCTION (guestfs_inotify_read);
PHP_FUNCTION (guestfs_inotify_rm_watch);
PHP_FUNCTION (guestfs_inspect_get_arch);
PHP_FUNCTION (guestfs_inspect_get_distro);
PHP_FUNCTION (guestfs_inspect_get_drive_mappings);
PHP_FUNCTION (guestfs_inspect_get_filesystems);
PHP_FUNCTION (guestfs_inspect_get_format);
PHP_FUNCTION (guestfs_inspect_get_hostname);
PHP_FUNCTION (guestfs_inspect_get_icon);
PHP_FUNCTION (guestfs_inspect_get_major_version);
PHP_FUNCTION (guestfs_inspect_get_minor_version);
PHP_FUNCTION (guestfs_inspect_get_mountpoints);
PHP_FUNCTION (guestfs_inspect_get_package_format);
PHP_FUNCTION (guestfs_inspect_get_package_management);
PHP_FUNCTION (guestfs_inspect_get_product_name);
PHP_FUNCTION (guestfs_inspect_get_product_variant);
PHP_FUNCTION (guestfs_inspect_get_roots);
PHP_FUNCTION (guestfs_inspect_get_type);
PHP_FUNCTION (guestfs_inspect_get_windows_current_control_set);
PHP_FUNCTION (guestfs_inspect_get_windows_systemroot);
PHP_FUNCTION (guestfs_inspect_is_live);
PHP_FUNCTION (guestfs_inspect_is_multipart);
PHP_FUNCTION (guestfs_inspect_is_netinst);
PHP_FUNCTION (guestfs_inspect_list_applications);
PHP_FUNCTION (guestfs_inspect_list_applications2);
PHP_FUNCTION (guestfs_inspect_os);
PHP_FUNCTION (guestfs_internal_autosync);
PHP_FUNCTION (guestfs_internal_hot_add_drive);
PHP_FUNCTION (guestfs_internal_hot_remove_drive);
PHP_FUNCTION (guestfs_internal_hot_remove_drive_precheck);
PHP_FUNCTION (guestfs_internal_lstatlist);
PHP_FUNCTION (guestfs_internal_lxattrlist);
PHP_FUNCTION (guestfs_internal_readlinklist);
PHP_FUNCTION (guestfs_internal_test);
PHP_FUNCTION (guestfs_internal_test_63_optargs);
PHP_FUNCTION (guestfs_internal_test_close_output);
PHP_FUNCTION (guestfs_internal_test_only_optargs);
PHP_FUNCTION (guestfs_internal_test_rbool);
PHP_FUNCTION (guestfs_internal_test_rboolerr);
PHP_FUNCTION (guestfs_internal_test_rbufferout);
PHP_FUNCTION (guestfs_internal_test_rbufferouterr);
PHP_FUNCTION (guestfs_internal_test_rconstoptstring);
PHP_FUNCTION (guestfs_internal_test_rconstoptstringerr);
PHP_FUNCTION (guestfs_internal_test_rconststring);
PHP_FUNCTION (guestfs_internal_test_rconststringerr);
PHP_FUNCTION (guestfs_internal_test_rhashtable);
PHP_FUNCTION (guestfs_internal_test_rhashtableerr);
PHP_FUNCTION (guestfs_internal_test_rint);
PHP_FUNCTION (guestfs_internal_test_rint64);
PHP_FUNCTION (guestfs_internal_test_rint64err);
PHP_FUNCTION (guestfs_internal_test_rinterr);
PHP_FUNCTION (guestfs_internal_test_rstring);
PHP_FUNCTION (guestfs_internal_test_rstringerr);
PHP_FUNCTION (guestfs_internal_test_rstringlist);
PHP_FUNCTION (guestfs_internal_test_rstringlisterr);
PHP_FUNCTION (guestfs_internal_test_rstruct);
PHP_FUNCTION (guestfs_internal_test_rstructerr);
PHP_FUNCTION (guestfs_internal_test_rstructlist);
PHP_FUNCTION (guestfs_internal_test_rstructlisterr);
PHP_FUNCTION (guestfs_internal_test_set_output);
PHP_FUNCTION (guestfs_internal_write);
PHP_FUNCTION (guestfs_internal_write_append);
PHP_FUNCTION (guestfs_is_blockdev);
PHP_FUNCTION (guestfs_is_busy);
PHP_FUNCTION (guestfs_is_chardev);
PHP_FUNCTION (guestfs_is_config);
PHP_FUNCTION (guestfs_is_dir);
PHP_FUNCTION (guestfs_is_fifo);
PHP_FUNCTION (guestfs_is_file);
PHP_FUNCTION (guestfs_is_launching);
PHP_FUNCTION (guestfs_is_lv);
PHP_FUNCTION (guestfs_is_ready);
PHP_FUNCTION (guestfs_is_socket);
PHP_FUNCTION (guestfs_is_symlink);
PHP_FUNCTION (guestfs_is_zero);
PHP_FUNCTION (guestfs_is_zero_device);
PHP_FUNCTION (guestfs_isoinfo);
PHP_FUNCTION (guestfs_isoinfo_device);
PHP_FUNCTION (guestfs_kill_subprocess);
PHP_FUNCTION (guestfs_launch);
PHP_FUNCTION (guestfs_lchown);
PHP_FUNCTION (guestfs_ldmtool_create_all);
PHP_FUNCTION (guestfs_ldmtool_diskgroup_disks);
PHP_FUNCTION (guestfs_ldmtool_diskgroup_name);
PHP_FUNCTION (guestfs_ldmtool_diskgroup_volumes);
PHP_FUNCTION (guestfs_ldmtool_remove_all);
PHP_FUNCTION (guestfs_ldmtool_scan);
PHP_FUNCTION (guestfs_ldmtool_scan_devices);
PHP_FUNCTION (guestfs_ldmtool_volume_hint);
PHP_FUNCTION (guestfs_ldmtool_volume_partitions);
PHP_FUNCTION (guestfs_ldmtool_volume_type);
PHP_FUNCTION (guestfs_lgetxattr);
PHP_FUNCTION (guestfs_lgetxattrs);
PHP_FUNCTION (guestfs_list_9p);
PHP_FUNCTION (guestfs_list_devices);
PHP_FUNCTION (guestfs_list_disk_labels);
PHP_FUNCTION (guestfs_list_dm_devices);
PHP_FUNCTION (guestfs_list_filesystems);
PHP_FUNCTION (guestfs_list_ldm_partitions);
PHP_FUNCTION (guestfs_list_ldm_volumes);
PHP_FUNCTION (guestfs_list_md_devices);
PHP_FUNCTION (guestfs_list_partitions);
PHP_FUNCTION (guestfs_ll);
PHP_FUNCTION (guestfs_llz);
PHP_FUNCTION (guestfs_ln);
PHP_FUNCTION (guestfs_ln_f);
PHP_FUNCTION (guestfs_ln_s);
PHP_FUNCTION (guestfs_ln_sf);
PHP_FUNCTION (guestfs_lremovexattr);
PHP_FUNCTION (guestfs_ls);
PHP_FUNCTION (guestfs_ls0);
PHP_FUNCTION (guestfs_lsetxattr);
PHP_FUNCTION (guestfs_lstat);
PHP_FUNCTION (guestfs_lstatlist);
PHP_FUNCTION (guestfs_luks_add_key);
PHP_FUNCTION (guestfs_luks_close);
PHP_FUNCTION (guestfs_luks_format);
PHP_FUNCTION (guestfs_luks_format_cipher);
PHP_FUNCTION (guestfs_luks_kill_slot);
PHP_FUNCTION (guestfs_luks_open);
PHP_FUNCTION (guestfs_luks_open_ro);
PHP_FUNCTION (guestfs_lvcreate);
PHP_FUNCTION (guestfs_lvcreate_free);
PHP_FUNCTION (guestfs_lvm_canonical_lv_name);
PHP_FUNCTION (guestfs_lvm_clear_filter);
PHP_FUNCTION (guestfs_lvm_remove_all);
PHP_FUNCTION (guestfs_lvm_set_filter);
PHP_FUNCTION (guestfs_lvremove);
PHP_FUNCTION (guestfs_lvrename);
PHP_FUNCTION (guestfs_lvresize);
PHP_FUNCTION (guestfs_lvresize_free);
PHP_FUNCTION (guestfs_lvs);
PHP_FUNCTION (guestfs_lvs_full);
PHP_FUNCTION (guestfs_lvuuid);
PHP_FUNCTION (guestfs_lxattrlist);
PHP_FUNCTION (guestfs_max_disks);
PHP_FUNCTION (guestfs_md_create);
PHP_FUNCTION (guestfs_md_detail);
PHP_FUNCTION (guestfs_md_stat);
PHP_FUNCTION (guestfs_md_stop);
PHP_FUNCTION (guestfs_mkdir);
PHP_FUNCTION (guestfs_mkdir_mode);
PHP_FUNCTION (guestfs_mkdir_p);
PHP_FUNCTION (guestfs_mkdtemp);
PHP_FUNCTION (guestfs_mke2fs);
PHP_FUNCTION (guestfs_mke2fs_J);
PHP_FUNCTION (guestfs_mke2fs_JL);
PHP_FUNCTION (guestfs_mke2fs_JU);
PHP_FUNCTION (guestfs_mke2journal);
PHP_FUNCTION (guestfs_mke2journal_L);
PHP_FUNCTION (guestfs_mke2journal_U);
PHP_FUNCTION (guestfs_mkfifo);
PHP_FUNCTION (guestfs_mkfs);
PHP_FUNCTION (guestfs_mkfs_b);
PHP_FUNCTION (guestfs_mkfs_btrfs);
PHP_FUNCTION (guestfs_mklost_and_found);
PHP_FUNCTION (guestfs_mkmountpoint);
PHP_FUNCTION (guestfs_mknod);
PHP_FUNCTION (guestfs_mknod_b);
PHP_FUNCTION (guestfs_mknod_c);
PHP_FUNCTION (guestfs_mkswap);
PHP_FUNCTION (guestfs_mkswap_L);
PHP_FUNCTION (guestfs_mkswap_U);
PHP_FUNCTION (guestfs_mkswap_file);
PHP_FUNCTION (guestfs_mktemp);
PHP_FUNCTION (guestfs_modprobe);
PHP_FUNCTION (guestfs_mount);
PHP_FUNCTION (guestfs_mount_9p);
PHP_FUNCTION (guestfs_mount_local);
PHP_FUNCTION (guestfs_mount_local_run);
PHP_FUNCTION (guestfs_mount_loop);
PHP_FUNCTION (guestfs_mount_options);
PHP_FUNCTION (guestfs_mount_ro);
PHP_FUNCTION (guestfs_mount_vfs);
PHP_FUNCTION (guestfs_mountpoints);
PHP_FUNCTION (guestfs_mounts);
PHP_FUNCTION (guestfs_mv);
PHP_FUNCTION (guestfs_nr_devices);
PHP_FUNCTION (guestfs_ntfs_3g_probe);
PHP_FUNCTION (guestfs_ntfsclone_in);
PHP_FUNCTION (guestfs_ntfsclone_out);
PHP_FUNCTION (guestfs_ntfsfix);
PHP_FUNCTION (guestfs_ntfsresize);
PHP_FUNCTION (guestfs_ntfsresize_size);
PHP_FUNCTION (guestfs_parse_environment);
PHP_FUNCTION (guestfs_parse_environment_list);
PHP_FUNCTION (guestfs_part_add);
PHP_FUNCTION (guestfs_part_del);
PHP_FUNCTION (guestfs_part_disk);
PHP_FUNCTION (guestfs_part_get_bootable);
PHP_FUNCTION (guestfs_part_get_gpt_type);
PHP_FUNCTION (guestfs_part_get_mbr_id);
PHP_FUNCTION (guestfs_part_get_parttype);
PHP_FUNCTION (guestfs_part_init);
PHP_FUNCTION (guestfs_part_list);
PHP_FUNCTION (guestfs_part_set_bootable);
PHP_FUNCTION (guestfs_part_set_gpt_type);
PHP_FUNCTION (guestfs_part_set_mbr_id);
PHP_FUNCTION (guestfs_part_set_name);
PHP_FUNCTION (guestfs_part_to_dev);
PHP_FUNCTION (guestfs_part_to_partnum);
PHP_FUNCTION (guestfs_ping_daemon);
PHP_FUNCTION (guestfs_pread);
PHP_FUNCTION (guestfs_pread_device);
PHP_FUNCTION (guestfs_pvchange_uuid);
PHP_FUNCTION (guestfs_pvchange_uuid_all);
PHP_FUNCTION (guestfs_pvcreate);
PHP_FUNCTION (guestfs_pvremove);
PHP_FUNCTION (guestfs_pvresize);
PHP_FUNCTION (guestfs_pvresize_size);
PHP_FUNCTION (guestfs_pvs);
PHP_FUNCTION (guestfs_pvs_full);
PHP_FUNCTION (guestfs_pvuuid);
PHP_FUNCTION (guestfs_pwrite);
PHP_FUNCTION (guestfs_pwrite_device);
PHP_FUNCTION (guestfs_read_file);
PHP_FUNCTION (guestfs_read_lines);
PHP_FUNCTION (guestfs_readdir);
PHP_FUNCTION (guestfs_readlink);
PHP_FUNCTION (guestfs_readlinklist);
PHP_FUNCTION (guestfs_realpath);
PHP_FUNCTION (guestfs_remove_drive);
PHP_FUNCTION (guestfs_removexattr);
PHP_FUNCTION (guestfs_rename);
PHP_FUNCTION (guestfs_resize2fs);
PHP_FUNCTION (guestfs_resize2fs_M);
PHP_FUNCTION (guestfs_resize2fs_size);
PHP_FUNCTION (guestfs_rm);
PHP_FUNCTION (guestfs_rm_f);
PHP_FUNCTION (guestfs_rm_rf);
PHP_FUNCTION (guestfs_rmdir);
PHP_FUNCTION (guestfs_rmmountpoint);
PHP_FUNCTION (guestfs_rsync);
PHP_FUNCTION (guestfs_rsync_in);
PHP_FUNCTION (guestfs_rsync_out);
PHP_FUNCTION (guestfs_scrub_device);
PHP_FUNCTION (guestfs_scrub_file);
PHP_FUNCTION (guestfs_scrub_freespace);
PHP_FUNCTION (guestfs_set_append);
PHP_FUNCTION (guestfs_set_attach_method);
PHP_FUNCTION (guestfs_set_autosync);
PHP_FUNCTION (guestfs_set_cachedir);
PHP_FUNCTION (guestfs_set_direct);
PHP_FUNCTION (guestfs_set_e2attrs);
PHP_FUNCTION (guestfs_set_e2generation);
PHP_FUNCTION (guestfs_set_e2label);
PHP_FUNCTION (guestfs_set_e2uuid);
PHP_FUNCTION (guestfs_set_label);
PHP_FUNCTION (guestfs_set_libvirt_requested_credential);
PHP_FUNCTION (guestfs_set_libvirt_supported_credentials);
PHP_FUNCTION (guestfs_set_memsize);
PHP_FUNCTION (guestfs_set_network);
PHP_FUNCTION (guestfs_set_path);
PHP_FUNCTION (guestfs_set_pgroup);
PHP_FUNCTION (guestfs_set_qemu);
PHP_FUNCTION (guestfs_set_recovery_proc);
PHP_FUNCTION (guestfs_set_selinux);
PHP_FUNCTION (guestfs_set_smp);
PHP_FUNCTION (guestfs_set_tmpdir);
PHP_FUNCTION (guestfs_set_trace);
PHP_FUNCTION (guestfs_set_verbose);
PHP_FUNCTION (guestfs_setcon);
PHP_FUNCTION (guestfs_setxattr);
PHP_FUNCTION (guestfs_sfdisk);
PHP_FUNCTION (guestfs_sfdiskM);
PHP_FUNCTION (guestfs_sfdisk_N);
PHP_FUNCTION (guestfs_sfdisk_disk_geometry);
PHP_FUNCTION (guestfs_sfdisk_kernel_geometry);
PHP_FUNCTION (guestfs_sfdisk_l);
PHP_FUNCTION (guestfs_sh);
PHP_FUNCTION (guestfs_sh_lines);
PHP_FUNCTION (guestfs_shutdown);
PHP_FUNCTION (guestfs_sleep);
PHP_FUNCTION (guestfs_stat);
PHP_FUNCTION (guestfs_statvfs);
PHP_FUNCTION (guestfs_strings);
PHP_FUNCTION (guestfs_strings_e);
PHP_FUNCTION (guestfs_swapoff_device);
PHP_FUNCTION (guestfs_swapoff_file);
PHP_FUNCTION (guestfs_swapoff_label);
PHP_FUNCTION (guestfs_swapoff_uuid);
PHP_FUNCTION (guestfs_swapon_device);
PHP_FUNCTION (guestfs_swapon_file);
PHP_FUNCTION (guestfs_swapon_label);
PHP_FUNCTION (guestfs_swapon_uuid);
PHP_FUNCTION (guestfs_sync);
PHP_FUNCTION (guestfs_tail);
PHP_FUNCTION (guestfs_tail_n);
PHP_FUNCTION (guestfs_tar_in);
PHP_FUNCTION (guestfs_tar_out);
PHP_FUNCTION (guestfs_tgz_in);
PHP_FUNCTION (guestfs_tgz_out);
PHP_FUNCTION (guestfs_touch);
PHP_FUNCTION (guestfs_truncate);
PHP_FUNCTION (guestfs_truncate_size);
PHP_FUNCTION (guestfs_tune2fs);
PHP_FUNCTION (guestfs_tune2fs_l);
PHP_FUNCTION (guestfs_txz_in);
PHP_FUNCTION (guestfs_txz_out);
PHP_FUNCTION (guestfs_umask);
PHP_FUNCTION (guestfs_umount);
PHP_FUNCTION (guestfs_umount_all);
PHP_FUNCTION (guestfs_umount_local);
PHP_FUNCTION (guestfs_upload);
PHP_FUNCTION (guestfs_upload_offset);
PHP_FUNCTION (guestfs_utimens);
PHP_FUNCTION (guestfs_utsname);
PHP_FUNCTION (guestfs_version);
PHP_FUNCTION (guestfs_vfs_label);
PHP_FUNCTION (guestfs_vfs_type);
PHP_FUNCTION (guestfs_vfs_uuid);
PHP_FUNCTION (guestfs_vg_activate);
PHP_FUNCTION (guestfs_vg_activate_all);
PHP_FUNCTION (guestfs_vgchange_uuid);
PHP_FUNCTION (guestfs_vgchange_uuid_all);
PHP_FUNCTION (guestfs_vgcreate);
PHP_FUNCTION (guestfs_vglvuuids);
PHP_FUNCTION (guestfs_vgmeta);
PHP_FUNCTION (guestfs_vgpvuuids);
PHP_FUNCTION (guestfs_vgremove);
PHP_FUNCTION (guestfs_vgrename);
PHP_FUNCTION (guestfs_vgs);
PHP_FUNCTION (guestfs_vgs_full);
PHP_FUNCTION (guestfs_vgscan);
PHP_FUNCTION (guestfs_vguuid);
PHP_FUNCTION (guestfs_wait_ready);
PHP_FUNCTION (guestfs_wc_c);
PHP_FUNCTION (guestfs_wc_l);
PHP_FUNCTION (guestfs_wc_w);
PHP_FUNCTION (guestfs_wipefs);
PHP_FUNCTION (guestfs_write);
PHP_FUNCTION (guestfs_write_append);
PHP_FUNCTION (guestfs_write_file);
PHP_FUNCTION (guestfs_xfs_admin);
PHP_FUNCTION (guestfs_xfs_growfs);
PHP_FUNCTION (guestfs_xfs_info);
PHP_FUNCTION (guestfs_xfs_repair);
PHP_FUNCTION (guestfs_zegrep);
PHP_FUNCTION (guestfs_zegrepi);
PHP_FUNCTION (guestfs_zero);
PHP_FUNCTION (guestfs_zero_device);
PHP_FUNCTION (guestfs_zero_free_space);
PHP_FUNCTION (guestfs_zerofree);
PHP_FUNCTION (guestfs_zfgrep);
PHP_FUNCTION (guestfs_zfgrepi);
PHP_FUNCTION (guestfs_zfile);
PHP_FUNCTION (guestfs_zgrep);
PHP_FUNCTION (guestfs_zgrepi);

extern zend_module_entry guestfs_php_module_entry;
#define phpext_guestfs_php_ptr &guestfs_php_module_entry

#endif /* PHP_GUESTFS_PHP_H */
