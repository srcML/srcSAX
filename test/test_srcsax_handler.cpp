/**
 * @file test_srcsax_test_handler.cpp
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

#include <srcsax_handler_test.hpp>
#include <sax2_srcsax_handler.hpp>

#include <stdio.h>
#include <string.h>
#include <cassert>

/** default initialization used throughout for testing */
sax2_srcsax_handler sax2_handler_init;

/** default initialization used throughout for testing */
xmlParserCtxt ctxt_init;

/**
 * main
 *
 * Test the sax2_srcsax_handler/srcsax_test_handler.
 *
 * @returns 0 on success.
 */
 int main() {

  /*
    start_document
  */
  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    start_document(&ctxt);
    assert(test_handler.start_document_call_number == 1);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.start_document = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    start_document(&ctxt);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  /*
    end_document
  */
  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    end_document(&ctxt);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 1);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.mode = END_UNIT;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    end_document(&ctxt);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 2);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 1);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }
  
  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.end_document = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    end_document(&ctxt);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.end_root = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.mode = END_UNIT;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    end_document(&ctxt);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 1);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.end_document = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.mode = END_UNIT;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    end_document(&ctxt);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 1);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  /*
    start_root
  */
  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { 0, "http://www.srcML.org/srcML/src", "cpp", "http://www.srcML.org/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.srcML.org/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.srcML.org/srcML/src", values + 1, values + 2,
                                    "language", 0, "http://www.srcML.org/srcML/src", values + 2, values + 3 };
    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);
    end_document(&ctxt);

  }
  
  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.start_document = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    start_document(&ctxt);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  /*
    start_element_ns_first
  */
  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { 0, "http://www.srcML.org/srcML/src", "cpp", "http://www.srcML.org/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.srcML.org/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.srcML.org/srcML/src", values + 1, values + 2,
                                    "language", 0, "http://www.srcML.org/srcML/src", values + 2, values + 3 };

    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    start_element_ns_first(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 1);
    assert(test_handler.start_unit_call_number == 3);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 2);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);
    end_document(&ctxt);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { 0, "http://www.srcML.org/srcML/src", "cpp", "http://www.srcML.org/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.srcML.org/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.srcML.org/srcML/src", values + 1, values + 2,
                                    "language", 0, "http://www.srcML.org/srcML/src", values + 2, values + 3 };

    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    start_element_ns_first(&ctxt, (const xmlChar *)"name", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 1);
    assert(test_handler.start_unit_call_number == 2);
    assert(test_handler.start_element_call_number == 3);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);
    end_document(&ctxt);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.start_root = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { 0, "http://www.srcML.org/srcML/src", "cpp", "http://www.srcML.org/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.srcML.org/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.srcML.org/srcML/src", values + 1, values + 2,
                                    "language", 0, "http://www.srcML.org/srcML/src", values + 2, values + 3 };

    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    start_element_ns_first(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 2);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 1);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);
    end_document(&ctxt);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.start_unit = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { 0, "http://www.srcML.org/srcML/src", "cpp", "http://www.srcML.org/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.srcML.org/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.srcML.org/srcML/src", values + 1, values + 2,
                                    "language", 0, "http://www.srcML.org/srcML/src", values + 2, values + 3 };

    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    start_element_ns_first(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 1);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 2);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);
    end_document(&ctxt);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.characters_root = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { 0, "http://www.srcML.org/srcML/src", "cpp", "http://www.srcML.org/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.srcML.org/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.srcML.org/srcML/src", values + 1, values + 2,
                                    "language", 0, "http://www.srcML.org/srcML/src", values + 2, values + 3 };

    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    start_element_ns_first(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 1);
    assert(test_handler.start_unit_call_number == 2);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);
    end_document(&ctxt);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.start_root = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { 0, "http://www.srcML.org/srcML/src", "cpp", "http://www.srcML.org/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.srcML.org/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.srcML.org/srcML/src", values + 1, values + 2,
                                    "language", 0, "http://www.srcML.org/srcML/src", values + 2, values + 3 };

    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    start_element_ns_first(&ctxt, (const xmlChar *)"name", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 1);
    assert(test_handler.start_element_call_number == 2);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);
    end_document(&ctxt);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.start_unit = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { 0, "http://www.srcML.org/srcML/src", "cpp", "http://www.srcML.org/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.srcML.org/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.srcML.org/srcML/src", values + 1, values + 2,
                                    "language", 0, "http://www.srcML.org/srcML/src", values + 2, values + 3 };

    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    start_element_ns_first(&ctxt, (const xmlChar *)"name", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 1);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 2);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);
    end_document(&ctxt);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.characters_unit = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { 0, "http://www.srcML.org/srcML/src", "cpp", "http://www.srcML.org/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.srcML.org/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.srcML.org/srcML/src", values + 1, values + 2,
                                    "language", 0, "http://www.srcML.org/srcML/src", values + 2, values + 3 };

    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    start_element_ns_first(&ctxt, (const xmlChar *)"name", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 1);
    assert(test_handler.start_unit_call_number == 2);
    assert(test_handler.start_element_call_number == 3);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);
    end_document(&ctxt);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.start_element = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { 0, "http://www.srcML.org/srcML/src", "cpp", "http://www.srcML.org/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.srcML.org/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.srcML.org/srcML/src", values + 1, values + 2,
                                    "language", 0, "http://www.srcML.org/srcML/src", values + 2, values + 3 };

    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    start_element_ns_first(&ctxt, (const xmlChar *)"name", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 1);
    assert(test_handler.start_unit_call_number == 2);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);
    end_document(&ctxt);

  }

  /*
    start_unit
  */
  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { 0, "http://www.srcML.org/srcML/src", "cpp", "http://www.srcML.org/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.srcML.org/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.srcML.org/srcML/src", values + 1, values + 2,
                                    "language", 0, "http://www.srcML.org/srcML/src", values + 2, values + 3 };

    start_unit(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 1);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);
    end_document(&ctxt);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.start_unit = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { 0, "http://www.srcML.org/srcML/src", "cpp", "http://www.srcML.org/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.srcML.org/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.srcML.org/srcML/src", values + 1, values + 2,
                                    "language", 0, "http://www.srcML.org/srcML/src", values + 2, values + 3 };

    start_unit(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);
    end_document(&ctxt);

  }

  /*
    start_element_ns
  */
  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { 0, "http://www.srcML.org/srcML/src", "cpp", "http://www.srcML.org/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.srcML.org/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.srcML.org/srcML/src", values + 1, values + 2,
                                    "language", 0, "http://www.srcML.org/srcML/src", values + 2, values + 3 };

    start_element_ns(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
                   (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
                   (const xmlChar **) attributes);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 1);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.start_element = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { 0, "http://www.srcML.org/srcML/src", "cpp", "http://www.srcML.org/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.srcML.org/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.srcML.org/srcML/src", values + 1, values + 2,
                                    "language", 0, "http://www.srcML.org/srcML/src", values + 2, values + 3 };

    start_element_ns(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
                   (const xmlChar *)"http://www.srcML.org/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
                   (const xmlChar **) attributes);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  /*
    end_element_ns
  */
  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    sax.startElementNs = &start_unit;
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    end_element_ns(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
                 (const xmlChar *)"http://www.srcML.org/srcML/src");
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 1);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    end_element_ns(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
                 (const xmlChar *)"http://www.srcML.org/srcML/src");
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 1);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    end_element_ns(&ctxt, (const xmlChar *)"name", (const xmlChar *)0,
                 (const xmlChar *)"http://www.srcML.org/srcML/src");
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 1);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.end_root = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    sax.startElementNs = &start_unit;
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    end_element_ns(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
                 (const xmlChar *)"http://www.srcML.org/srcML/src");
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.end_unit = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    end_element_ns(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
                 (const xmlChar *)"http://www.srcML.org/srcML/src");
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.end_element = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    end_element_ns(&ctxt, (const xmlChar *)"name", (const xmlChar *)0,
                 (const xmlChar *)"http://www.srcML.org/srcML/src");
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  /*
    characters_root
  */
  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    characters_root(&ctxt, (const xmlChar *)"unit", 4);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 1);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.characters_root = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    characters_root(&ctxt, (const xmlChar *)"unit", 4);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  /*
    characters_unit
  */
  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    characters_unit(&ctxt, (const xmlChar *)"unit", 4);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 1);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.characters_unit = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    characters_unit(&ctxt, (const xmlChar *)"unit", 4);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  /*
    meta_tag
  */
  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    sax.startElementNs = start_element_ns_first;
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char ** namespaces = 0;
    const char * values = "ab";
    const char * attributes[10] = { "token", 0, "http://www.srcML.org/srcML/src", values, values + 1,
                                    "type", 0, "http://www.srcML.org/srcML/src", values + 1, values + 2 };

    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 0, (const xmlChar **)namespaces, 2, 0,
              (const xmlChar **) attributes);
    start_element_ns_first(&ctxt, (const xmlChar *)"macro-list", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 0, (const xmlChar **)namespaces, 2, 0,
              (const xmlChar **) attributes);
    start_element_ns_first(&ctxt, (const xmlChar *)"expr_stmt", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 0, (const xmlChar **)namespaces, 2, 0,
              (const xmlChar **) attributes);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 1);
    assert(test_handler.start_unit_call_number == 3);
    assert(test_handler.start_element_call_number == 4);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 2);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);
    end_document(&ctxt);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    sax.startElementNs = start_element_ns_first;
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char ** namespaces = 0;
    const char * values = "ab";
    const char * attributes[10] = { "token", 0, "http://www.srcML.org/srcML/src", values, values + 1,
                                    "type", 0, "http://www.srcML.org/srcML/src", values + 1, values + 2 };

    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 0, (const xmlChar **)namespaces, 2, 0,
              (const xmlChar **) attributes);
    start_element_ns_first(&ctxt, (const xmlChar *)"macro-list", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 0, (const xmlChar **)namespaces, 2, 0,
              (const xmlChar **) attributes);
    start_element_ns_first(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 0, (const xmlChar **)namespaces, 2, 0,
              (const xmlChar **) attributes);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 1);
    assert(test_handler.start_unit_call_number == 4);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 3);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 2);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);
    end_document(&ctxt);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.meta_tag = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    sax.startElementNs = start_element_ns_first;
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char ** namespaces = 0;
    const char * values = "ab";
    const char * attributes[10] = { "token", 0, "http://www.srcML.org/srcML/src", values, values + 1,
                                    "type", 0, "http://www.srcML.org/srcML/src", values + 1, values + 2 };

    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 0, (const xmlChar **)namespaces, 2, 0,
              (const xmlChar **) attributes);
    start_element_ns_first(&ctxt, (const xmlChar *)"macro-list", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 0, (const xmlChar **)namespaces, 2, 0,
              (const xmlChar **) attributes);
    start_element_ns_first(&ctxt, (const xmlChar *)"expr_stmt", (const xmlChar *)0,
              (const xmlChar *)"http://www.srcML.org/srcML/src", 0, (const xmlChar **)namespaces, 2, 0,
              (const xmlChar **) attributes);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 1);
    assert(test_handler.start_unit_call_number == 2);
    assert(test_handler.start_element_call_number == 3);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);
    end_document(&ctxt);

  }

  /*
    comment
  */
  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    comment(&ctxt, (const xmlChar *)"unit");
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 1);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.comment = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    comment(&ctxt, (const xmlChar *)"unit");
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  /*
    cdata_block
  */
  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    cdata_block(&ctxt, (const xmlChar *)"unit", 4);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 1);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.cdata_block = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    cdata_block(&ctxt, (const xmlChar *)"unit", 4);
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  /*
    processing_instruction
  */
  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    processing_instruction(&ctxt, (const xmlChar *)"target", (const xmlChar *)"data");
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 1);

  }

  {

    srcsax_handler_test test_handler;
    srcsax_handler srcsax_sax = srcsax_handler_test::factory();
    srcsax_sax.processing_instruction = 0;

    srcsax_context context = {};
    context.data = &test_handler;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    processing_instruction(&ctxt, (const xmlChar *)"target", (const xmlChar *)"data");
    assert(test_handler.start_document_call_number == 0);
    assert(test_handler.end_document_call_number == 0);
    assert(test_handler.start_root_call_number == 0);
    assert(test_handler.start_unit_call_number == 0);
    assert(test_handler.start_element_call_number == 0);
    assert(test_handler.end_root_call_number == 0);
    assert(test_handler.end_unit_call_number == 0);
    assert(test_handler.end_element_call_number == 0);
    assert(test_handler.characters_root_call_number == 0);
    assert(test_handler.characters_unit_call_number == 0);
    assert(test_handler.meta_tag_call_number == 0);
    assert(test_handler.comment_call_number == 0);
    assert(test_handler.cdata_block_call_number == 0);
    assert(test_handler.processing_instruction_call_number == 0);

  }

  return 0;

}
