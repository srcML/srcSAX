/**
 * @file print_callbacks_handler.hpp
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

#ifndef INCLUDED_PRINT_CALLBACKS_HANDLER_HPP
#define INCLUDED_PRINT_CALLBACKS_HANDLER_HPP

#include <srcSAXHandler.hpp>

class print_callbacks_handler : public srcSAXHandler {

public :

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

  /**
   * startDocument
   *
   * SAX handler function for start of document.
   * Print when callback is called.
   * Overide for desired behaviour.
   */
  virtual void startDocument() {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
    
  }

  /**
   * endDocument
   *
   * SAX handler function for end of document.
   * Print when callback is called.
   * Overide for desired behaviour.
   */
  virtual void endDocument() {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

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
   * @param meta_tags vector of elements composed of metage tags defined after root tag
   *
   * SAX handler function for start of the root element.
   * Print when callback is called.
   * Overide for desired behaviour.
   */
  virtual void startRoot(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
			 int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
			 const xmlChar ** attributes, std::vector<srcMLElement> * meta_tags) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

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
   * Print when callback is called.
   * Overide for desired behaviour.
   */
  virtual void startUnit(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                           int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                      const xmlChar ** attributes) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  /**
   * startFunction
   * @param name the function's name
   * @param return_type the function return type
   * @param parameter_list a list of the function parameters in struct containing (declaration.type/declaration.name)
   * @param is_decl indicates if the call is a function declaration (true) or definition (false)
   *
   * SAX handler function for start of function with prototype.
   * Accessing references after callback termination is undefined.
   * Print when callback is called.
   *
   * Overide for desired behaviour.
   */
  virtual void startFunction(const std::string & name, const std::string & return_type, const std::vector<declaration> & parameter_list, bool is_decl) {

   fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

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
   * Print when callback is called.
   * 
   * Overide for desired behaviour.
   */
  virtual void startElementNs(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                           int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                      const xmlChar ** attributes) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  /**
   * endRoot
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   *
   * SAX handler function for end of the root element.
   * Print when callback is called.
   * 
   * Overide for desired behaviour.
   */
  virtual void endRoot(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  /**
   * endUnit
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   *
   * SAX handler function for end of an unit.
   * Print when callback is called.
   * 
   * Overide for desired behaviour.
   */
  virtual void endUnit(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  /**
   * endFunction
   *
   * SAX handler function for end of a function.
   * Print when callback is called.
   *
   * Overide for desired behaviour.
   */
  virtual void endFunction() {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  /**
   * endElementNs
   * @param localname the name of the element tag
   * @param prefix the tag prefix
   * @param URI the namespace of tag
   *
   * SAX handler function for end of an element.
   * Print when callback is called.
   *
   * Overide for desired behaviour.
   */
  virtual void endElementNs(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  /**
   * charactersRoot
   * @param ch the characers
   * @param len number of characters
   *
   * SAX handler function for character handling at the root level.
   * Print when callback is called.
   * 
   * Overide for desired behaviour.
   */
  virtual void charactersRoot(const xmlChar * ch, int len) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  /**
   * charactersUnit
   * @param ch the characers
   * @param len number of characters
   *
   * SAX handler function for character handling within a unit.
   * Print when callback is called.
   *
   * Overide for desired behaviour.
   */
  virtual void charactersUnit(const xmlChar * ch, int len) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  /**
   * comment
   * @param value the comment content
   *
   * A comment has been parsed.
   * Print when callback is called.
   *
   * Overide for desired behaviour.
   */
  virtual void comment(const xmlChar * value) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  /**
   * cdataBlock
   * @param value the pcdata content
   * @param len the block length
   *
   * Called when a pcdata block has been parsed.
   * Print when callback is called.
   * 
   * Overide for desired behaviour.
   */
  virtual void cdataBlock(const xmlChar * value, int len) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  /**
   * processingInstruction
   * @param target the processing instruction target.
   * @param data the processing instruction data.
   *
   * Called when a processing instruction has been parsed.
   * Print when callback is called.
   *
   * Overide for desired behaviour.
   */
  virtual void processingInstruction(const xmlChar * target, const xmlChar * data) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

#pragma GCC diagnostic pop

};

#endif
