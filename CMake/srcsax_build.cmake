##
#  config.cmake
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
#
#  Build configuration file

get_filename_component(SRCSAX_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(SRCSAX_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR} DIRECTORY)

# Compiler options
add_definitions("-std=c++11")

# find needed libraries
find_package(LibXml2 REQUIRED)

# include needed includes
include_directories(${LIBXML2_INCLUDE_DIR} 
    ${SRCSAX_SOURCE_DIR}/src/srcsax
    ${SRCSAX_SOURCE_DIR}/src/cpp
    ${SRCSAX_SOURCE_DIR}/src/windows)

# Continue to build directory
add_subdirectory(${SRCSAX_SOURCE_DIR}/src ${SRCSAX_BINARY_DIR}/src)
