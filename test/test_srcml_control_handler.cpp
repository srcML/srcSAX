#include <srcMLControlHandler.hpp>

#include <stdio.h>
#include <string.h>
#include <cassert>

int main(int argc, char * argv[]) {

  /*
    srcMLControlHandler
   */
  {
    try {

      srcMLControlHandler control(__FILE__);

    } catch(...) { assert(false); }
  }

  {
    try {

      srcMLControlHandler control("foobar");
      assert(false);
    } catch(...) {}
  }

  /*
    enable_startDocument
   */
  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  /*
    enable_startDocument
   */
  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_startDocument(true);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_startDocument(false);
    assert(sax.startDocument == 0);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  /*
    enable_endDocument
   */
  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_endDocument(true);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_endDocument(false);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == 0);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }


  return 0;
}
