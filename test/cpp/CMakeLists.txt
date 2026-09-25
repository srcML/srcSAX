## SPDX-License-Identifier: GPL-3.0-only
#
# @file CMakeLists.txt
#
# @copyright Copyright (C) 2014-2026 srcML, LLC. (www.srcML.org)
#
# This file is part of the srcML Infrastructure.
#

find_package(LibXml2 REQUIRED)

add_unit_test(test_srcsax_controller.cpp srcsax_static LibXml2::LibXml2)
add_unit_test(test_srcsax_handler_cpp.cpp srcsax_static LibXml2::LibXml2)
