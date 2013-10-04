#include <srcMLHandlerTest.hpp>
#include <SAX2srcMLHandler.hpp>

#include <stdio.h>
#include <string.h>
#include <cassert>

int main(int argc, char * argv[]) {

  /*
    startDocument
  */
  {

    srcMLHandlerTest handler;
    SAX2srcMLHandler sax2_handler;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    startDocument(&ctxt);
    assert(handler.start_document == true);
    assert(handler.end_document == false);
    assert(handler.start_root == false);
    assert(handler.start_unit == false);
    assert(handler.start_element_ns == false);
    assert(handler.end_root == false);
    assert(handler.end_unit == false);
    assert(handler.end_element_ns == false);
    assert(handler.characters_root == false);
    assert(handler.characters_unit == false);
    assert(handler.comment_ == false);
    assert(handler.cdata_block == false);

  }

  /*
    endDocument
  */
  {

    srcMLHandlerTest handler;
    SAX2srcMLHandler sax2_handler = { 0 };
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    ctxt._private = &sax2_handler;
    endDocument(&ctxt);
    assert(handler.start_document == false);
    assert(handler.end_document == true);
    assert(handler.start_root == false);
    assert(handler.start_unit == false);
    assert(handler.start_element_ns == false);
    assert(handler.end_root == true);
    assert(handler.end_unit == false);
    assert(handler.end_element_ns == false);
    assert(handler.characters_root == false);
    assert(handler.characters_unit == false);
    assert(handler.comment_ == false);
    assert(handler.cdata_block == false);

  }

  {

    srcMLHandlerTest handler;
    SAX2srcMLHandler sax2_handler = { 0 };
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    xmlSAXHandler sax = factory();
    ctxt.sax = &sax;
    sax.startElementNs = 0;
    ctxt._private = &sax2_handler;
    endDocument(&ctxt);
    assert(handler.start_document == false);
    assert(handler.end_document == true);
    assert(handler.start_root == false);
    assert(handler.start_unit == false);
    assert(handler.start_element_ns == false);
    assert(handler.end_root == false);
    assert(handler.end_unit == false);
    assert(handler.end_element_ns == false);
    assert(handler.characters_root == false);
    assert(handler.characters_unit == false);
    assert(handler.comment_ == false);
    assert(handler.cdata_block == false);

  }

  /*
    startRoot
  */
  {

    srcMLHandlerTest handler;
    SAX2srcMLHandler sax2_handler = { 0 };
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
    assert(handler.start_document == false);
    assert(handler.end_document == false);
    assert(handler.start_root == true);
    assert(handler.start_unit == false);
    assert(handler.start_element_ns == false);
    assert(handler.end_root == false);
    assert(handler.end_unit == false);
    assert(handler.end_element_ns == false);
    assert(handler.characters_root == false);
    assert(handler.characters_unit == false);
    assert(handler.comment_ == false);
    assert(handler.cdata_block == false);
    endDocument(&ctxt);

  }

  /*
    startUnit
  */
  {

    srcMLHandlerTest handler;
    SAX2srcMLHandler sax2_handler = { 0 };
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
    assert(handler.start_document == false);
    assert(handler.end_document == false);
    assert(handler.start_root == true);
    assert(handler.start_unit == false);
    assert(handler.start_element_ns == false);
    assert(handler.end_root == false);
    assert(handler.end_unit == false);
    assert(handler.end_element_ns == false);
    assert(handler.characters_root == false);
    assert(handler.characters_unit == false);
    assert(handler.comment_ == false);
    assert(handler.cdata_block == false);
    endDocument(&ctxt);

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

    srcMLHandlerTest handler;
    SAX2srcMLHandler sax2_handler = { 0 };
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
    endRoot
  */
  {

    srcMLHandlerTest handler;
    SAX2srcMLHandler sax2_handler = { 0 };
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

    srcMLHandlerTest handler;
    SAX2srcMLHandler sax2_handler = { 0 };
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

    srcMLHandlerTest handler;
    SAX2srcMLHandler sax2_handler = { 0 };
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
    endUnit
  */
  {

    srcMLHandlerTest handler;
    SAX2srcMLHandler sax2_handler = { 0 };
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

  /*
    endElementNs
  */
  {

    srcMLHandlerTest handler;
    SAX2srcMLHandler sax2_handler = { 0 };
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

  /*
    charactersRoot
  */
  {

    srcMLHandlerTest handler;
    SAX2srcMLHandler sax2_handler = { 0 };
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

    srcMLHandlerTest handler;
    SAX2srcMLHandler sax2_handler = { 0 };
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

    srcMLHandlerTest handler;
    SAX2srcMLHandler sax2_handler = { 0 };
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

    srcMLHandlerTest handler;
    SAX2srcMLHandler sax2_handler = { 0 };
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
