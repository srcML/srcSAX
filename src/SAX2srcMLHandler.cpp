/*
  @file SAX2srcMLHandler.cpp

  Copyright (C) 2004-2013  SDML (www.sdml.info)

  This file is part of the srcML SAX2 Framework.

  The srcML SAX2 Framework is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  The srcML SAX2 Framework is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with the srcML SAX2 Framework; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <SAX2srcMLHandler.hpp>

/**
 * factory
 *
 * Create SAX handler.
 */
xmlSAXHandler factory() {

  xmlSAXHandler sax = { 0 };

  sax.initialized    = XML_SAX2_MAGIC;

  sax.startDocument = &startDocument;
  sax.endDocument = &endDocument;

  sax.startElementNs = &startElementNs;
  sax.endElementNs = &endElementNs;

  sax.characters = &characters;

  return sax;
}

/**
 * startDocument
 * @param ctx an xmlParserCtxtPtr
 *
 * SAX handler function for start of document.
 * Immediately calls supplied handlers function.
 */
void startDocument(void * ctx) {

  xmlParserCtxtPtr ctxt = (xmlParserCtxtPtr) ctx;
  SAX2srcMLHandler * state = (SAX2srcMLHandler *) ctxt->_private;

  state->process->startDocument();

}

/**
 * endDocument
 * @param ctx an xmlParserCtxtPtr
 *
 * SAX handler function for end of document.
 * Immediately calls supplied handlers function.
 */
void endDocument(void * ctx) {

  xmlParserCtxtPtr ctxt = (xmlParserCtxtPtr) ctx;
  SAX2srcMLHandler * state = (SAX2srcMLHandler *) ctxt->_private;

  state->process->endDocument();

}

/**
 * startElementNs
 * @param ctx an xmlParserCtxtPtr
 * @param localname the name of the element tag
 * @param prefix the tag prefix
 * @param URI the namespace of tag
 * @param nb_namespaces number of namespaces definitions
 * @param namespaces the defined namespaces
 * @param nb_attributes the number of attributes on the tag
 * @param nb_defaulted the number of defaulted attributes
 * @param attributes list of attribute name value pairs (localname/prefix/URI/value/end)
 *
 * SAX handler function for start of an element.
 * Immediately calls supplied handlers function.
 */
void startElementNs(void * ctx, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                           int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                    const xmlChar ** attributes) {

  xmlParserCtxtPtr ctxt = (xmlParserCtxtPtr) ctx;
  SAX2srcMLHandler * state = (SAX2srcMLHandler *) ctxt->_private;

  state->process->startElementNs(localname, prefix, URI, nb_namespaces, namespaces, nb_attributes, nb_defaulted, attributes);

}

void endElementNs(void * ctx, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

  xmlParserCtxtPtr ctxt = (xmlParserCtxtPtr) ctx;
  SAX2srcMLHandler * state = (SAX2srcMLHandler *) ctxt->_private;

  state->process->endElementNs(localname, prefix, URI);

}

void characters(void * ctx, const xmlChar * ch, int len) {

  xmlParserCtxtPtr ctxt = (xmlParserCtxtPtr) ctx;
  SAX2srcMLHandler * state = (SAX2srcMLHandler *) ctxt->_private;

  state->process->characters(ch, len);
}
