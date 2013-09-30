#include <SAX2srcMLHandler.hpp>

xmlSAXHandler factory() {

  xmlSAXHandler sax = { 0 };

  sax.initialized    = XML_SAX2_MAGIC;

  sax.startDocument = &startDocument;
  sax.endDocument = &endDocument;

  sax.startElementNs = &startElementNs;
  sax.endElementNs = &startElementNs;

  sax.characters = &characters;

  return sax;
}

void startDocument(void * ctx) {

  xmlParserCtxtPtr ctxt = (xmlParserCtxtPtr) ctx;
  srcMLHandler * state = (srcMLHandler *) ctxt->_private;

  state->startDocument();

}

void endDocument(void * ctx) {

  xmlParserCtxtPtr ctxt = (xmlParserCtxtPtr) ctx;
  srcMLHandler * state = (srcMLHandler *) ctxt->_private;

  state->endDocument();

}

void startElementNs(void * ctx, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                           int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                    const xmlChar ** attributes) {

  xmlParserCtxtPtr ctxt = (xmlParserCtxtPtr) ctx;
  srcMLHandler * state = (srcMLHandler *) ctxt->_private;

  state->startElementNs(localname, prefix, URI, nb_namespaces, namespaces, nb_attributes, nb_defaullted, attributes);

}

void endElementNs(void * ctx, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

  xmlParserCtxtPtr ctxt = (xmlParserCtxtPtr) ctx;
  srcMLHandler * state = (srcMLHandler *) ctxt->_private;

  state->endElementNs(localname, prefix, URI);

}

void characters(void * ctx, const xmlChar * ch, int len) {

  xmlParserCtxtPtr ctxt = (xmlParserCtxtPtr) ctx;
  srcMLHandler * state = (srcMLHandler *) ctxt->_private;

  state->characters(ch, len)
}
