## SPDX-License-Identifier: GPL-3.0-only
#
# @file CMakeLists.txt
#
# @copyright Copyright (C) 2015-2026 srcML, LLC. (www.srcML.org)
#
# This file is part of the srcML Infrastructure.
#

file(GLOB HANDLER_SOURCE srcsax/*.cpp cpp/*.cpp)
file(GLOB HANDLER_INCLUDE srcsax/*.hpp cpp/*.hpp)

file(GLOB HANDLER_INTERNAL_INCLUDE srcsax/internal/*.h)

file(GLOB WINDOWS_SOURCE windows/*.cpp)
file(GLOB WINDOWS_INCLUDE windows/*.hpp)

# build_lib
#  Used to help with the creation of the srcML library.
#  - LIB_NAME is the name of the library and target
#  - LIB_TYPE is either STATIC or SHARED.
# 
macro(build_lib LIB_NAME LIB_TYPE)

    add_library(${LIB_NAME} ${LIB_TYPE} ${HANDLER_SOURCE} ${HANDLER_INCLUDE} ${HANDLER_INTERNAL_INCLUDE} ${WINDOWS_SOURCE} ${WINDOWS_INCLUDE})

if("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
    if("${LIB_TYPE}" STREQUAL "STATIC")
        set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME libsrcsax_static)
    else()
        set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME libsrcsax)
    endif()
elseif(APPLE)
    set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME srcsax MACOSX_RPATH OFF)
else()
    set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME srcsax)
endif()

endmacro()

find_package(LibXml2 REQUIRED)

build_lib(srcsax_static STATIC)
target_link_libraries(srcsax_static PRIVATE LibXml2::LibXml2)

build_lib(srcsax_shared SHARED)
target_link_libraries(srcsax_shared PRIVATE LibXml2::LibXml2)

install(TARGETS srcsax_shared srcsax_static 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION ${CMAKE_INSTALL_BINDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_BINDIR}
       )
install(FILES ${HANDLER_INCLUDE} DESTINATION include/srcsax)
install(FILES ${HANDLER_INTERNAL_INCLUDE} DESTINATION include/srcsax/internal)
