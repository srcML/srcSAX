
/*
  srcMLHandler.hpp

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

#ifndef INCLUDED_SRCML_HANDLER_TEST_HPP
#define INCLUDED_SRCML_HANDLER_TEST_HPP

#include <srcMLHandler.hpp>

#include <libxml/parser.h>

/**
 * srcMLHandlerTest
 *
 * Base class that provides hooks for SAX processing.
 */
class srcMLHandlerTest : public srcMLHandler {

public :

  bool start_document;
  bool end_document;

  bool start_root;
  bool start_unit;
  bool start_element_ns;

  bool end_root;
  bool end_unit;
  bool end_element_ns;

  bool characters_root;
  bool characters_unit;

  bool comment_;
  bool cdata_block;

  srcMLHandlerTest() 
    : start_document(false), end_document(false), start_root(false), start_unit(false), start_element_ns(false),
      end_root(false), end_unit(false), end_element_ns(false), characters_root(false), characters_unit(false),
      comment_(false), cdata_block(false) {}

  /**
   * startDocument
   *
   * SAX handler function for start of document.
   * Overide for desired behaviour.
   */
  virtual void startDocument() { 

    start_document = true;

  }

  /**
   * endDocument
   *
   * SAX handler function for end of document.
   * Overide for desired behaviour.
   */
  virtual void endDocument() {

    end_document = true;

  }

  /**
   * startRoot
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   * @param nb_namespaces number of namespaces definitions
   * @param namespaces the defined namespaces
   * @param nb_attributes the number of attributes on the tag
   * @param nb_defaulted the number of defaulted attributes
   * @param attributes list of attribute name value pairs (localname/prefix/URI/value/end)
   *
   * SAX handler function for start of the root element.
   * Overide for desired behaviour.
   */
  virtual void startRoot(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                         int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                         const xmlChar ** attributes) {

    start_root = true;

  }

  /**
   * startUnit
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   * @param nb_namespaces number of namespaces definitions
   * @param namespaces the defined namespaces
   * @param nb_attributes the number of attributes on the tag
   * @param nb_defaulted the number of defaulted attributes
   * @param attributes list of attribute name value pairs (localname/prefix/URI/value/end)
   *
   * SAX handler function for start of an unit.
   * Overide for desired behaviour.
   */
  virtual void startUnit(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                         int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                         const xmlChar ** attributes) {

    start_unit = true;

  }

  /**
   * startElementNs
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
   * Overide for desired behaviour.
   */
  virtual void startElementNs(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                              int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                              const xmlChar ** attributes) {
    start_element_ns = true;

  }

  /**
   * endRoot
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   *
   * SAX handler function for end of the root element.
   * Overide for desired behaviour.
   */
  virtual void endRoot(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

    end_root = true;

  }

  /**
   * endUnit
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   *
   * SAX handler function for end of an unit.
   * Overide for desired behaviour.
   */
  virtual void endUnit(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

    end_unit = true;

  }

  /**
   * endElementNs
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   *
   * SAX handler function for end of an element.
   * Overide for desired behaviour.
   */
  virtual void endElementNs(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

    end_element_ns = true;

  }

  /**
   * charactersRoot
   * @param ch the characers
   * @param len number of characters
   *
   * SAX handler function for character handling at the root level.
   * Overide for desired behaviour.
   */
  virtual void charactersRoot(const xmlChar * ch, int len) {

    characters_root = true;

  }

  /**
   * charactersUnit
   * @param ch the characers
   * @param len number of characters
   *
   * SAX handler function for character handling within a unit.
   * Overide for desired behaviour.
   */
  virtual void charactersUnit(const xmlChar * ch, int len) {

    characters_unit = true;

  }

  /**
   * comment
   * @param value the comment content
   *
   * A comment has been parsed.
   * Overide for desired behaviour.
   */
  virtual void comment(const xmlChar * value) {

    comment_ = true;

  }

  /**
   * cdataBlock
   * @param value the pcdata content
   * @param len the block length
   *
   * Called when a pcdata block has been parsed.
   * Overide for desired behaviour.
   */
  virtual void cdataBlock(const xmlChar * value, int len) {

    cdata_block = true;

  }

};

#endif
