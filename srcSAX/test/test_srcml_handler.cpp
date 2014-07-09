/**
 * @file test_srcml_handler.cpp
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

#include <srcMLHandlerTest.hpp>
#include <SAX2srcSAXHandler.hpp>

#include <stdio.h>
#include <string.h>
#include <cassert>

int main() {

  /*
    startDocument
  */
  {

    srcMLHandlerTest handler;
    SAX2srcSAXHandler sax2_handler;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    startDocument(&ctxt);
    assert(handler.start_document == 1);
    assert(handler.end_document == 0);
    assert(handler.start_root == 0);
    assert(handler.start_unit == 0);
    assert(handler.start_element_ns == 0);
    assert(handler.end_root == 0);
    assert(handler.end_unit == 0);
    assert(handler.end_element_ns == 0);
    assert(handler.characters_root == 0);
    assert(handler.characters_unit == 0);
    assert(handler.comment_ == 0);
    assert(handler.cdata_block == 0);

  }

  /*
    endDocument
  */
  {

    srcMLHandlerTest handler;
    SAX2srcSAXHandler sax2_handler;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    endDocument(&ctxt);
    assert(handler.start_document == 0);
    assert(handler.end_document == 2);
    assert(handler.start_root == 0);
    assert(handler.start_unit == 0);
    assert(handler.start_element_ns == 0);
    assert(handler.end_root == 1);
    assert(handler.end_unit == 0);
    assert(handler.end_element_ns == 0);
    assert(handler.characters_root == 0);
    assert(handler.characters_unit == 0);
    assert(handler.comment_ == 0);
    assert(handler.cdata_block == 0);

  }

  {

    srcMLHandlerTest handler;
    SAX2srcSAXHandler sax2_handler;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    sax.startElementNs = 0;
    ctxt._private = &sax2_handler;
    endDocument(&ctxt);
    assert(handler.start_document == 0);
    assert(handler.end_document == 1);
    assert(handler.start_root == 0);
    assert(handler.start_unit == 0);
    assert(handler.start_element_ns == 0);
    assert(handler.end_root == 0);
    assert(handler.end_unit == 0);
    assert(handler.end_element_ns == 0);
    assert(handler.characters_root == 0);
    assert(handler.characters_unit == 0);
    assert(handler.comment_ == 0);
    assert(handler.cdata_block == 0);

  }

  /*
    startRoot
  */
  {

    srcMLHandlerTest handler;
    SAX2srcSAXHandler sax2_handler;
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
    startRoot(&ctxt, (const xmlChar *)"unit", (const xmlChar *)"src",
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(handler.start_document == 0);
    assert(handler.end_document == 0);
    assert(handler.start_root == 1);
    assert(handler.start_unit == 0);
    assert(handler.start_element_ns == 0);
    assert(handler.end_root == 0);
    assert(handler.end_unit == 0);
    assert(handler.end_element_ns == 0);
    assert(handler.characters_root == 0);
    assert(handler.characters_unit == 0);
    assert(handler.comment_ == 0);
    assert(handler.cdata_block == 0);
    endDocument(&ctxt);

  }

  /*
    startElementNsFirst
  */
  {

    srcMLHandlerTest handler;
    SAX2srcSAXHandler sax2_handler;
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

    startElementNsFirst(&ctxt, (const xmlChar *)"unit", (const xmlChar *)"src",
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(handler.start_document == 0);
    assert(handler.end_document == 0);
    assert(handler.start_root == 0);
    assert(handler.start_unit == 2);
    assert(handler.start_element_ns == 0);
    assert(handler.end_root == 0);
    assert(handler.end_unit == 0);
    assert(handler.end_element_ns == 0);
    assert(handler.characters_root == 1);
    assert(handler.characters_unit == 0);
    assert(handler.comment_ == 0);
    assert(handler.cdata_block == 0);
    endDocument(&ctxt);

  }

  {

    srcMLHandlerTest handler;
    SAX2srcSAXHandler sax2_handler;
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

    startElementNsFirst(&ctxt, (const xmlChar *)"name", (const xmlChar *)"src",
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(handler.start_document == 0);
    assert(handler.end_document == 0);
    assert(handler.start_root == 0);
    assert(handler.start_unit == 1);
    assert(handler.start_element_ns == 3);
    assert(handler.end_root == 0);
    assert(handler.end_unit == 0);
    assert(handler.end_element_ns == 0);
    assert(handler.characters_root == 0);
    assert(handler.characters_unit == 2);
    assert(handler.comment_ == 0);
    assert(handler.cdata_block == 0);
    endDocument(&ctxt);

  }

  /*
    startUnit
  */
  {

    srcMLHandlerTest handler;
    SAX2srcSAXHandler sax2_handler;
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

    startUnit(&ctxt, (const xmlChar *)"unit", (const xmlChar *)"src",
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);
    assert(handler.start_document == 0);
    assert(handler.end_document == 0);
    assert(handler.start_root == 0);
    assert(handler.start_unit == 1);
    assert(handler.start_element_ns == 0);
    assert(handler.end_root == 0);
    assert(handler.end_unit == 0);
    assert(handler.end_element_ns == 0);
    assert(handler.characters_root == 0);
    assert(handler.characters_unit == 0);
    assert(handler.comment_ == 0);
    assert(handler.cdata_block == 0);
    endDocument(&ctxt);

  }

  /*
    startElementNs
  */
  {

    srcMLHandlerTest handler;
    SAX2srcSAXHandler sax2_handler;
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

    startElementNs(&ctxt, (const xmlChar *)"unit", (const xmlChar *)"src",
                   (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
                   (const xmlChar **) attributes);
    assert(handler.start_document == 0);
    assert(handler.end_document == 0);
    assert(handler.start_root == 0);
    assert(handler.start_unit == 0);
    assert(handler.start_element_ns == 1);
    assert(handler.end_root == 0);
    assert(handler.end_unit == 0);
    assert(handler.end_element_ns == 0);
    assert(handler.characters_root == 0);
    assert(handler.characters_unit == 0);
    assert(handler.comment_ == 0);
    assert(handler.cdata_block == 0);

  }


  /*
    endElementNs
  */
  {

    srcMLHandlerTest handler;
    SAX2srcSAXHandler sax2_handler;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    sax.startElementNs = startUnit;
    ctxt._private = &sax2_handler;
    endElementNs(&ctxt, (const xmlChar *)"unit", (const xmlChar *)"src",
                 (const xmlChar *)"http://www.sdml.info/srcML/src");
    assert(handler.start_document == 0);
    assert(handler.end_document == 0);
    assert(handler.start_root == 0);
    assert(handler.start_unit == 0);
    assert(handler.start_element_ns == 0);
    assert(handler.end_root == 1);
    assert(handler.end_unit == 0);
    assert(handler.end_element_ns == 0);
    assert(handler.characters_root == 0);
    assert(handler.characters_unit == 0);
    assert(handler.comment_ == 0);
    assert(handler.cdata_block == 0);

  }

  {

    srcMLHandlerTest handler;
    SAX2srcSAXHandler sax2_handler;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    endElementNs(&ctxt, (const xmlChar *)"unit", (const xmlChar *)"src",
                 (const xmlChar *)"http://www.sdml.info/srcML/src");
    assert(handler.start_document == 0);
    assert(handler.end_document == 0);
    assert(handler.start_root == 0);
    assert(handler.start_unit == 0);
    assert(handler.start_element_ns == 0);
    assert(handler.end_root == 0);
    assert(handler.end_unit == 1);
    assert(handler.end_element_ns == 0);
    assert(handler.characters_root == 0);
    assert(handler.characters_unit == 0);
    assert(handler.comment_ == 0);
    assert(handler.cdata_block == 0);

  }

  {

    srcMLHandlerTest handler;
    SAX2srcSAXHandler sax2_handler;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    endElementNs(&ctxt, (const xmlChar *)"name", (const xmlChar *)"src",
                 (const xmlChar *)"http://www.sdml.info/srcML/src");
    assert(handler.start_document == 0);
    assert(handler.end_document == 0);
    assert(handler.start_root == 0);
    assert(handler.start_unit == 0);
    assert(handler.start_element_ns == 0);
    assert(handler.end_root == 0);
    assert(handler.end_unit == 0);
    assert(handler.end_element_ns == 1);
    assert(handler.characters_root == 0);
    assert(handler.characters_unit == 0);
    assert(handler.comment_ == 0);
    assert(handler.cdata_block == 0);

  }

  /*
    charactersRoot
  */
  {

    srcMLHandlerTest handler;
    SAX2srcSAXHandler sax2_handler;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    charactersRoot(&ctxt, (const xmlChar *)"unit", 4);
    assert(handler.start_document == 0);
    assert(handler.end_document == 0);
    assert(handler.start_root == 0);
    assert(handler.start_unit == 0);
    assert(handler.start_element_ns == 0);
    assert(handler.end_root == 0);
    assert(handler.end_unit == 0);
    assert(handler.end_element_ns == 0);
    assert(handler.characters_root == 1);
    assert(handler.characters_unit == 0);
    assert(handler.comment_ == 0);
    assert(handler.cdata_block == 0);

  }

  /*
    charactersUnit
  */
  {

    srcMLHandlerTest handler;
    SAX2srcSAXHandler sax2_handler;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    charactersUnit(&ctxt, (const xmlChar *)"unit", 4);
    assert(handler.start_document == 0);
    assert(handler.end_document == 0);
    assert(handler.start_root == 0);
    assert(handler.start_unit == 0);
    assert(handler.start_element_ns == 0);
    assert(handler.end_root == 0);
    assert(handler.end_unit == 0);
    assert(handler.end_element_ns == 0);
    assert(handler.characters_root == 0);
    assert(handler.characters_unit == 1);
    assert(handler.comment_ == 0);
    assert(handler.cdata_block == 0);

  }

  /*
    comment
  */
  {

    srcMLHandlerTest handler;
    SAX2srcSAXHandler sax2_handler;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    comment(&ctxt, (const xmlChar *)"unit");
    assert(handler.start_document == 0);
    assert(handler.end_document == 0);
    assert(handler.start_root == 0);
    assert(handler.start_unit == 0);
    assert(handler.start_element_ns == 0);
    assert(handler.end_root == 0);
    assert(handler.end_unit == 0);
    assert(handler.end_element_ns == 0);
    assert(handler.characters_root == 0);
    assert(handler.characters_unit == 0);
    assert(handler.comment_ == 1);
    assert(handler.cdata_block == 0);

  }

  /*
    cdataBlock
  */
  {

    srcMLHandlerTest handler;
    SAX2srcSAXHandler sax2_handler;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    cdataBlock(&ctxt, (const xmlChar *)"unit", 4);
    assert(handler.start_document == 0);
    assert(handler.end_document == 0);
    assert(handler.start_root == 0);
    assert(handler.start_unit == 0);
    assert(handler.start_element_ns == 0);
    assert(handler.end_root == 0);
    assert(handler.end_unit == 0);
    assert(handler.end_element_ns == 0);
    assert(handler.characters_root == 0);
    assert(handler.characters_unit == 0);
    assert(handler.comment_ == 0);
    assert(handler.cdata_block == 1);

  }

  return 0;
}
