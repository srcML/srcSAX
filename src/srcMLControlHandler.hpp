#ifndef INCLUDED_SRCMLCONTROLHANDLER_HPP
#define INCLUDED_SRCMLCONTROLHANDLER_HPP

class srcMLControlHandler {

private :

  xmlParserCtxtPtr ctxt;

public :

  srcMLControlHandler(std::string filename);
  ~srcMLControlHandler();

  void parse(srcMLHandler * handler);

};

#endif
