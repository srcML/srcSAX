#ifndef INCLUDED_SRCMLCONTROLHANDLER_HPP
#define INCLUDED_SRCMLCONTROLHANDLER_HPP

#include <srcMLHandler.hpp>
#include <SAX2srcMLHandler.hpp>

#include <libxml/parser.h>
#include <libxml/parserInternals.h>

class srcMLControlHandler {

private :

  xmlParserCtxtPtr ctxt;
  xmlSAXHandler sax;
  SAX2srcMLHandler sax2_handler;

public :

  srcMLControlHandler(const char * filename);
  ~srcMLControlHandler();

  void parse(srcMLHandler * handler);

};

#endif
