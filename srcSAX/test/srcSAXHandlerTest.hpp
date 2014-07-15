/**
 * @file srcsax_handler_test.hpp
 *
 * @copyright Copyright (C) 2013-2014  SDML (www.srcML.org)
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

#ifndef INCLUDED_SRCSAX_HANDLER_TEST_HPP
#define INCLUDED_SRCSAX_HANDLER_TEST_HPP

#include <srcSAXHandler.hpp>

#include <libxml/parser.h>

/**
 * srcsax_handler_test
 *
 * Base class that provides hooks for SAX processing.
 */
class srcsax_handler_test {

public :

  int start_document_call_number;
  int end_document_call_number;

  int start_root_call_number;
  int start_unit_call_number;
  int start_element_ns_call_number;

  int end_root_call_number;
  int end_unit_call_number;
  int end_element_ns_call_number;

  int characters_root_call_number;
  int characters_unit_call_number;

  int comment_call_number;
  int cdata_block_call_number;

  int call_count;

  srcsax_handler_test() 
    : start_document_call_number(0), end_document_call_number(0), start_root_call_number(0), start_unit_call_number(0), start_element_ns_call_number(0),
      end_root_call_number(0), end_unit_call_number(0), end_element_ns_call_number(0), characters_root_call_number(0), characters_unit_call_number(0),
      comment_call_number_(0), cdata_block_call_number(0), call_count(0) {}

    /**
     * factory
     *
     * Factory method to generate the srcsax_handler containin this classes
     * callbacks needed to test C API.
     *
     * @returns the generated srcsax_handler with the correct callbacks for C API.
     */
    static srcsax_handler factory() {

        srcsax_handler handler;

        handler.start_document = start_document;
        handler.end_document = end_document;
        handler.start_root = start_root;
        handler.start_unit = start_unit;
        handler.start_element_ns = start_element_ns;
        handler.end_root = end_root;
        handler.end_unit = end_unit;
        handler.end_element_ns = end_element_ns;
        handler.characters_root = characters_root;
        handler.characters_unit = characters_unit;
        handler.comment = comment;
        handler.cdata_block = cdata_block;
        handler.processing_instruction = processing_instruction;

        return handler;

    }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

  /**
   * start_document
   *
   * SAX handler function for start of document.
   * Overidden for testing.  Count calls made and order.
   */
  static void start_document() { 

    start_document_call_number = ++call_count;

  }

  /**
   * end_document
   *
   * SAX handler function for end of document.
   * Overidden for testing.  Count calls made and order.
   */
  static void end_document() {

    end_document_call_number = ++call_count;

  }

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
   *
   * SAX handler function for start of the root element.
   * Overidden for testing.  Count calls made and order.
   */
  static void start_root(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                         int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                         const xmlChar ** attributes, std::vector<srcml_element *> * meta_tags) {

    start_root_call_number = ++call_count;

  }

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
   * SAX handler function for start of an unit.
   * Overidden for testing.  Count calls made and order.
   */
  static void start_unit(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                         int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                         const xmlChar ** attributes) {

    start_unit_call_number = ++call_count;

  }

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
   * SAX handler function for start of an element.
   * Overidden for testing.  Count calls made and order.
   */
  static void start_element_ns(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                              int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                              const xmlChar ** attributes) {
    start_element_ns_call_number = ++call_count;

  }

  /**
   * end_root
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   *
   * SAX handler function for end of the root element.
   * Overidden for testing.  Count calls made and order.
   */
  static void end_root(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

    end_root_call_number = ++call_count;

  }

  /**
   * end_unit
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   *
   * SAX handler function for end of an unit.
   * Overidden for testing.  Count calls made and order.
   */
  static void end_unit(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

    end_unit_call_number = ++call_count;

  }

  /**
   * end_element_ns
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   *
   * SAX handler function for end of an element.
   * Overidden for testing.  Count calls made and order.
   */
  static void end_element_ns(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

    end_element_ns_call_number = ++call_count;

  }

  /**
   * characters_root
   * @param ch the characers
   * @param len number of characters
   *
   * SAX handler function for character handling at the root level.
   * Overidden for testing.  Count calls made and order.
   */
  static void characters_root(const xmlChar * ch, int len) {

    characters_root_call_number = ++call_count;

  }

  /**
   * charactersUnit
   * @param ch the characers
   * @param len number of characters
   *
   * SAX handler function for character handling within a unit.
   * Overidden for testing.  Count calls made and order.
   */
  static void charactersUnit(const xmlChar * ch, int len) {

    characters_unit_call_number = ++call_count;

  }

  /**
   * comment
   * @param value the comment content
   *
   * A comment has been parsed.
   * Overidden for testing.  Count calls made and order.
   */
  static void comment(const xmlChar * value) {

    comment_call_number_ = ++call_count;

  }

  /**
   * cdata_block
   * @param value the pcdata content
   * @param len the block length
   *
   * Called when a pcdata block has been parsed.
   * Overidden for testing.  Count calls made and order.
   */
  static void cdata_block(const xmlChar * value, int len) {

    cdata_block_call_number = ++call_count;

  }

  /**
   * processing_instruction
   * @param value the pcdata content
   * @param len the block length
   *
   * Called when a pcdata block has been parsed.
   * Overidden for testing.  Count calls made and order.
   */
  static void processing_instruction(const xmlChar * value, int len) {

    processing_instruction = ++call_count;

  }

#pragma GCC diagnostic pop

};

#endif
