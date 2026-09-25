## SPDX-License-Identifier: GPL-3.0-only
#
# @file CMakeLists.txt
#
# @copyright Copyright (C) 2014-2026 srcML, LLC. (www.srcML.org)
#
# This file is part of the srcML Infrastructure.
#

cmake_minimum_required(VERSION 3.28)
project(srcSAX)

enable_testing()

# project options
option(INCLUDE_UNIT_TESTS "Build unit tests for srcSAX" ON)
option(INCLUDE_EXAMPLES "Build unit tests for srcSAX" ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions("-Wall")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(CMake)

if(INCLUDE_UNIT_TESTS)
    include_directories(${SRCSAX_INCLUDE_DIR} test)
    add_subdirectory(test)
endif()

if(INCLUDE_EXAMPLES)
    include_directories(${SRCSAX_INCLUDE_DIR} examples)
    add_subdirectory(examples)
endif()
