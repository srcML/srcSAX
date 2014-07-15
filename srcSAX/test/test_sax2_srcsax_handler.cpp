/**
 * @file test_sax2_srcsax_handler.cpp
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

#include <srcsax.h>

#include <stdio.h>
#include <string.h>
#include <cassert>

sax2_srcsax_handler sax2_handler_init;


int main() {

  /*
    start_document
   */
  {

    srcsax_handler_test test_handler;
    srcsax_handler sax = srcsax_handler_test::factory();

    srcsax_context context;
    context.data = &test_handler;
    context.handler = &sax;

    start_document(&context);

  }

  {

    start_document(NULL);

  }
#if 0
  /*
    end_document
   */
  {

    srcSAXHandler handler;
    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    end_document(&ctxt);

  }

  {

    end_document(NULL);

  }

  /*
    start_root
   */
  {

    srcSAXHandler handler;
    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { "src", "http://www.sdml.info/srcML/src", "cpp", "http://www.sdml.info/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", "src", "http://www.sdml.info/srcML/src", values, values + 1,
                                    "dir", "src", "http://www.sdml.info/srcML/src", values + 1, values + 2,
                                   "language", "src", "http://www.sdml.info/srcML/src", values + 2, values + 3 };
    start_root(&ctxt, (const xmlChar *)"unit", (const xmlChar *)"src", 
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

    assert((const char *)sax2_handler.root.localname == std::string("unit"));
    assert((const char *)sax2_handler.root.prefix == std::string("src"));
    assert((const char *)sax2_handler.root.URI == std::string("http://www.sdml.info/srcML/src"));
    assert(sax2_handler.root.nb_namespaces == 2);
    assert((const char *)sax2_handler.root.namespaces[0] == std::string("src"));
    assert((const char *)sax2_handler.root.namespaces[1] == std::string("http://www.sdml.info/srcML/src"));
    assert((const char *)sax2_handler.root.namespaces[2] == std::string("cpp"));
    assert((const char *)sax2_handler.root.namespaces[3] == std::string("http://www.sdml.info/srcML/cpp"));
    assert(sax2_handler.root.nb_attributes == 3);
    assert(sax2_handler.root.nb_defaulted == 0);
    assert((const char *)sax2_handler.root.attributes[0] == std::string("filename"));
    assert((const char *)sax2_handler.root.attributes[1] == std::string("src"));
    assert((const char *)sax2_handler.root.attributes[2] == std::string("http://www.sdml.info/srcML/src"));
    assert(sax2_handler.root.attributes[4] - sax2_handler.root.attributes[3] == 1);
    assert((char)sax2_handler.root.attributes[3][0] == 'a');
    assert((const char *)sax2_handler.root.attributes[5] == std::string("dir"));
    assert((const char *)sax2_handler.root.attributes[6] == std::string("src"));
    assert((const char *)sax2_handler.root.attributes[7] == std::string("http://www.sdml.info/srcML/src"));
    assert(sax2_handler.root.attributes[9] - sax2_handler.root.attributes[8] == 1);
    assert((char)sax2_handler.root.attributes[8][0] == 'b');
    assert((const char *)sax2_handler.root.attributes[10] == std::string("language"));
    assert((const char *)sax2_handler.root.attributes[11] == std::string("src"));
    assert((const char *)sax2_handler.root.attributes[12] == std::string("http://www.sdml.info/srcML/src"));
    assert(sax2_handler.root.attributes[14] - sax2_handler.root.attributes[13] == 1);
    assert((char)sax2_handler.root.attributes[13][0] == 'c');
    assert(ctxt.sax->start_document == start_document);
    assert(ctxt.sax->end_document == end_document);
    assert(ctxt.sax->start_element_ns == start_element_ns_first);
    assert(ctxt.sax->end_element_ns == end_element_ns);
    assert(ctxt.sax->characters == characters_first);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdata_block == cdata_block);
    end_document(&ctxt);

  }

  {

    const char * namespaces[4] = { "src", "http://www.sdml.info/srcML/src", "cpp", "http://www.sdml.info/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", "src", "http://www.sdml.info/srcML/src", values, values + 1,
                                    "dir", "src", "http://www.sdml.info/srcML/src", values + 1, values + 2,
                                    "language", "src", "http://www.sdml.info/srcML/src", values + 2, values + 3 };
    start_root(NULL, (const xmlChar *)"unit", (const xmlChar *)"src",
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

  }


  /*
    start_element_ns_first
   */
  {

    srcSAXHandler handler;
    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { "src", "http://www.sdml.info/srcML/src", "cpp", "http://www.sdml.info/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", "src", "http://www.sdml.info/srcML/src", values, values + 1,
                                    "dir", "src", "http://www.sdml.info/srcML/src", values + 1, values + 2,
                                   "language", "src", "http://www.sdml.info/srcML/src", values + 2, values + 3 };

    start_element_ns_first(&ctxt, (const xmlChar *)"unit", (const xmlChar *)"src", 
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(ctxt.sax->start_document == start_document);
    assert(ctxt.sax->end_document == end_document);
    assert(ctxt.sax->start_element_ns == start_element_ns);
    assert(ctxt.sax->end_element_ns == end_element_ns);
    assert(ctxt.sax->characters == characters_unit);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdata_block == cdata_block);

  }

  {
    const char * namespaces[4] = { "src", "http://www.sdml.info/srcML/src", "cpp", "http://www.sdml.info/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", "src", "http://www.sdml.info/srcML/src", values, values + 1,
                                    "dir", "src", "http://www.sdml.info/srcML/src", values + 1, values + 2,
                                    "language", "src", "http://www.sdml.info/srcML/src", values + 2, values + 3 };
    start_element_ns_first(NULL, (const xmlChar *)"unit", (const xmlChar *)"src",
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

  }

  /*
    start_unit
   */
  {

    srcSAXHandler handler;
    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { "src", "http://www.sdml.info/srcML/src", "cpp", "http://www.sdml.info/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", "src", "http://www.sdml.info/srcML/src", values, values + 1,
                                    "dir", "src", "http://www.sdml.info/srcML/src", values + 1, values + 2,
                                   "language", "src", "http://www.sdml.info/srcML/src", values + 2, values + 3 };

    start_unit(&ctxt, (const xmlChar *)"unit", (const xmlChar *)"src", 
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(ctxt.sax->start_document == start_document);
    assert(ctxt.sax->end_document == end_document);
    assert(ctxt.sax->start_element_ns == start_element_ns);
    assert(ctxt.sax->end_element_ns == end_element_ns);
    assert(ctxt.sax->characters == characters_unit);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdata_block == cdata_block);

  }

  {

    const char * namespaces[4] = { "src", "http://www.sdml.info/srcML/src", "cpp", "http://www.sdml.info/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", "src", "http://www.sdml.info/srcML/src", values, values + 1,
                                    "dir", "src", "http://www.sdml.info/srcML/src", values + 1, values + 2,
                                    "language", "src", "http://www.sdml.info/srcML/src", values + 2, values + 3 };
    start_unit(NULL, (const xmlChar *)"unit", (const xmlChar *)"src",
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

  }

  /*
    start_element_ns
   */
  {

    srcSAXHandler handler;
    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    const char * namespaces[4] = { "src", "http://www.sdml.info/srcML/src", "cpp", "http://www.sdml.info/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", "src", "http://www.sdml.info/srcML/src", values, values + 1,
                                    "dir", "src", "http://www.sdml.info/srcML/src", values + 1, values + 2,
                                   "language", "src", "http://www.sdml.info/srcML/src", values + 2, values + 3 };

    start_element_ns(&ctxt, (const xmlChar *)"unit", (const xmlChar *)"src", 
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(ctxt.sax->start_document == start_document);
    assert(ctxt.sax->end_document == end_document);
    assert(ctxt.sax->start_element_ns == start_root);
    assert(ctxt.sax->end_element_ns == end_element_ns);
    assert(ctxt.sax->characters == characters_first);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdata_block == cdata_block);

  }

  {
    const char * namespaces[4] = { "src", "http://www.sdml.info/srcML/src", "cpp", "http://www.sdml.info/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", "src", "http://www.sdml.info/srcML/src", values, values + 1,
                                    "dir", "src", "http://www.sdml.info/srcML/src", values + 1, values + 2,
                                    "language", "src", "http://www.sdml.info/srcML/src", values + 2, values + 3 };
    start_element_ns(NULL, (const xmlChar *)"unit", (const xmlChar *)"src",
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

  }

  /*
    end_element_ns
   */
  {

    srcSAXHandler handler;
    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    end_element_ns(&ctxt, (const xmlChar *)"unit", (const xmlChar *)"src", 
                   (const xmlChar *)"http://www.sdml.info/srcML/src");
    assert(ctxt.sax->start_document == start_document);
    assert(ctxt.sax->end_document == end_document);
    assert(ctxt.sax->start_element_ns == start_unit);
    assert(ctxt.sax->end_element_ns == end_element_ns);
    assert(ctxt.sax->characters == characters_root);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdata_block == cdata_block);

  }

  {

    srcSAXHandler handler;
    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    sax.start_element_ns = &start_unit;
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    end_element_ns(&ctxt, (const xmlChar *)"unit", (const xmlChar *)"src", 
                   (const xmlChar *)"http://www.sdml.info/srcML/src");
    assert(ctxt.sax->start_document == start_document);
    assert(ctxt.sax->end_document == end_document);
    assert(ctxt.sax->start_element_ns == 0);
    assert(ctxt.sax->end_element_ns == end_element_ns);
    assert(ctxt.sax->characters == characters_first);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdata_block == cdata_block);

  }

  {

    srcSAXHandler handler;
    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    end_element_ns(&ctxt, (const xmlChar *)"name", (const xmlChar *)"src", 
                   (const xmlChar *)"http://www.sdml.info/srcML/src");
    assert(ctxt.sax->start_document == start_document);
    assert(ctxt.sax->end_document == end_document);
    assert(ctxt.sax->start_element_ns == start_root);
    assert(ctxt.sax->end_element_ns == end_element_ns);
    assert(ctxt.sax->characters == characters_first);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdata_block == cdata_block);

  }

  {

    end_element_ns(NULL, (const xmlChar *)"unit", (const xmlChar *)"src",
                 (const xmlChar *)"http://www.sdml.info/srcML/src");
  }

  /*
    characters_first
   */
  {

    srcSAXHandler handler;
    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    characters_first(&ctxt, (const xmlChar *)"unit", 4);
    assert(sax2_handler.root.characters == "unit");
    assert(ctxt.sax->start_document == start_document);
    assert(ctxt.sax->end_document == end_document);
    assert(ctxt.sax->start_element_ns == start_root);
    assert(ctxt.sax->end_element_ns == end_element_ns);
    assert(ctxt.sax->characters == characters_first);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdata_block == cdata_block);

  }

  {

    characters_first(NULL, (const xmlChar *)"unit", 4);

  }

  /*
    characters_root
   */
  {

    srcSAXHandler handler;
    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    characters_root(&ctxt, (const xmlChar *)"unit", 4);
    assert(ctxt.sax->start_document == start_document);
    assert(ctxt.sax->end_document == end_document);
    assert(ctxt.sax->start_element_ns == start_root);
    assert(ctxt.sax->end_element_ns == end_element_ns);
    assert(ctxt.sax->characters == characters_first);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdata_block == cdata_block);
  }

  {

    characters_root(NULL, (const xmlChar *)"unit", 4);

  }

  /*
    characters_unit
   */
  {

    srcSAXHandler handler;
    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    characters_unit(&ctxt, (const xmlChar *)"unit", 4);
    assert(ctxt.sax->start_document == start_document);
    assert(ctxt.sax->end_document == end_document);
    assert(ctxt.sax->start_element_ns == start_root);
    assert(ctxt.sax->end_element_ns == end_element_ns);
    assert(ctxt.sax->characters == characters_first);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdata_block == cdata_block);
  }

  {

    characters_unit(NULL, (const xmlChar *)"unit", 4);

  }

  /*
    comment
   */
  {

    srcSAXHandler handler;
    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    comment(&ctxt, (const xmlChar *)"unit");
    assert(ctxt.sax->start_document == start_document);
    assert(ctxt.sax->end_document == end_document);
    assert(ctxt.sax->start_element_ns == start_root);
    assert(ctxt.sax->end_element_ns == end_element_ns);
    assert(ctxt.sax->characters == characters_first);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdata_block == cdata_block);
  }

  {

    comment(NULL, (const xmlChar *)"unit");

  }

  /*
    cdata_block
   */
  {

    srcSAXHandler handler;
    sax2_srcsax_handler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    cdata_block(&ctxt, (const xmlChar *)"unit", 4);
    assert(ctxt.sax->start_document == start_document);
    assert(ctxt.sax->end_document == end_document);
    assert(ctxt.sax->start_element_ns == start_root);
    assert(ctxt.sax->end_element_ns == end_element_ns);
    assert(ctxt.sax->characters == characters_first);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdata_block == cdata_block);
  }

  {

    cdata_block(NULL, (const xmlChar *)"unit", 4);

  }
#endif
  return 0;
}
