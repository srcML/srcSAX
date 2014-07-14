/**
 * @file srcSAXHandler.hpp
 *
 * @copyright Copyright (C) 2013-2014 SDML (www.srcML.org)
 *
 * The srcML Toolkit is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * The srcML Toolkit is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the srcML Toolkit; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef INCLUDED_SRCSAX_H
#define INCLUDED_SRCSAX_H

#include <srcsax_handler.h>

#include <libxml/parser.h>

/**
 * srcsax_context
 *
 * Context data structure passed between callbacks.
 */
struct srcsax_context {

    /** user provided data */
    void * data;

    /** srcSAX handler callbacks */
    struct srcsax_handler * sax;

    /** error callback need to figure this one out probably message and errorcode. or struct */
    void (*srcsax_error)(const char * message, int error_code);

    /** is the document an archive */
    int is_archive;

    /** the current unit count */
    int unit_count;

    /** the xml documents encoding */
    const char * encoding;

    /** internally used libxml2 context */
    xmlParserCtxtPtr libxml2_context;

};


int srcsax_create_context_filename(const char * filename, int options);
int srcsax_parse(struct srcsax_context * context);
void stop_srcsax_parser(struct srcsax_context * context);


#endif
