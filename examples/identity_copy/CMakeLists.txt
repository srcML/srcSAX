## SPDX-License-Identifier: GPL-3.0-only
#
# @file CMakeLists.txt
#
# @copyright Copyright (C) 2014-2026 srcML, LLC. (www.srcML.org)
#
# This file is part of the srcML Infrastructure.
#

file(GLOB IDENTITY_COPY_SOURCE *.cpp)
file(GLOB IDENTITY_COPY_HEADER *.hpp)

find_package(LibXml2 REQUIRED)

add_executable(identity_copy ${IDENTITY_COPY_SOURCE} ${IDENTITY_COPY_HEADER})
target_link_libraries(identity_copy srcsax_static LibXml2::LibXml2)
