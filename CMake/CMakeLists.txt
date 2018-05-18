##
#  srcsax.cmake
#
#  Copyright (C) 2014 SDML (www.sdml.info)
#
#  This file is part of the srcSAX.
#
#  The srcSAX is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  The srcSAX is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with the srcSAX; if not, write to the Free Software
#  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

# add this directory
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

# project options
option(INCLUDE_UNIT_TESTS "Build unit tests for srcSAX" ON)
option(INCLUDE_EXAMPLES "Build unit tests for srcSAX" ON)

include(srcsax_build)
include(srcsax_install)
include(srcsax_testing)
