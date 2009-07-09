#!/bin/bash -
# appliance/supermin-split.sh.  Generated from supermin-split.sh.in by configure.
# Copyright (C) 2009 Red Hat Inc.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

# Decide which files will stay in the supermin appliance and which
# files will be pulled out of the host at runtime.
#
# Read the README file!
#
# The basic idea is that we create two output files, one containing
# the files that will stay, and the other listing the files that
# will be pulled from the host (ie. not go into the appliance now).
#
# The list of files that stay ('supermin.incfiles') is just a straight
# list of files and directories.
#
# The list of files that come from the host ('*.supermin.hostfiles')
# can include wildcards, to allow libraries to be upgraded on the
# host.

unset CDPATH

set -e

cd ../initramfs

incfiles=../appliance/supermin.incfiles
hostfiles=../appliance/initramfs.fedora-11.i686.supermin.hostfiles

exec 5>$incfiles
exec 6>$hostfiles

# Note currently the initramfs contains ~2500 files, and none have
# "funny characters" in the names.  So this is reasonable just to
# simplify the script.
for path in $(find -not -name fakeroot.log); do
    dir=$(dirname "$path")
    file=$(basename "$path")

    # All we're going to keep are the special files /init, the daemon,
    # configuration files (/etc), devices and modifiable stuff (/var).
    if [ "$path" = "./init" -o "$file" = "guestfsd" ]; then
	echo "$path" >&5

    elif [[ "$path" =~ '^\./etc' || "$path" =~ '^./dev' || "$path" =~ '^\./var' ]]; then
	echo "$path" >&5

    # Kernel modules are always copied in from the host, including all
    # the dependency files.
    elif [[ "$path" =~ '^\./lib/modules/' ]]; then
	:

    elif [ -d "$path" ]; then
	# Always write directory names to both output files.
	echo "$path" >&5
	echo "$path" >&6

    # Some libraries need fixed version numbers replaced by wildcards.

    elif [[ "$file" =~ '^ld-[.0-9]+\.so$' ]]; then
	echo "$dir/ld-*.so" >&6

    # libfoo-1.2.3.so
    elif [[ "$file" =~ '^lib(.*)-[-.0-9]+\.so$' ]]; then
	echo "$dir/lib${BASH_REMATCH[1]}-*.so" >&6

    # libfoo-1.2.3.so.1.2.3 (but NOT '*.so.N')
    elif [[ "$file" =~ '^lib(.*)-[-.0-9]+\.so\.([0-9]+)\.' ]]; then
	echo "$dir/lib${BASH_REMATCH[1]}-*.so.${BASH_REMATCH[2]}.*" >&6

    # libfoo.so.1.2.3 (but NOT '*.so.N')
    elif [[ "$file" =~ '^lib(.*)\.so\.([0-9]+)\.' ]]; then
	echo "$dir/lib${BASH_REMATCH[1]}.so.${BASH_REMATCH[2]}.*" >&6

    else
	# Anything else comes from the host directly.
	echo "$path" >&6
    fi
done
