#ifndef INCLUDED_SRCMLHANDLER_HPP
#define INCLUDED_SRCMLHANDLER_HPP

#include <libxml/parser.h>

class srcMLHandler {

public :

  virtual void startDocument() {}

  virtual void endDocument() {}

  virtual void startElementNs(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                           int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                      const xmlChar ** attributes) {}

  virtual void endElementNs(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {}

  virtual void characters(const xmlChar * ch, int len) {}

};

#endif
