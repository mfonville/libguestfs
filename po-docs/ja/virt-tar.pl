
=head1 名前

virt-tar - Extract or upload files to a virtual machine

=head1 SYNOPSIS

 virt-tar [--options] -x domname directory tarball

 virt-tar [--options] -u domname tarball directory

 virt-tar [--options] disk.img [disk.img ...] -x directory tarball

 virt-tar [--options] disk.img [disk.img ...] -u tarball directory

=head1 NOTE

This tool is obsolete.  Use L<virt-copy-in(1)>, L<virt-copy-out(1)>,
L<virt-tar-in(1)>, L<virt-tar-out(1)> as replacements.

=head1 EXAMPLES

Download C</home> from the VM into a local tarball:

 virt-tar -x domname /home home.tar

 virt-tar -zx domname /home home.tar.gz

Upload a local tarball and unpack it inside C</tmp> in the VM:

 virt-tar -u domname uploadstuff.tar /tmp

 virt-tar -zu domname uploadstuff.tar.gz /tmp

=head1 WARNING

You must I<not> use C<virt-tar> with the I<-u> option (upload) on live
virtual machines.  If you do this, you risk disk corruption in the VM.
C<virt-tar> tries to stop you from doing this, but doesn't catch all cases.

You can use I<-x> (extract) on live virtual machines, but you might get
inconsistent results or errors if there is filesystem activity inside the
VM.  If the live VM is synched and quiescent, then C<virt-tar> will usually
work, but the only way to guarantee consistent results is if the virtual
machine is shut down.

=head1 DESCRIPTION

C<virt-tar> is a general purpose archive tool for downloading and uploading
parts of a guest filesystem.  There are many possibilities: making backups,
uploading data files, snooping on guest activity, fixing or customizing
guests, etc.

If you want to just view a single file, use L<virt-cat(1)>.  If you just
want to edit a single file, use L<virt-edit(1)>.  For more complex cases you
should look at the L<guestfish(1)> tool.

There are two modes of operation: I<-x> (eXtract) downloads a directory and
its contents (recursively) from the virtual machine into a local tarball.
I<-u> uploads from a local tarball, unpacking it into a directory inside the
virtual machine.  You cannot use these two options together.

In addition, you may need to use the I<-z> (gZip) option to enable
compression.  When uploading, you have to specify I<-z> if the upload file
is compressed because virt-tar won't detect this on its own.

C<virt-tar> can only handle tar (optionally gzipped) format tarballs.  For
example it cannot do PKZip files or bzip2 compression.  If you want that
then you'll have to rebuild the tarballs yourself.  (This is a limitation of
the L<libguestfs(3)> API).

=head1 OPTIONS

=over 4

=item B<--help>

Display brief help.

=item B<--version>

Display version number and exit.

=item B<--connect URI> | B<-c URI>

If using libvirt, connect to the given I<URI>.  If omitted, then we connect
to the default libvirt hypervisor.

If you specify guest block devices directly, then libvirt is not used at
all.

=item B<--format> raw

Specify the format of disk images given on the command line.  If this is
omitted then the format is autodetected from the content of the disk image.

If disk images are requested from libvirt, then this program asks libvirt
for this information.  In this case, the value of the format parameter is
ignored.

If working with untrusted raw-format guest disk images, you should ensure
the format is always specified.

=item B<-x> | B<--extract> | B<--download>

=item B<-u> | B<--upload>

Use I<-x> to extract (download) a directory from a virtual machine to a
local tarball.

Use I<-u> to upload and unpack from a local tarball into a virtual machine.
Please read the L</WARNING> section above before using this option.

You must specify exactly one of these options.

=item B<-z> | B<--gzip>

Specify that the input or output tarball is gzip-compressed.

=back

=head1 SHELL QUOTING

Libvirt guest names can contain arbitrary characters, some of which have
meaning to the shell such as C<#> and space.  You may need to quote or
escape these characters on the command line.  See the shell manual page
L<sh(1)> for details.

=head1 SEE ALSO

L<guestfs(3)>, L<guestfish(1)>, L<virt-cat(1)>, L<virt-edit(1)>,
L<virt-copy-in(1)>, L<virt-copy-out(1)>, L<virt-tar-in(1)>,
L<virt-tar-out(1)>, L<Sys::Guestfs(3)>, L<Sys::Guestfs::Lib(3)>,
L<Sys::Virt(3)>, L<http://libguestfs.org/>.

=head1 AUTHOR

Richard W.M. Jones L<http://people.redhat.com/~rjones/>

=head1 COPYRIGHT

Copyright (C) 2009 Red Hat Inc.

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your option)
any later version.

This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
more details.

You should have received a copy of the GNU General Public License along with
this program; if not, write to the Free Software Foundation, Inc., 675 Mass
Ave, Cambridge, MA 02139, USA.
