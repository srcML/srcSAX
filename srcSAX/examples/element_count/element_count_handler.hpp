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

    /** map to count srcML elements */
    std::map<std::string, unsigned long long> element_counts;

public :

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

    /**
     * get_counts
     *
     * Accessor method to get the element counts.
     *
     * @returns the element count map.
     */
    const std::map<std::string, unsigned long long> & get_counts() const {

        return element_counts;

    }

    /**
     * update_count
     * @param prefix the element's prefix
     * @param localname the element name
     *
     * Helper function to update the count of an element or add it if necessary.
     * Need the full name (prefix + localname) of elemement to disambiguate between
     * elements with the same name, but different prefix/namespaces (e.g. cpp:if, if).
     * A more general find approach is used instead of relying on access using the
     * operator[] to default non-existant items to 0. 
     */
    void update_count(const char * prefix, const char * localname) {

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
     * @param num_namespaces number of namespaces definitions
     * @param namespaces the defined namespaces
     * @param num_attributes the number of attributes on the tag
     * @param attributes list of attributes
     *
     * SAX handler function for start of the root element.
     * Counts the root unit (if an archive, to avoid double count with startUnit).
     * Overide for desired behaviour.
     */
    virtual void startRoot(const char * localname, const char * prefix, const char * URI,
                           int num_namespaces, const struct srcsax_namespace * namespaces, int num_attributes,
                           const struct srcsax_attribute * attributes) {

        if(is_archive)
            update_count(prefix, localname);

    }

    /**
     * startUnit
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     * @param num_namespaces number of namespaces definitions
     * @param namespaces the defined namespaces
     * @param num_attributes the number of attributes on the tag
     * @param attributes list of attributes
     *
     * SAX handler function for start of an unit.
     * Counts each unit tag (= filecount non-archive, = filecount + 1 if archive).
     * Overide for desired behaviour.
     */
    virtual void startUnit(const char * localname, const char * prefix, const char * URI,
                           int num_namespaces, const struct srcsax_namespace * namespaces, int num_attributes,
                           const struct srcsax_attribute * attributes) {

            update_count(prefix, localname);

    }

    /**
     * startElement
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     * @param num_namespaces number of namespaces definitions
     * @param namespaces the defined namespaces
     * @param num_attributes the number of attributes on the tag
     * @param attributes list of attributes
     *
     * SAX handler function for start of an element.
     * Count each element.
     * Overide for desired behaviour.
     */
    virtual void startElement(const char * localname, const char * prefix, const char * URI,
                                int num_namespaces, const struct srcsax_namespace * namespaces, int num_attributes,
                                const struct srcsax_attribute * attributes) {

        update_count(prefix, localname);

    }

    /*

    // end elements may need to be used if you want to collect only on per file basis or some other granularity.
    virtual void endRoot(const char * localname, const char * prefix, const char * URI) {}
    virtual void endUnit(const char * localname, const char * prefix, const char * URI) {}
    virtual void endElement(const char * localname, const char * prefix, const char * URI) {}

    // Contains information such as stuff used for parsing.  So, probably do not need to count.
    virtual void metaTag(const char* localname, const char* prefix, const char* URI, int num_namespaces, const char** namespaces, int num_attributes, const char** attributes) {}

    // Not typically in srcML documents    
    virtual void comment(const char * value) {}
    virtual void cdataBlock(const char * value, int len) {}
    virtual void processingInstruction(const char * target, const char * data) {}
    */

#pragma GCC diagnostic pop

};

#endif
