## SPDX-License-Identifier: GPL-3.0-only
#
# @file CMakeLists.txt
#
# @copyright Copyright (C) 2014-2026 srcML, LLC. (www.srcML.org)
#
# This file is part of the srcML Infrastructure.
#

add_subdirectory(print_callbacks)
add_subdirectory(identity_copy)
add_subdirectory(element_count)
add_subdirectory(name_collector)

file(COPY example.xml DESTINATION ${CMAKE_BINARY_DIR}/bin)
