/**
 * @file srcMLHandlerTest.hpp
 *
 * @copyright Copyright (C) 2013-2014  SDML (www.srcML.org)
 *
 * The srcML Toolkit is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * The srcML Toolkit is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the srcML Toolkit; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef INCLUDED_SRCML_HANDLER_TEST_HPP
#define INCLUDED_SRCML_HANDLER_TEST_HPP

#include <srcSAXHandler.hpp>

#include <libxml/parser.h>

/**
 * srcMLHandlerTest
 *
 * Base class that provides hooks for SAX processing.
 */
class srcMLHandlerTest : public srcSAXHandler {

public :

  int start_document;
  int end_document;

  int start_root;
  int start_unit;
  int start_element_ns;

  int end_root;
  int end_unit;
  int end_element_ns;

  int characters_root;
  int characters_unit;

  int comment_;
  int cdata_block;

  int call_count;

  srcMLHandlerTest() 
    : start_document(0), end_document(0), start_root(0), start_unit(0), start_element_ns(0),
      end_root(0), end_unit(0), end_element_ns(0), characters_root(0), characters_unit(0),
      comment_(0), cdata_block(0), call_count(0) {}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

  /**
   * startDocument
   *
   * SAX handler function for start of document.
   * Overide for desired behaviour.
   */
  virtual void startDocument() { 

    start_document = ++call_count;

  }

  /**
   * endDocument
   *
   * SAX handler function for end of document.
   * Overide for desired behaviour.
   */
  virtual void endDocument() {

    end_document = ++call_count;

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
                         const xmlChar ** attributes, std::vector<srcMLElement> * meta_tags) {

    start_root = ++call_count;

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

    start_unit = ++call_count;

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
    start_element_ns = ++call_count;

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

    end_root = ++call_count;

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

    end_unit = ++call_count;

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

    end_element_ns = ++call_count;

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

    characters_root = ++call_count;

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

    characters_unit = ++call_count;

  }

  /**
   * comment
   * @param value the comment content
   *
   * A comment has been parsed.
   * Overide for desired behaviour.
   */
  virtual void comment(const xmlChar * value) {

    comment_ = ++call_count;

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

    cdata_block = ++call_count;

  }

#pragma GCC diagnostic pop

};

#endif
