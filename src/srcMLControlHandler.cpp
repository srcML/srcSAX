#include <srcMLControlHandler.hpp>

srcMLControlHandler::srcMLControlHandler(std::string filename) {

  ctxt = xmlCreateURLParserCtxt(infile, XML_PARSE_COMPACT | XML_PARSE_HUGE);

}


void srcMLControlHandler::parse(srcMLHandler * handler) {

  int status = xmlParseDocument(ctxt);

}
