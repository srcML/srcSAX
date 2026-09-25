// SPDX-License-Identifier: GPL-3.0-only
/**
 * @file windows_utils.cpp
 *
 * @copyright Copyright (C) 2013-2026 srcML, LLC. (www.srcML.org)
 *
 * This file is part of the srcML Infrastructure.
 */

#include <windows_utils.hpp>

#include <cstdlib>
#include <cstring>

#ifdef _MSC_BUILD

char * strndup(const char * source, size_t n) {

	if(source == 0) return 0;

	char * dup = (char *)malloc((n + 1) * sizeof(char));
	strncpy(dup, source, n);
	dup[n] = 0;

	return dup;

}

#endif
