#include <srcMLControlHandler.hpp>

srcMLControlHandler::srcMLControlHandler(std::string filename) {

  ctxt = xmlCreateURLParserCtxt(infile, XML_PARSE_COMPACT | XML_PARSE_HUGE);

}


void srcMLControlHandler::parse() {

  // process the document
  int status;
  if ((status = xmlParseDocument(ctxt)) == -1)
    return status;

}
