#ifndef INCLUDED_SAX2SRCMLHANDLER_HPP
#define INCLUDED_SAX2SRCMLHANDLER_HPP

#include <libxml/parser.h>

xmlSAXHandler factory();

void startDocument(void * ctx);

void endDocument(void * ctx);
void startElementNs(void * ctx, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                           int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                           const xmlChar ** attributes);

void endElementNs(void * ctx, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI);

void characters(void * ctx, const xmlChar * ch, int len);

#endif
