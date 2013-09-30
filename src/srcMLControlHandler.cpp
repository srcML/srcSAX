#include <srcMLControlHandler.hpp>

srcMLControlHandler::srcMLControlHandler(std::string filename) {

  ctxt = xmlCreateURLParserCtxt(infile, XML_PARSE_COMPACT | XML_PARSE_HUGE);

}

srcMLControlHandler::~srcMLControlHandler() {

  xmlFreeParserCtxt(ctxt);

}

void srcMLControlHandler::parse(srcMLHandler * handler) {

  xmlSAXHandler sax = factory();

  SAX2srcMLHandler handler;
  srcMLHandlerExample example;
  handler.process = &example;

  ctxt->sax = &sax;
  ctxt->_private = &handler;

  int status = xmlParseDocument(ctxt);

}
