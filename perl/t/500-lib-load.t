# libguestfs Perl bindings -*- perl -*-
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
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

use strict;
use warnings;

BEGIN {
    use Test::More;

    eval "use Locale::TextDomain";;
    if (exists $INC{"Locale/TextDomain.pm"}) {
        plan tests => 1;
    } else {
        plan skip_all => "no perl-libintl module";
        exit 0;
    }
}

use Sys::Guestfs;
use Sys::Guestfs::Lib;

# Just check Lib can be loaded.
ok (1);
