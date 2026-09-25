// SPDX-License-Identifier: GPL-3.0-only
/**
 * @file windows_utils.hpp
 *
 * @copyright Copyright (C) 2014-2026 srcML, LLC. (www.srcML.org)
 *
 * This file is part of the srcML Infrastructure.
 */

#ifndef INCLUDED_SRCTOOLS_WINDOWS_HPP
#define INCLUDED_SRCTOOLS_WINDOWS_HPP

#ifdef _MSC_BUILD

#ifdef WIN32
#include <cstdlib>
#endif

char * strndup(const char * source, size_t n);

#endif

#endif
