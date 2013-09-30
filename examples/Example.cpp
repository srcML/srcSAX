#include <srcMLHandlerExample.hpp>
#include <SAX2srcMLHandler.hpp>

#include <libxml/parserInternals.h>

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
static void srcMLParseDocument(xmlParserCtxtPtr ctxt, bool allowendearly) {

  // process the document                                                                                              
  int status;
  if ((status = xmlParseDocument(ctxt)) == -1) {

    xmlErrorPtr ep = xmlCtxtGetLastError(ctxt);
  }
}
int main(int argc, char * argv[]) {

  xmlParserCtxtPtr ctxt = srcMLCreateURLParserCtxt("example.xml");
  xmlSAXHandler sax = factory();

  SAX2srcMLHandler handler;
  srcMLHandlerExample example;
  handler.process = &example;

 ctxt->sax = &sax;
 ctxt->_private = &handler;

  return 0;
}
