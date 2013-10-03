#include <SAX2srcMLHandler.hpp>

#include <stdio.h>
#include <string.h>
#include <cassert>

int main(int argc, char * argv[]) {

  /*
    factory
   */

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

  /*
    endDocument
   */
  {

    srcMLHandler handler;
    SAX2srcMLHandler sax2_handler;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
    ctxt._private = &sax2_handler;
    endDocument(&ctxt);

  }

  /*
    startRoot
   */
  {

    srcMLHandler handler;
    SAX2srcMLHandler sax2_handler;
    sax2_handler.process = &handler;

    xmlParserCtxt ctxt;
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
    assert(const char *)sax2_handler.root.attributes[3] == values);
    assert(const char *)sax2_handler.root.attributes[4] == values + 1);
    assert((const char *)sax2_handler.root.attributes[5] == std::string("dir"));
    assert((const char *)sax2_handler.root.attributes[6] == std::string("src"));
    assert((const char *)sax2_handler.root.attributes[7] == std::string("http://www.sdml.info/srcML/src"));
    assert(const char *)sax2_handler.root.attributes[8] == values + 1);
    assert(const char *)sax2_handler.root.attributes[9] == values + 2);
    assert((const char *)sax2_handler.root.attributes[10] == std::string("language"));
    assert((const char *)sax2_handler.root.attributes[11] == std::string("src"));
    assert((const char *)sax2_handler.root.attributes[12] == std::string("http://www.sdml.info/srcML/src"));
    assert(const char *)sax2_handler.root.attributes[13] == values + 2);
    assert(const char *)sax2_handler.root.attributes[14] == values + 3);

  }

  return 0;
}
