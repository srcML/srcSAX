#ifndef INCLUDED_SRCMLCONTROLHANDLER_HPP
#define INCLUDED_SRCMLCONTROLHANDLER_HPP

#include <srcMLHandler.hpp>

#include <string>

#include <libxml/parser.h>
#include <libxml/parserInternals.h>

class srcMLControlHandler {

private :

  xmlParserCtxtPtr ctxt;

public :

  srcMLControlHandler(std::string filename);
  ~srcMLControlHandler();

  void parse(srcMLHandler * handler);

};

#endif
