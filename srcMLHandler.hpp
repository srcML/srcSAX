#ifndef INCLUDED_SRCMLHANDLER_HPP
#define INCLUDED_SRCMLHANDLER_HPP

class srcMLHandler {

  virtual void startDocument(void * ctx) {}

  virtual void endDocument(void * ctx) {}

  virtual void startElementNs(void * ctx, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                           int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                      const xmlChar ** attributes) {}

  virtual void endElementNs(void * ctx, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {}

  virtual void characters(void * ctx, const xmlChar * ch, int len) {}

}

#endif
