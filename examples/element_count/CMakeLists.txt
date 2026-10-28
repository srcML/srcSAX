## SPDX-License-Identifier: GPL-3.0-only
#
# @file CMakeLists.txt
#
# @copyright Copyright (C) 2014-2026 srcML, LLC. (www.srcML.org)
#
# This file is part of the srcML Infrastructure.
#

cmake_minimum_required(VERSION 3.28)
project(element_count LANGUAGES CXX)

file(GLOB ELEMENT_COUNT_SOURCE *.cpp)
file(GLOB ELEMENT_COUNT_HEADER *.hpp)

# Use the installed srcSAX package; shared is the default.
# For static linking: find_package(srcSAX REQUIRED COMPONENTS static)
find_package(srcSAX REQUIRED)

add_executable(element_count ${ELEMENT_COUNT_SOURCE} ${ELEMENT_COUNT_HEADER})
target_link_libraries(element_count PRIVATE srcSAX::LibsrcSAX)
