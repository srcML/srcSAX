#include <srcMLControlHandler.hpp>
#include <SAX2srcMLHandler.hpp>

srcMLControlHandler::srcMLControlHandler(std::string filename) {

  ctxt = xmlCreateURLParserCtxt(filename.c_str(), XML_PARSE_COMPACT | XML_PARSE_HUGE);

}

srcMLControlHandler::~srcMLControlHandler() {

  xmlFreeParserCtxt(ctxt);

}

void srcMLControlHandler::parse(srcMLHandler * handler) {

  xmlSAXHandler sax = factory();

  SAX2srcMLHandler sax2_handler;
  sax2_handler.process = handler;

  ctxt->sax = &sax;
  ctxt->_private = &sax2_handler;

  int status = xmlParseDocument(ctxt);

}
