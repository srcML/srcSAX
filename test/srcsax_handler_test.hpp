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

#include <string.h>
#include <string>
#include <cassert>

/**
 * srcsax_handler_test
 *
 * Test class with callbacks for C API.
 */
class srcsax_handler_test {

public :

  /** number which start_document callback was called */
  int start_document_call_number;
  /** number which end_document callback was called */
  int end_document_call_number;

  /** number which start_root callback was called */
  int start_root_call_number;
  /** number which start_unit callback was called */
  int start_unit_call_number;
  /** number which start_element callback was called */
  int start_element_call_number;

  /** number which end_root callback was called */
  int end_root_call_number;
  /** number which end_unit callback was called */
  int end_unit_call_number;
  /** number which end_elemnt callback was called */
  int end_element_call_number;

  /** number which characters_root callback was called */
  int characters_root_call_number;
  /** number which characters_unit callback was called */
  int characters_unit_call_number;

  /** number which meta_tag callback was called */
  int meta_tag_call_number;
  /** number which comment callback was called */
  int comment_call_number;
  /** number which cdata_block callback was called */
  int cdata_block_call_number;
  /** number which processing_instruction callback was called */
  int processing_instruction_call_number;

  /** the number of calls made */
  int call_count;

  /**
   * srcsax_handler_test
   *
   * Constructor.  Initialize members for testing C API.
   */
  srcsax_handler_test() 
    : start_document_call_number(0), end_document_call_number(0), start_root_call_number(0), start_unit_call_number(0), start_element_call_number(0),
      end_root_call_number(0), end_unit_call_number(0), end_element_call_number(0), characters_root_call_number(0), characters_unit_call_number(0),
      meta_tag_call_number(0), comment_call_number(0), cdata_block_call_number(0), processing_instruction_call_number(0), call_count(0) {}

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
      handler.start_element = start_element;
      handler.end_root = end_root;
      handler.end_unit = end_unit;
      handler.end_element = end_element;
      handler.characters_root = characters_root;
      handler.characters_unit = characters_unit;
      handler.meta_tag = meta_tag;
      handler.comment = comment;
      handler.cdata_block = cdata_block;
      handler.processing_instruction = processing_instruction;

      return handler;

  }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

  /**
   * start_document
   * @param context a srcSAX context
   *
   * SAX handler function for start of document.
   * Overidden for testing.  Count calls made and order.
   */
  static void start_document(struct srcsax_context * context) {

    srcsax_handler_test * test_handler = (srcsax_handler_test *)context->data;

    assert(context->stack_size == 0);
    assert(context->srcml_element_stack == 0);

    test_handler->start_document_call_number = ++test_handler->call_count;

  }

  /**
   * end_document
   * @param context a srcSAX context
   *
   * SAX handler function for end of document.
   * Overidden for testing.  Count calls made and order.
   */
  static void end_document(struct srcsax_context * context) {

    srcsax_handler_test * test_handler = (srcsax_handler_test *)context->data;

    assert(context->stack_size == 0);
    assert(context->srcml_element_stack == 0);

    test_handler->end_document_call_number = ++test_handler->call_count;

  }

  /**
   * start_root
   * @param context a srcSAX context
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   * @param nb_namespaces number of namespaces definitions
   * @param namespaces the defined namespaces
   * @param nb_attributes the number of attributes on the tag
   * @param attributes list of attributes
   *
   * SAX handler function for start of the root element.
   * Overidden for testing.  Count calls made and order.
   */
  static void start_root(struct srcsax_context * context, const char * localname, const char * prefix, const char * URI,
                         int nb_namespaces, const struct srcsax_namespace * namespaces, int nb_attributes,
                         const struct srcsax_attribute * attributes) {

    srcsax_handler_test * test_handler = (srcsax_handler_test *)context->data;

    assert(context->stack_size == 1);
    assert(strcmp(context->srcml_element_stack[context->stack_size - 1], "unit") == 0);

    test_handler->start_root_call_number = ++test_handler->call_count;

  }

  /**
   * start_unit
   * @param context a srcSAX context
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   * @param nb_namespaces number of namespaces definitions
   * @param namespaces the defined namespaces
   * @param nb_attributes the number of attributes on the tag
   * @param attributes list of attributes
   *
   * SAX handler function for start of an unit.
   * Overidden for testing.  Count calls made and order.
   */
  static void start_unit(struct srcsax_context * context, const char * localname, const char * prefix, const char * URI,
                         int nb_namespaces, const struct srcsax_namespace * namespaces, int nb_attributes,
                         const struct srcsax_attribute * attributes) {

    srcsax_handler_test * test_handler = (srcsax_handler_test *)context->data;

    assert(strcmp(context->srcml_element_stack[context->stack_size - 1], "unit") == 0);

    test_handler->start_unit_call_number = ++test_handler->call_count;

  }

  /**
   * start_element
   * @param context a srcSAX context
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   * @param nb_namespaces number of namespaces definitions
   * @param namespaces the defined namespaces
   * @param nb_attributes the number of attributes on the tag
   * @param attributes list of attributes
   *
   * SAX handler function for start of an element.
   * Overidden for testing.  Count calls made and order.
   */
  static void start_element(struct srcsax_context * context, const char * localname, const char * prefix, const char * URI,
                              int nb_namespaces, const struct srcsax_namespace * namespaces, int nb_attributes,
                              const struct srcsax_attribute * attributes) {

    srcsax_handler_test * test_handler = (srcsax_handler_test *)context->data;

    std::string element = "";
    if(prefix) {

      element += prefix;
      element += ':';

    }

    element += localname;

   assert(std::string(context->srcml_element_stack[context->stack_size - 1]) == element);

    test_handler->start_element_call_number = ++test_handler->call_count;

  }

  /**
   * end_root
   * @param context a srcSAX context
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   *
   * SAX handler function for end of the root element.
   * Overidden for testing.  Count calls made and order.
   */
  static void end_root(struct srcsax_context * context, const char * localname, const char * prefix, const char * URI) {

    srcsax_handler_test * test_handler = (srcsax_handler_test *)context->data;

    test_handler->end_root_call_number = ++test_handler->call_count;

  }

  /**
   * end_unit
   * @param context a srcSAX context
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   *
   * SAX handler function for end of an unit.
   * Overidden for testing.  Count calls made and order.
   */
  static void end_unit(struct srcsax_context * context, const char * localname, const char * prefix, const char * URI) {

    srcsax_handler_test * test_handler = (srcsax_handler_test *)context->data;

    test_handler->end_unit_call_number = ++test_handler->call_count;

  }

  /**
   * end_element
   * @param context a srcSAX context
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   *
   * SAX handler function for end of an element.
   * Overidden for testing.  Count calls made and order.
   */
  static void end_element(struct srcsax_context * context, const char * localname, const char * prefix, const char * URI) {

    srcsax_handler_test * test_handler = (srcsax_handler_test *)context->data;

    test_handler->end_element_call_number = ++test_handler->call_count;

  }

  /**
   * characters_root
   * @param context a srcSAX context
   * @param ch the characers
   * @param len number of characters
   *
   * SAX handler function for character handling at the root level.
   * Overidden for testing.  Count calls made and order.
   */
  static void characters_root(struct srcsax_context * context, const char * ch, int len) {

    srcsax_handler_test * test_handler = (srcsax_handler_test *)context->data;

    test_handler->characters_root_call_number = ++test_handler->call_count;

  }

  /**
   * characters_unit
   * @param context a srcSAX context
   * @param ch the characers
   * @param len number of characters
   *
   * SAX handler function for character handling within a unit.
   * Overidden for testing.  Count calls made and order.
   */
  static void characters_unit(struct srcsax_context * context, const char * ch, int len) {

    srcsax_handler_test * test_handler = (srcsax_handler_test *)context->data;

    test_handler->characters_unit_call_number = ++test_handler->call_count;

  }

  /**
   * meta_tag
   * @param context a srcSAX context
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   * @param nb_namespaces number of namespaces definitions
   * @param namespaces the defined namespaces
   * @param nb_attributes the number of attributes on the tag
   * @param attributes list of attributes
   *
   * SAX handler function for meta tags.
   * Overidden for testing.  Count calls made and order.
   */
  static void meta_tag(struct srcsax_context * context, const char * localname, const char * prefix, const char * URI,
                         int nb_namespaces, const struct srcsax_namespace * namespaces, int nb_attributes,
                         const struct srcsax_attribute * attributes) {

    srcsax_handler_test * test_handler = (srcsax_handler_test *)context->data;

    assert(strcmp(context->srcml_element_stack[context->stack_size - 1], localname) == 0);

    test_handler->meta_tag_call_number = ++test_handler->call_count;

  }


  /**
   * comment
   * @param context a srcSAX context
   * @param value the comment content
   *
   * A comment has been parsed.
   * Overidden for testing.  Count calls made and order.
   */
  static void comment(struct srcsax_context * context, const char * value) {

    srcsax_handler_test * test_handler = (srcsax_handler_test *)context->data;

    test_handler->comment_call_number = ++test_handler->call_count;

  }

  /**
   * cdata_block
   * @param context a srcSAX context
   * @param value the pcdata content
   * @param len the block length
   *
   * Called when a pcdata block has been parsed.
   * Overidden for testing.  Count calls made and order.
   */
  static void cdata_block(struct srcsax_context * context, const char * value, int len) {

    srcsax_handler_test * test_handler = (srcsax_handler_test *)context->data;

    test_handler->cdata_block_call_number = ++test_handler->call_count;

  }

  /**
   * processing_instruction
   * @param context a srcSAX context
   * @param value the pcdata content
   * @param len the block length
   *
   * Called when a pcdata block has been parsed.
   * Overidden for testing.  Count calls made and order.
   */
  static void processing_instruction(struct srcsax_context * context, const char * target, const char * data) {

    srcsax_handler_test * test_handler = (srcsax_handler_test *)context->data;

    test_handler->processing_instruction_call_number = ++test_handler->call_count;

  }

#pragma GCC diagnostic pop

};

#endif
