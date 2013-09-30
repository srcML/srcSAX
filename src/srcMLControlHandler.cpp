#include <srcMLControlHandler.hpp>
#include <SAX2srcMLHandler.hpp>

srcMLControlHandler::srcMLControlHandler(const char * filename) {

  ctxt = xmlCreateURLParserCtxt(filename, XML_PARSE_COMPACT | XML_PARSE_HUGE);
  fprintf(stderr, "HERE: %s %s %d %p\n", __FILE__, __FUNCTION__, __LINE__, ctxt);
}

srcMLControlHandler::~srcMLControlHandler() {

  if(ctxt) xmlFreeParserCtxt(ctxt);

}

void srcMLControlHandler::parse(srcMLHandler * handler) {

  xmlSAXHandler sax = factory();

  SAX2srcMLHandler sax2_handler;
  sax2_handler.process = handler;

  ctxt->sax = &sax;
  ctxt->_private = &sax2_handler;

  int status = xmlParseDocument(ctxt);
  ctxt->sax = NULL;

}
