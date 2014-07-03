/**
 * @file test_sax2_srcml_handler.cpp
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

#include <SAX2srcMLHandler.hpp>
#include <srcMLHandler.hpp>

#include <stdio.h>
#include <string.h>
#include <cassert>

SAX2srcMLHandler sax2_handler_init;


int main() {

  /*
    factory
   */

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

  {

    xmlSAXHandler sax = factory();
    assert(sax.initialized == XML_SAX2_MAGIC);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);

  }

#pragma GCC diagnostic pop

  /*
    startDocument
   */
  {

    srcMLHandler handler;
    SAX2srcMLHandler sax2_handler;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    ctxt._private = &sax2_handler;
    startDocument(&ctxt);

  }

  {

    startDocument(NULL);

  }

  /*
    endDocument
   */
  {

    srcMLHandler handler;
    SAX2srcMLHandler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    endDocument(&ctxt);

  }

  {

    endDocument(NULL);

  }

  /*
    startRoot
   */
  {

    srcMLHandler handler;
    SAX2srcMLHandler sax2_handler = sax2_handler_init;
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
    assert(ctxt.sax->startDocument == startDocument);
    assert(ctxt.sax->endDocument == endDocument);
    assert(ctxt.sax->startElementNs == startElementNsFirst);
    assert(ctxt.sax->endElementNs == endElementNs);
    assert(ctxt.sax->characters == charactersFirst);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdataBlock == cdataBlock);
    endDocument(&ctxt);

  }

  {

    const char * namespaces[4] = { "src", "http://www.sdml.info/srcML/src", "cpp", "http://www.sdml.info/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", "src", "http://www.sdml.info/srcML/src", values, values + 1,
                                    "dir", "src", "http://www.sdml.info/srcML/src", values + 1, values + 2,
                                    "language", "src", "http://www.sdml.info/srcML/src", values + 2, values + 3 };
    startRoot(NULL, (const xmlChar *)"unit", (const xmlChar *)"src",
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

  }


  /*
    startElementNsFirst
   */
  {

    srcMLHandler handler;
    SAX2srcMLHandler sax2_handler = sax2_handler_init;
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
    assert(ctxt.sax->startDocument == startDocument);
    assert(ctxt.sax->endDocument == endDocument);
    assert(ctxt.sax->startElementNs == startElementNs);
    assert(ctxt.sax->endElementNs == endElementNs);
    assert(ctxt.sax->characters == charactersUnit);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdataBlock == cdataBlock);

  }

  {
    const char * namespaces[4] = { "src", "http://www.sdml.info/srcML/src", "cpp", "http://www.sdml.info/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", "src", "http://www.sdml.info/srcML/src", values, values + 1,
                                    "dir", "src", "http://www.sdml.info/srcML/src", values + 1, values + 2,
                                    "language", "src", "http://www.sdml.info/srcML/src", values + 2, values + 3 };
    startElementNsFirst(NULL, (const xmlChar *)"unit", (const xmlChar *)"src",
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

  }

  /*
    startUnit
   */
  {

    srcMLHandler handler;
    SAX2srcMLHandler sax2_handler = sax2_handler_init;
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
    assert(ctxt.sax->startDocument == startDocument);
    assert(ctxt.sax->endDocument == endDocument);
    assert(ctxt.sax->startElementNs == startElementNs);
    assert(ctxt.sax->endElementNs == endElementNs);
    assert(ctxt.sax->characters == charactersUnit);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdataBlock == cdataBlock);

  }

  {

    const char * namespaces[4] = { "src", "http://www.sdml.info/srcML/src", "cpp", "http://www.sdml.info/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", "src", "http://www.sdml.info/srcML/src", values, values + 1,
                                    "dir", "src", "http://www.sdml.info/srcML/src", values + 1, values + 2,
                                    "language", "src", "http://www.sdml.info/srcML/src", values + 2, values + 3 };
    startUnit(NULL, (const xmlChar *)"unit", (const xmlChar *)"src",
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

  }

  /*
    startElementNs
   */
  {

    srcMLHandler handler;
    SAX2srcMLHandler sax2_handler = sax2_handler_init;
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
    assert(ctxt.sax->startDocument == startDocument);
    assert(ctxt.sax->endDocument == endDocument);
    assert(ctxt.sax->startElementNs == startRoot);
    assert(ctxt.sax->endElementNs == endElementNs);
    assert(ctxt.sax->characters == charactersFirst);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdataBlock == cdataBlock);

  }

  {
    const char * namespaces[4] = { "src", "http://www.sdml.info/srcML/src", "cpp", "http://www.sdml.info/srcML/cpp" };
    const char * values = "abc";
    const char * attributes[15] = { "filename", "src", "http://www.sdml.info/srcML/src", values, values + 1,
                                    "dir", "src", "http://www.sdml.info/srcML/src", values + 1, values + 2,
                                    "language", "src", "http://www.sdml.info/srcML/src", values + 2, values + 3 };
    startElementNs(NULL, (const xmlChar *)"unit", (const xmlChar *)"src",
              (const xmlChar *)"http://www.sdml.info/srcML/src", 2, (const xmlChar **)namespaces, 3, 0,
              (const xmlChar **) attributes);

  }

  /*
    endElementNs
   */
  {

    srcMLHandler handler;
    SAX2srcMLHandler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    endElementNs(&ctxt, (const xmlChar *)"unit", (const xmlChar *)"src", 
                   (const xmlChar *)"http://www.sdml.info/srcML/src");
    assert(ctxt.sax->startDocument == startDocument);
    assert(ctxt.sax->endDocument == endDocument);
    assert(ctxt.sax->startElementNs == startUnit);
    assert(ctxt.sax->endElementNs == endElementNs);
    assert(ctxt.sax->characters == charactersRoot);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdataBlock == cdataBlock);

  }

  {

    srcMLHandler handler;
    SAX2srcMLHandler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    sax.startElementNs = &startUnit;
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    endElementNs(&ctxt, (const xmlChar *)"unit", (const xmlChar *)"src", 
                   (const xmlChar *)"http://www.sdml.info/srcML/src");
    assert(ctxt.sax->startDocument == startDocument);
    assert(ctxt.sax->endDocument == endDocument);
    assert(ctxt.sax->startElementNs == 0);
    assert(ctxt.sax->endElementNs == endElementNs);
    assert(ctxt.sax->characters == charactersFirst);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdataBlock == cdataBlock);

  }

  {

    srcMLHandler handler;
    SAX2srcMLHandler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    endElementNs(&ctxt, (const xmlChar *)"name", (const xmlChar *)"src", 
                   (const xmlChar *)"http://www.sdml.info/srcML/src");
    assert(ctxt.sax->startDocument == startDocument);
    assert(ctxt.sax->endDocument == endDocument);
    assert(ctxt.sax->startElementNs == startRoot);
    assert(ctxt.sax->endElementNs == endElementNs);
    assert(ctxt.sax->characters == charactersFirst);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdataBlock == cdataBlock);

  }

  {

    endElementNs(NULL, (const xmlChar *)"unit", (const xmlChar *)"src",
                 (const xmlChar *)"http://www.sdml.info/srcML/src");
  }

  /*
    charactersFirst
   */
  {

    srcMLHandler handler;
    SAX2srcMLHandler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    charactersFirst(&ctxt, (const xmlChar *)"unit", 4);
    assert(sax2_handler.root.characters == "unit");
    assert(ctxt.sax->startDocument == startDocument);
    assert(ctxt.sax->endDocument == endDocument);
    assert(ctxt.sax->startElementNs == startRoot);
    assert(ctxt.sax->endElementNs == endElementNs);
    assert(ctxt.sax->characters == charactersFirst);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdataBlock == cdataBlock);

  }

  {

    charactersFirst(NULL, (const xmlChar *)"unit", 4);

  }

  /*
    charactersRoot
   */
  {

    srcMLHandler handler;
    SAX2srcMLHandler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    charactersRoot(&ctxt, (const xmlChar *)"unit", 4);
    assert(ctxt.sax->startDocument == startDocument);
    assert(ctxt.sax->endDocument == endDocument);
    assert(ctxt.sax->startElementNs == startRoot);
    assert(ctxt.sax->endElementNs == endElementNs);
    assert(ctxt.sax->characters == charactersFirst);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdataBlock == cdataBlock);
  }

  {

    charactersRoot(NULL, (const xmlChar *)"unit", 4);

  }

  /*
    charactersUnit
   */
  {

    srcMLHandler handler;
    SAX2srcMLHandler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    charactersUnit(&ctxt, (const xmlChar *)"unit", 4);
    assert(ctxt.sax->startDocument == startDocument);
    assert(ctxt.sax->endDocument == endDocument);
    assert(ctxt.sax->startElementNs == startRoot);
    assert(ctxt.sax->endElementNs == endElementNs);
    assert(ctxt.sax->characters == charactersFirst);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdataBlock == cdataBlock);
  }

  {

    charactersUnit(NULL, (const xmlChar *)"unit", 4);

  }

  /*
    comment
   */
  {

    srcMLHandler handler;
    SAX2srcMLHandler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    comment(&ctxt, (const xmlChar *)"unit");
    assert(ctxt.sax->startDocument == startDocument);
    assert(ctxt.sax->endDocument == endDocument);
    assert(ctxt.sax->startElementNs == startRoot);
    assert(ctxt.sax->endElementNs == endElementNs);
    assert(ctxt.sax->characters == charactersFirst);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdataBlock == cdataBlock);
  }

  {

    comment(NULL, (const xmlChar *)"unit");

  }

  /*
    cdataBlock
   */
  {

    srcMLHandler handler;
    SAX2srcMLHandler sax2_handler = sax2_handler_init;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    cdataBlock(&ctxt, (const xmlChar *)"unit", 4);
    assert(ctxt.sax->startDocument == startDocument);
    assert(ctxt.sax->endDocument == endDocument);
    assert(ctxt.sax->startElementNs == startRoot);
    assert(ctxt.sax->endElementNs == endElementNs);
    assert(ctxt.sax->characters == charactersFirst);
    assert(ctxt.sax->comment == comment);
    assert(ctxt.sax->cdataBlock == cdataBlock);
  }

  {

    cdataBlock(NULL, (const xmlChar *)"unit", 4);

  }

  return 0;
}
