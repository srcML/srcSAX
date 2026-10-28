## SPDX-License-Identifier: GPL-3.0-only
#
# @file CMakeLists.txt
#
# @copyright Copyright (C) 2015-2026 srcML, LLC. (www.srcML.org)
#
# This file is part of the srcML Infrastructure.
#

file(GLOB HANDLER_SOURCE srcsax/*.cpp cpp/*.cpp)
file(GLOB HANDLER_INCLUDE srcsax/*.h srcsax/*.hpp cpp/*.hpp)

file(GLOB WINDOWS_SOURCE windows/*.cpp)
file(GLOB WINDOWS_INCLUDE windows/*.hpp)

# build_lib
#  Used to help with the creation of the srcML library.
#  - LIB_NAME is the name of the library and target
#  - LIB_TYPE is either STATIC or SHARED.
# 
macro(build_lib LIB_NAME LIB_TYPE)

    add_library(${LIB_NAME} ${LIB_TYPE} ${HANDLER_SOURCE} ${HANDLER_INCLUDE} ${WINDOWS_SOURCE} ${WINDOWS_INCLUDE})

if("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
    if("${LIB_TYPE}" STREQUAL "STATIC")
        set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME libsrcsax_static)
    else()
        set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME libsrcsax)
    endif()
elseif(APPLE)
    set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME srcsax MACOSX_RPATH ON)
else()
    set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME srcsax)
endif()

endmacro()

find_package(LibXml2 REQUIRED)

build_lib(srcsax_static STATIC)
build_lib(srcsax_shared SHARED)

foreach(kind IN ITEMS static shared)
    target_include_directories(srcsax_${kind} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/srcsax>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/cpp>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/srcsax>)
    target_link_libraries(srcsax_${kind} PUBLIC LibXml2::LibXml2)
    target_compile_features(srcsax_${kind} PUBLIC cxx_std_17)
endforeach()

include(${CMAKE_CURRENT_SOURCE_DIR}/../CMake/srcsax_install.cmake)
