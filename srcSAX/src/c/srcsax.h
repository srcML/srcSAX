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

#include <srcMLElement.hpp>
#include <srcSAXController.hpp>

#include <libxml/parser.h>

#include <vector>

/**
 * srcsax_context
 *
 * Context data structure passed between callbacks.
 */
struct srcsax_context {


    /** is the document an archive */
    bool is_archive;

    /** the current unit count */
    int unit_count;

    /** the xml documents encoding */
    const char * encoding;

};

/**
 * start_document
 *
 * Signature for srcSAX handler function for start of document.
 */
typedef void (*start_document)();

/**
 * end_document
 *
 * Signature for srcSAX handler function for end of document.
 */
typedef void (*end_document)();

/**
 * start_root
 * @param localname the name of the element tag
 * @param prefix the tag prefix
 * @param URI the namespace of tag
 * @param nb_namespaces number of namespaces definitions
 * @param namespaces the defined namespaces
 * @param nb_attributes the number of attributes on the tag
 * @param nb_defaulted the number of defaulted attributes
 * @param attributes list of attribute name value pairs (localname/prefix/URI/value/end)
 * @param meta_tags vector of elements composed of metage tags defined after root tag
 *
 * Signature for srcSAX handler function for start of the root element.
 */
void (*start_root(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                       int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                       const xmlChar ** attributes, std::vector<srcMLElement> * meta_tags));

/**
 * start_unit
 * @param localname the name of the element tag
 * @param prefix the tag prefix
 * @param URI the namespace of tag
 * @param nb_namespaces number of namespaces definitions
 * @param namespaces the defined namespaces
 * @param nb_attributes the number of attributes on the tag
 * @param nb_defaulted the number of defaulted attributes
 * @param attributes list of attribute name value pairs (localname/prefix/URI/value/end)
 *
 * Signature srcSAX handler function for start of an unit.
 * Overide for desired behaviour.
 */
void (*start_unit(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                       int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                       const xmlChar ** attributes));

/**
 * start_function
 * @param name the function's name
 * @param return_type the function return type
 * @param parameter_list a list of the function parameters in struct containing (declaration.type/declaration.name)
 * @param is_decl indicates if the call is a function declaration (true) or definition (false)
 *
 * Signature for srcSAX handler function for start of function with prototype.
 * Accessing references after callback termination is undefined.

 */
typedef void (*start_function(const std::string & name, const std::string & return_type, const std::vector<declaration> & parameter_list, bool is_decl));

/**
 * start_element_ns
 * @param localname the name of the element tag
 * @param prefix the tag prefix
 * @param URI the namespace of tag
 * @param nb_namespaces number of namespaces definitions
 * @param namespaces the defined namespaces
 * @param nb_attributes the number of attributes on the tag
 * @param nb_defaulted the number of defaulted attributes
 * @param attributes list of attribute name value pairs (localname/prefix/URI/value/end)
 *
 * Signature for srcSAX handler function for start of an element.
 */
typedef void (*start_element_ns(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                            int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                            const xmlChar ** attributes));

/**
 * end_root
 * @param localname the name of the element tag
 * @param prefix the tag prefix
 * @param URI the namespace of tag
 *
 * Signature for srcSAX handler function for end of the root element.
 */
typedef void (*end_root(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI));

/**
 * end_unit
 * @param localname the name of the element tag
 * @param prefix the tag prefix
 * @param URI the namespace of tag
 *
 * Signature for srcSAX handler function for end of an unit.
 */
typedef void (*end_unit(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI));

/**
 * end_function
 *
 * Signature for srcSAX handler function for end of a function.
 */
typedef void (*end_function());

/**
 * end_element_ns
 * @param localname the name of the element tag
 * @param prefix the tag prefix
 * @param URI the namespace of tag
 *
 * Signature for srcSAX handler function for end of an element.
 */
typedef void (*end_element_ns(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI));

/**
 * characters_root
 * @param ch the characers
 * @param len number of characters
 *
 * Signature for srcSAX handler function for character handling at the root level.
 */
typedef void (*characters_root(const xmlChar * ch, int len));

/**
 * characters_unit
 * @param ch the characers
 * @param len number of characters
 *
 * Signature for srcSAX handler function for character handling within a unit.
 */
typedef void (*characters_unit(const xmlChar * ch, int len));

/**
 * comment
 * @param value the comment content
 *
 * Signature for srcSAX handler function for a XML comment.
 */
typedef void (*comment(const xmlChar * value));

/**
 * cdata_block
 * @param value the pcdata content
 * @param len the block length
 *
 * Signature for srcSAX handler function for pcdata block.
 */
typedef void (*cdata_block(const xmlChar * value, int len));

/**
 * processing_instruction
 * @param target the processing instruction target.
 * @param data the processing instruction data.
 *
 * Signature for srcSAX handler function for processing instruction
 */
typedef void (*processing_instruction(const xmlChar * target, const xmlChar * data));



#endif
