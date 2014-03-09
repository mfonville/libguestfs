-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA1

Format: 3.0 (quilt)
Source: libguestfs
Binary: guestfsd, libguestfs-dev, libguestfs0, libguestfs-tools, libguestfs0-dbg, python-guestfs, python3-guestfs, libguestfs-perl, libguestfs-ocaml, libguestfs-ocaml-dev, erlang-guestfs, libguestfs-java, ruby-guestfs, libguestfs-gobject-1.0-0, libguestfs-gobject-dev, gir1.2-guestfs-1.0, lua-guestfs, golang-guestfs-dev
Architecture: i386 amd64 all
Version: 1:1.24.8-1ubuntu2
Maintainer: Debian Libvirt Maintainers <pkg-libvirt-maintainers@lists.alioth.debian.org>
Uploaders: Richard Jones <rjones@redhat.com>, Guido Günther <agx@sigxcpu.org>, Hilko Bengen <bengen@debian.org>
Homepage: http://libguestfs.org
Standards-Version: 3.9.5
Vcs-Browser: http://git.debian.org/?p=pkg-libvirt/libguestfs.git
Vcs-Git: git://git.debian.org/git/pkg-libvirt/libguestfs.git
Build-Depends: debhelper (>= 9~), autotools-dev, aptitude, dh-autoreconf, po-debconf, bash-completion, supermin (>= 4.1.5-2~), libreadline-dev, libaugeas-dev (>= 1.0.0), libselinux1-dev, libhivex-dev, libvirt-dev, libmagic-dev, libncurses5-dev, libpcre3-dev, libxml2-dev, libconfig-dev, libc-dev-bin, systemtap-sdt-dev, libcap-dev, libacl1-dev, libyajl-dev, automake, autoconf, libtool, gperf, libxml2-utils, qemu-system-x86 [i386 amd64], qemu-utils, genisoimage, pkg-config, erlang-dev, dh-lua, dh-ocaml, ocaml-nox, ocaml-findlib, libpcre-ocaml-dev, libgettext-ocaml-dev, python (>= 2.6.6-3~), python-all-dev (>= 2.6.6-3~), python3-all-dev, default-jdk, gem2deb, rake, libjs-jquery, libtest-pod-coverage-perl, libextutils-command-perl, libintl-perl, libtest-pod-perl, libstring-shellquote-perl, libsys-virt-perl, libwin-hivex-perl, libfuse-dev, fuse, libglib2.0-dev, gjs, gobject-introspection, libgirepository1.0-dev, gtk-doc-tools, netpbm, icoutils, po4a, curl, golang-go [i386 amd64]
Build-Conflicts: supermin (>= 5)
Package-List: 
 erlang-guestfs deb interpreters extra
 gir1.2-guestfs-1.0 deb introspection extra
 golang-guestfs-dev deb devel extra
 guestfsd deb libs extra
 libguestfs-dev deb libdevel extra
 libguestfs-gobject-1.0-0 deb libs extra
 libguestfs-gobject-dev deb libdevel extra
 libguestfs-java deb java extra
 libguestfs-ocaml deb ocaml extra
 libguestfs-ocaml-dev deb ocaml extra
 libguestfs-perl deb perl extra
 libguestfs-tools deb admin extra
 libguestfs0 deb libs extra
 libguestfs0-dbg deb debug extra
 lua-guestfs deb libs extra
 python-guestfs deb python extra
 python3-guestfs deb python extra
 ruby-guestfs deb ruby extra
Checksums-Sha1: 
 22526111892b13eb50b9763788937538ae472464 11405709 libguestfs_1.24.8.orig.tar.gz
 e0dcc20ee5cabcf25fc952d906b1c40e5ce0ea12 29369 libguestfs_1.24.8-1ubuntu2.debian.tar.gz
Checksums-Sha256: 
 34b6b53f2429a9f77bdd2c61297ccfaf05966836df722e9c23028804662d1aa9 11405709 libguestfs_1.24.8.orig.tar.gz
 906311168dde060d2edff79069fd565453dbbcb3b1f1332034aa49ee16af9b63 29369 libguestfs_1.24.8-1ubuntu2.debian.tar.gz
Files: 
 4506538266bd19db721c71908790db35 11405709 libguestfs_1.24.8.orig.tar.gz
 bc7e09e0ead8f40f80608e93d3a6e836 29369 libguestfs_1.24.8-1ubuntu2.debian.tar.gz
Ruby-Versions: all

-----BEGIN PGP SIGNATURE-----
Version: GnuPG v1.4.14 (GNU/Linux)

iEYEARECAAYFAlMcq1wACgkQXjGr8JbE19WLvgCgljti82oIGT0s3RTlvgHk0g36
EeQAn0lthHFcPsVGOf79BvtHraeBFxjU
=3/h5
-----END PGP SIGNATURE-----
