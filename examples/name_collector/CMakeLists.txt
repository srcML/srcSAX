## SPDX-License-Identifier: GPL-3.0-only
#
# @file CMakeLists.txt
#
# @copyright Copyright (C) 2023-2026 srcML, LLC. (www.srcML.org)
#
# This file is part of the srcML Infrastructure.
#

file(GLOB NAME_COLLECTOR_COPY_SOURCE *.cpp)
file(GLOB NAME_COLLECTOR_COPY_HEADER *.hpp)

find_package(LibXml2 REQUIRED)

add_executable(name_collector ${NAME_COLLECTOR_COPY_SOURCE} ${NAME_COLLECTOR_COPY_HEADER})
target_link_libraries(name_collector srcsax_static LibXml2::LibXml2)
