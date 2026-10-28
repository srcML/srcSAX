## SPDX-License-Identifier: GPL-3.0-only
#
# @file CMakeLists.txt
#
# @copyright Copyright (C) 2023-2026 srcML, LLC. (www.srcML.org)
#
# This file is part of the srcML Infrastructure.
#

cmake_minimum_required(VERSION 3.28)
project(name_collector LANGUAGES CXX)

file(GLOB NAME_COLLECTOR_COPY_SOURCE *.cpp)
file(GLOB NAME_COLLECTOR_COPY_HEADER *.hpp)

# Use the installed srcSAX package; shared is the default.
# For static linking: find_package(srcSAX REQUIRED COMPONENTS static)
if(NOT TARGET srcSAX::LibsrcSAX)
    find_package(srcSAX REQUIRED)
endif()

add_executable(name_collector ${NAME_COLLECTOR_COPY_SOURCE} ${NAME_COLLECTOR_COPY_HEADER})
target_link_libraries(name_collector PRIVATE srcSAX::LibsrcSAX)
