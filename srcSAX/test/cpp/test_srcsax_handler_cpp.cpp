/**
 * @file test_srcsax_control_handler.cpp
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

#include <sax2_srcsax_handler.hpp>
#include <srcsax_handler_test.hpp>
#include <cppCallbackAdapter.hpp>

#include <srcsax.h>

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
 * Test the srcsax functions.
 *
 * @returns 0 on success.
 */
int main() {


  /**
    srcml_element_stack
   */
  {

    srcSAXHandler handler;
    cppCallbackAdapter cpp_adapter(&handler);
    srcsax_handler srcsax_sax = cppCallbackAdapter::factory();

    srcsax_context context;
    context.data = &cpp_adapter;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;

    start_document(&ctxt);
    assert(handler.get_stack().size() == 0);

    const char * namespaces[4] = { 0, "http://www.sdml.info/srcML/src", "cpp", "http://www.sdml.info/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.sdml.info/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.sdml.info/srcML/src", values + 1, values + 2,
                                   "language", 0, "http://www.sdml.info/srcML/src", values + 2, values + 3 };
    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

    assert(handler.get_stack().size() == 0);

    start_element_ns_first(&ctxt, (const xmlChar *)"expr_stmt", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

    assert(handler.get_stack().size() == 2);
    assert(handler.get_stack().front() == "unit");
    assert(handler.get_stack().back() == "expr_stmt");

    start_unit(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

    assert(handler.get_stack().size() == 3);
    assert(handler.get_stack().back() == "unit");

    end_element_ns(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src");

    assert(handler.get_stack().size() == 2);
    assert(handler.get_stack().back() == "expr_stmt");

    start_unit(&ctxt, (const xmlChar *)"decl_stmt", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

    assert(handler.get_stack().size() == 3);
    assert(handler.get_stack().back() == "decl_stmt");

    start_unit(&ctxt, (const xmlChar *)"if", (const xmlChar *)"cpp",
              (const xmlChar *)"http://www.sdml.info/srcML/cpp", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

    assert(handler.get_stack().size() == 4);
    assert(handler.get_stack().back() == "cpp:if");

    end_element_ns(&ctxt, (const xmlChar *)"if", (const xmlChar *)"cpp",
              (const xmlChar *)"http://www.sdml.info/srcML/cpp");

    assert(handler.get_stack().size() == 3);
    assert(handler.get_stack().back() == "decl_stmt");

    end_element_ns(&ctxt, (const xmlChar *)"decl_stmt", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src");

    assert(handler.get_stack().size() == 2);
    assert(handler.get_stack().back() == "expr_stmt");

    end_element_ns(&ctxt, (const xmlChar *)"expr_stmt", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src");

    assert(handler.get_stack().size() == 1);
    assert(handler.get_stack().back() == "unit");

    end_element_ns(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src");

    assert(handler.get_stack().size() == 0);

    end_document(&ctxt);

    assert(handler.get_stack().size() == 0);

  }

  {

    srcSAXHandler handler;
    cppCallbackAdapter cpp_adapter(&handler);
    srcsax_handler srcsax_sax = cppCallbackAdapter::factory();

    srcsax_context context;
    context.data = &cpp_adapter;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;

    start_document(&ctxt);
    assert(handler.get_stack().size() == 0);

    const char * namespaces[4] = { 0, "http://www.sdml.info/srcML/src", "cpp", "http://www.sdml.info/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.sdml.info/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.sdml.info/srcML/src", values + 1, values + 2,
                                   "language", 0, "http://www.sdml.info/srcML/src", values + 2, values + 3 };
    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

    assert(handler.get_stack().size() == 0);

    start_element_ns_first(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

    assert(handler.get_stack().size() == 2);
    assert(handler.get_stack().front() == "unit");
    assert(handler.get_stack().back() == "unit");

    end_element_ns(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src");

    assert(handler.get_stack().size() == 1);
    assert(handler.get_stack().back() == "unit");

    end_element_ns(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src");

    assert(handler.get_stack().size() == 0);

    end_document(&ctxt);

    assert(handler.get_stack().size() == 0);

  }

  {

    srcSAXHandler handler;
    cppCallbackAdapter cpp_adapter(&handler);
    srcsax_handler srcsax_sax = cppCallbackAdapter::factory();

    srcsax_context context;
    context.data = &cpp_adapter;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;

    start_document(&ctxt);
    assert(handler.get_stack().size() == 0);

    const char * namespaces[4] = { 0, "http://www.sdml.info/srcML/src", "cpp", "http://www.sdml.info/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.sdml.info/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.sdml.info/srcML/src", values + 1, values + 2,
                                   "language", 0, "http://www.sdml.info/srcML/src", values + 2, values + 3 };
    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

    assert(handler.get_stack().size() == 0);

    start_element_ns_first(&ctxt, (const xmlChar *)"macro-list", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

    assert(handler.get_stack().size() == 0);

    end_element_ns(&ctxt, (const xmlChar *)"macro-list", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src");

    assert(handler.get_stack().size() == 0);

    start_element_ns_first(&ctxt, (const xmlChar *)"expr_stmt", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

    assert(handler.get_stack().size() == 2);
    assert(handler.get_stack().front() == "unit");
    assert(handler.get_stack().back() == "expr_stmt");

    end_element_ns(&ctxt, (const xmlChar *)"expr_stmt", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src");

    assert(handler.get_stack().size() == 1);
    assert(handler.get_stack().back() == "unit");

    end_element_ns(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src");

    assert(handler.get_stack().size() == 0);

    end_document(&ctxt);

    assert(handler.get_stack().size() == 0);

  }

  {

    srcSAXHandler handler;
    cppCallbackAdapter cpp_adapter(&handler);
    srcsax_handler srcsax_sax = cppCallbackAdapter::factory();

    srcsax_context context;
    context.data = &cpp_adapter;
    context.handler = &srcsax_sax;

    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.context = &context;

    xmlParserCtxt ctxt = ctxt_init;
    xmlSAXHandler sax = srcsax_sax2_factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;

    start_document(&ctxt);
    assert(handler.get_stack().size() == 0);

    const char * namespaces[4] = { 0, "http://www.sdml.info/srcML/src", "cpp", "http://www.sdml.info/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", 0, "http://www.sdml.info/srcML/src", values, values + 1,
                                    "dir", 0, "http://www.sdml.info/srcML/src", values + 1, values + 2,
                                   "language", 0, "http://www.sdml.info/srcML/src", values + 2, values + 3 };
    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

    assert(handler.get_stack().size() == 0);

    start_element_ns_first(&ctxt, (const xmlChar *)"macro-list", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

    assert(handler.get_stack().size() == 0);

    end_element_ns(&ctxt, (const xmlChar *)"macro-list", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src");

    assert(handler.get_stack().size() == 0);

    end_element_ns(&ctxt, (const xmlChar *)"unit", (const xmlChar *)0,
              (const xmlChar *)"http://www.sdml.info/srcML/src");

    assert(handler.get_stack().size() == 0);

    end_document(&ctxt);

    assert(handler.get_stack().size() == 0);

  }

  return 0;
}
