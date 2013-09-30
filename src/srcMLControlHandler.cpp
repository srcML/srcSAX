#ifndef INCLUDED_SRCMLCONTROLHANDLER_HPP
#define INCLUDED_SRCMLCONTROLHANDLER_HPP

// create srcml parser with error reporting
xmlParserCtxtPtr srcMLCreateURLParserCtxt(const char * infile) {

  xmlParserCtxtPtr ctxt = xmlCreateURLParserCtxt(infile, XML_PARSE_COMPACT | XML_PARSE_HUGE);
  if (ctxt == NULL) {

    // report error                                                                                                    
    xmlErrorPtr ep = xmlGetLastError();
  }

  return ctxt;
}

// process srcML document with error reporting
static void srcMLParseDocument(xmlParserCtxtPtr ctxt) {

  // process the document                                                                                              
  int status;
  if ((status = xmlParseDocument(ctxt)) == -1) {

    xmlErrorPtr ep = xmlCtxtGetLastError(ctxt);
  }
}

class srcMLControlHandler {

public :

  srcMLControlHandler() {

  }

  

};

#endif
