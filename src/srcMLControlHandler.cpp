#include <srcMLControlHandler.hpp>

srcMLControlHandler::srcMLControlHandler(const char * filename) : sax2_handler() {

  ctxt = xmlCreateURLParserCtxt(filename, XML_PARSE_COMPACT | XML_PARSE_HUGE);
  sax = factory();
  ctxt->sax = &sax;

}

srcMLControlHandler::~srcMLControlHandler() {

  ctxt->sax = NULL;
  if(ctxt) xmlFreeParserCtxt(ctxt);

}

void srcMLControlHandler::parse(srcMLHandler * handler) {


  sax2_handler.process = handler;

  ctxt->sax = &sax;
  ctxt->_private = &sax2_handler;

  int status = xmlParseDocument(ctxt);

}
