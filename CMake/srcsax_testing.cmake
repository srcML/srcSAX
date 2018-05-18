##
#  testing.cmake
#
#  Copyright (C) 2014 SDML (www.sdml.info)
#
#  This file is part of the srcSAX.
#
#  The srcSAX is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#
#  The srcSAX is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with the srcSAX; if not, write to the Free Software
#  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA


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

# 
# copy_dependent_file 
# This copies a file given as FILE_NAME to the current bunary directory
# of the build and adds it as a dependency to TARGET_NAME.
# 
macro(copy_dependent_file TARGET_NAME FILE_NAME)

    if(NOT ${CMAKE_SOURCE_DIR} MATCHES ${CMAKE_BINARY_DIR})

        file(COPY ${FILE_NAME} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
        add_dependencies(${TARGET_NAME} ${FILE_NAME})

    endif()

endmacro()
