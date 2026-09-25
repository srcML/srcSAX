## SPDX-License-Identifier: GPL-3.0-only
#
# @file srcsax_build.cmake
#
# @copyright Copyright (C) 2014-2026 srcML, LLC. (www.srcML.org)
#
# This file is part of the srcML Infrastructure.
#
#  Build configuration file

get_filename_component(SRCSAX_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
get_filename_component(SRCSAX_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR} DIRECTORY)

# Compiler options
add_definitions("-std=c++11")

set(SRCSAX_INCLUDE_DIR ${SRCSAX_SOURCE_DIR}/src/srcsax
                       ${SRCSAX_SOURCE_DIR}/src/cpp
                       ${SRCSAX_SOURCE_DIR}/src/windows
    CACHE INTERNAL "Include directories for srcSAX")

# include needed includes
include_directories(${SRCSAX_INCLUDE_DIR})

# Continue to build directory
add_subdirectory(${SRCSAX_SOURCE_DIR}/src ${SRCSAX_BINARY_DIR}/src)
