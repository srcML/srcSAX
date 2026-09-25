## SPDX-License-Identifier: GPL-3.0-only
#
# @file CMakeLists.txt
#
# @copyright Copyright (C) 2014-2026 srcML, LLC. (www.srcML.org)
#
# This file is part of the srcML Infrastructure.
#

file(GLOB ELEMENT_COUNT_SOURCE *.cpp)
file(GLOB ELEMENT_COUNT_HEADER *.hpp)

find_package(LibXml2 REQUIRED)

add_executable(element_count ${ELEMENT_COUNT_SOURCE} ${ELEMENT_COUNT_HEADER})
target_link_libraries(element_count srcsax_static LibXml2::LibXml2)
