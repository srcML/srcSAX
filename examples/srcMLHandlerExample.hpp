#ifndef INCLUDED_SRCMLHANDLER_HPP
#define INCLUDED_SRCMLHANDLER_HPP

#include <srcMLHandler.hpp>

#include <stdio.h>

class srcMLHandlerExample : public srcMLHandler {

public :

  virtual void startDocument() {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
    
  }

  virtual void endDocument() {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  virtual void startElementNs(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                           int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                      const xmlChar ** attributes) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  virtual void endElementNs(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  virtual void characters(const xmlChar * ch, int len) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

};

#endif
