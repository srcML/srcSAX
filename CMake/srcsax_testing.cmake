## SPDX-License-Identifier: GPL-3.0-only
#
# @file srcsax_testing.cmake
#
# @copyright Copyright (C) 2014-2026 srcML, LLC. (www.srcML.org)
#
# This file is part of the srcML Infrastructure.
#

# 
# Testing macros/functions and additional variables. These functions will also allow
# for the specification of additional resource locations.
#

#
# add_unit_test
# Creates a unit test from a given file with a given name.
# - FILE_NAME the name of the unit test file.
# All arguments after the file name are considered to be linker arguments.
#
#
macro(add_unit_test TEST_FILE)

    get_filename_component(TEST_NAME_WITH_EXTENSION ${TEST_FILE} NAME)
    string(FIND ${TEST_NAME_WITH_EXTENSION} "." EXTENSION_BEGIN)
    string(SUBSTRING ${TEST_NAME_WITH_EXTENSION} 0 ${EXTENSION_BEGIN} TEST_NAME)

    add_executable(${TEST_NAME} ${TEST_FILE})
    target_link_libraries(${TEST_NAME} ${ARGN})
    add_test(NAME ${TEST_NAME} COMMAND $<TARGET_FILE:${TEST_NAME}>)
    set_target_properties(${TEST_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

endmacro()
