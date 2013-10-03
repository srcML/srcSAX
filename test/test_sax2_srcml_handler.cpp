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

    xmlParserCtxt ctxt;
    ctxt._private = &handler;
    

  }

  return 0;
}
