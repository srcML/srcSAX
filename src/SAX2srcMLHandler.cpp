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

#include <cstring>

const char * const SRCML_SRC_NS_URI = "http://www.sdml.info/srcML/src";

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

  sax.startElementNs = &startRoot;
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
 * startRoot
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
void startRoot(void * ctx, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                           int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                    const xmlChar ** attributes) {

  xmlParserCtxtPtr ctxt = (xmlParserCtxtPtr) ctx;
  SAX2srcMLHandler * state = (SAX2srcMLHandler *) ctxt->_private;

  // need to record that we actually found something besides the root element
  //state->rootonly = true;

  // save all the info in case this is not a srcML archive
  state->root.localname = localname ? (xmlChar*) strdup((const char*) localname) : 0;
  state->root.prefix = prefix ? (xmlChar*) strdup((const char*) prefix) : 0;
  state->root.URI = URI ? (xmlChar*) strdup((const char*) URI) : 0;

  state->root.nb_namespaces = nb_namespaces;
  int ns_length = nb_namespaces * 2;
  state->root.namespaces = (const xmlChar**) malloc(ns_length * sizeof(namespaces[0]));
  for (int i = 0; i < ns_length; ++i)
    state->root.namespaces[i] = namespaces[i] ? (xmlChar*) strdup((const char*) namespaces[i]) : 0;

  state->root.nb_attributes = nb_attributes;
  state->root.nb_defaulted = nb_defaulted;

  int nb_length = nb_attributes * 5;
  state->root.attributes = (const xmlChar**) malloc(nb_length * sizeof(attributes[0]));
  for (int i = 0, index = 0; i < nb_attributes; ++i, index += 5) {
    state->root.attributes[index] = attributes[index] ? (xmlChar*) strdup((const char*) attributes[index]) : 0;
    state->root.attributes[index + 1] = attributes[index + 1] ? (xmlChar*) strdup((const char*) attributes[index + 1]) : 0;
    state->root.attributes[index + 2] = attributes[index + 2] ? (xmlChar*) strdup((const char*) attributes[index + 2]) : 0;
    int vallength = attributes[index + 4] - attributes[index + 3];
    state->root.attributes[index + 3] = (const xmlChar*) malloc(vallength);
    strncpy((char *) state->root.attributes[index + 3], (const char*) attributes[index + 3], vallength);
    state->root.attributes[index + 4] = state->root.attributes[index + 3] + vallength;
  }

  state->process->startRoot(localname, prefix, URI, nb_namespaces, namespaces, nb_attributes, nb_defaulted, attributes);
  // handle nested units
  ctxt->sax->startElementNs = &startElementNsFirst;

}

/**
 * startElementNsFirst
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
void startElementNsFirst(void * ctx, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                           int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                    const xmlChar ** attributes) {

  xmlParserCtxtPtr ctxt = (xmlParserCtxtPtr) ctx;
  SAX2srcMLHandler * state = (SAX2srcMLHandler *) ctxt->_private;
  state->is_archive = strcmp((const char *)localname, "unit") == 0 && strcmp((const char *)URI, SRCML_SRC_NS_URI) == 0;

  if(!state->is_archive) {
    state->process->startUnit(state->root.localname, state->root.prefix, state->root.URI,
                               state->root.nb_namespaces, state->root.namespaces, state->root.nb_attributes,
                               state->root.nb_defaulted, state->root.attributes);
    state->process->startElementNs(localname, prefix, URI,
                               nb_namespaces, namespaces, nb_attributes,
                               nb_defaulted, attributes);
  } else
    state->process->startUnit(localname, prefix, URI,
                               nb_namespaces, namespaces, nb_attributes,
                               nb_defaulted, attributes);

  ctxt->sax->startElementNs = &startElementNs;    

}

/**
 * startUnit
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
void startUnit(void * ctx, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                           int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                    const xmlChar ** attributes) {

  xmlParserCtxtPtr ctxt = (xmlParserCtxtPtr) ctx;
  SAX2srcMLHandler * state = (SAX2srcMLHandler *) ctxt->_private;

  state->process->startUnit(localname, prefix, URI, nb_namespaces, namespaces, nb_attributes, nb_defaulted, attributes);
  ctxt->sax->startElementNs = &startElementNs;    

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

/**
 * endElementNs
 * @param ctx an xmlParserCtxtPtr
 * @param localname the name of the element tag
 * @param prefix the tag prefix
 * @param URI the namespace of tag
 *
 * SAX handler function for end of an element.
 * Immediately calls supplied handlers function.
 */
void endElementNs(void * ctx, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

  xmlParserCtxtPtr ctxt = (xmlParserCtxtPtr) ctx;
  SAX2srcMLHandler * state = (SAX2srcMLHandler *) ctxt->_private;

  if(strcmp((const char *)localname, "unit") == 0 && strcmp((const char *)URI, SRCML_SRC_NS_URI) == 0) {

    if(ctxt->sax->startElementNs == &startUnit) {

      state->process->endRoot(localname, prefix, URI);

    } else {

      state->process->endUnit(localname, prefix, URI);
      ctxt->sax->startElementNs = &startUnit;    

    }

  } else
    state->process->endElementNs(localname, prefix, URI);

}

/**
 * characters
 * @param ctx an xmlParserCtxtPtr
 * @param ch the characers
 * @param len number of characters
 *
 * SAX handler function for character handling.
 * Immediately calls supplied handlers function.
 */
void characters(void * ctx, const xmlChar * ch, int len) {

  xmlParserCtxtPtr ctxt = (xmlParserCtxtPtr) ctx;
  SAX2srcMLHandler * state = (SAX2srcMLHandler *) ctxt->_private;

  state->process->characters(ch, len);
}
