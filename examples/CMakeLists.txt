##
#  CMakeLists.txt
#
#  Copyright (C) 2014-2023 SDML (www.sdml.info)
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

add_subdirectory(print_callbacks)
add_subdirectory(identity_copy)
add_subdirectory(element_count)
add_subdirectory(name_collector)

file(COPY example.xml DESTINATION ${CMAKE_BINARY_DIR}/bin)
