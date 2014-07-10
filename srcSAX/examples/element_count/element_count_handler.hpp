/**
 * @file element_count_handler.hpp
 *
 * @copyright Copyright (C) 2013-2014 SDML (www.srcML.org)
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

#ifndef INCLUDED_ELEMENT_COUNT_HANDLER_HPP
#define INCLUDED_ELEMENT_COUNT_HANDLER_HPP

#include <srcSAXHandler.hpp>
#include <map>

/**
 * element_count_handler
 *
 * Base class that provides hooks for SAX processing.
 */
class element_count_handler : public srcSAXHandler {

private :

    std::map<std::string, unsigned long long> element_counts;

public :

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

    const std::map<std::string, unsigned long long> & get_counts() const {

        return element_counts;

    }

    void update_count(const xmlChar * prefix, const xmlChar * localname) {

        std::string element = "";
        if(prefix) {

            element += (const char *)prefix;
            element += ":";

        }
        element += (const char *)localname;

        /* Note: in map could just use operator[], however, this a bit more general */
        std::map<std::string, unsigned long long>::iterator itr = element_counts.find(element);
        if(itr == element_counts.end()) {

            element_counts.insert(std::pair<std::string, unsigned long long>(element, 1));

        } else {

            ++itr->second;

        }

    }

    /*
    virtual void startDocument() {}
    virtual void endDocument() {}
    */

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

        update_count(prefix, localname);

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

        if(is_archive)
            update_count(prefix, localname);

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

        update_count(prefix, localname);

    }

    /*

    // end elements may need to be used to end if you want to collect only on per file basis.
    virtual void endRoot(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {}
    virtual void endUnit(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {}
    virtual void endElementNs(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {}
    virtual void comment(const xmlChar * value) {}
    virtual void cdataBlock(const xmlChar * value, int len) {}
    */

#pragma GCC diagnostic pop

};

#endif
