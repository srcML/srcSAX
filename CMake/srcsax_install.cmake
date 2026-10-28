## SPDX-License-Identifier: GPL-3.0-only
#
# @file srcsax_install.cmake
#
# @copyright Copyright (C) 2014-2026 srcML, LLC. (www.srcML.org)
#
# This file is part of the srcML Infrastructure.
#

include(CMakePackageConfigHelpers)
set(SRCSAX_CONFIG_DESTINATION "${CMAKE_INSTALL_DATADIR}/cmake/srcsax")

foreach(kind IN ITEMS static shared)
    install(TARGETS srcsax_${kind} EXPORT srcsax_${kind}_Targets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
    install(EXPORT srcsax_${kind}_Targets
        DESTINATION "${SRCSAX_CONFIG_DESTINATION}"
        NAMESPACE srcSAX::
        FILE srcSAX-${kind}-targets.cmake)
endforeach()
install(FILES ${HANDLER_INCLUDE} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/srcsax)

configure_package_config_file(
    "${CMAKE_CURRENT_LIST_DIR}/srcSAXConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/srcSAXConfig.cmake"
    INSTALL_DESTINATION "${SRCSAX_CONFIG_DESTINATION}"
    NO_SET_AND_CHECK_MACRO
    NO_CHECK_REQUIRED_COMPONENTS_MACRO)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/srcSAXConfig.cmake"
    DESTINATION "${SRCSAX_CONFIG_DESTINATION}")
