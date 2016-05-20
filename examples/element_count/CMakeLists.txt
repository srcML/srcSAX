##
#  CMakeLists.txt
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

file(GLOB ELEMENT_COUNT_SOURCE *.cpp)
file(GLOB ELEMENT_COUNT_HEADER *.hpp)

add_executable(element_count ${ELEMENT_COUNT_SOURCE} ${ELEMENT_COUNT_HEADER})
target_link_libraries(element_count srcsax_static ${LIBXML2_LIBRARIES})

# eventually make thes part of either the sub-directies or the add_unit_test
copy_dependent_file(element_count ../example.xml)
