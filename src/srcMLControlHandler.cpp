#include <srcMLControlHandler.hpp>

// create srcml parser with error reporting
static void srcMLCreateURLParserCtxt(const char * infile) {

  ctxt = xmlCreateURLParserCtxt(infile, XML_PARSE_COMPACT | XML_PARSE_HUGE);

}

// process srcML document with error reporting
static int srcMLParseDocument(xmlParserCtxtPtr ctxt) {

  // process the document                                                                                              
  int status;
  if ((status = xmlParseDocument(ctxt)) == -1)
    return status;

}
