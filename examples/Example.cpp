#include <srcMLHandlerExample.hpp>
#include <SAX2srcMLHandler.hpp>

#include <libxml/parserInternals.h>

int main(int argc, char * argv[]) {

  xmlParserCtxtPtr ctxt = srcMLCreateURLParserCtxt("example.xml");
  xmlSAXHandler sax = factory();

  SAX2srcMLHandler handler;
  srcMLHandlerExample example;
  handler.process = &example;

  ctxt->sax = &sax;
  ctxt->_private = &handler;

  srcMLParseDocument(ctxt);

  return 0;
}
