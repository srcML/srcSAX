/**
 * @file identity_copy_handler.hpp
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

#ifndef INCLUDED_IDENTITY_COPY_HANDLER_HPP
#define INCLUDED_IDENTITY_COPY_HANDLER_HPP

#include <srcSAXHandler.hpp>
#include <iostream>
#include <string>

#include <libxml/xmlwriter.h>

/**
 * identity_copy_handler
 *
 * Base class that provides hooks for SAX processing.
 */
class identity_copy_handler : public srcSAXHandler {

private :

    xmlTextWriterPtr writer;
    std::string content;

public :

    /**
     * identity_copy_handler
     *
     * Constructor.  Open xmlwriter. 
     */
    identity_copy_handler(std::string output_filename) : writer(0) {

        if((writer = xmlNewTextWriterFilename(output_filename.c_str(), 0)) == 0) {

            std::cerr << "Problems opening output file: " << output_filename << '\n';
            exit(1);

        }

    }

    /**
     * ~identity_copy_handler
     *
     * Destructor. Free writer resource.
     */
    ~identity_copy_handler() {

        if(writer)
            xmlFreeTextWriter(writer);

    }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

    /**
     * startDocument
     *
     * SAX handler function for start of document.
     * Write start of xml document.
     *
     * Overide for desired behaviour.
     */
    virtual void startDocument() {

        xmlTextWriterStartDocument(writer, "1.0", "UTF-8", "yes");

    }

    /**
     * endDocument
     *
     * SAX handler function for end of document.
     * Write the end of xml document.
     *
     * Overide for desired behaviour.
     */
    virtual void endDocument() {

        xmlTextWriterEndDocument(writer);

    }

    /**
     * write_start_tag
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
     * Write out a start tag.
     *
     * Overide for desired behaviour.
     */
    void write_start_tag(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                           int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                           const xmlChar ** attributes) {

        xmlTextWriterStartElementNS(writer, prefix, localname, 0);

        for(int i = 0, index = 0; i < nb_namespaces; ++i, index += 2) {

            std::string name = "xmlns";
            if(namespaces[index]) {
                name += ":";

                name += (const char *)namespaces[index];

            }

            xmlTextWriterWriteAttribute(writer, (const xmlChar *)name.c_str(), namespaces[index + 1]);

        }

        for(int i = 0, index = 0; i < nb_attributes; ++i, index += 5) {

            std::string value = "";
            value.append((const char *)attributes[index + 3], attributes[index + 4] - attributes[index + 3]);

            xmlTextWriterWriteAttributeNS(writer, attributes[index + 1], attributes[index], attributes[index + 2], (const xmlChar *)value.c_str());

        }

    }

    /**
     * write_content
     * @param text_content
     *
     * Write out the provided text content, escaping everything but ".
     */
    void write_content(std::string & text_content) {

        if(text_content != "") {

            /*
                Normal output of text is for the most part
                identical to what libxml2 provides.  However,
                srcML does not escape " while libxml2 does escape
                quotations.
            */
            int ret = 0;
            char * text = (char *)text_content.c_str();
            for(char * pos = text; *pos; ++pos) {

              if(*pos != '"') continue;

              *pos = 0;
              ret = xmlTextWriterWriteString(writer, (const xmlChar *)text);
              //if(ret == -1) return false;

              *pos = '\"';
              xmlTextWriterWriteRaw(writer, (const xmlChar *)"\"");
              //if(ret == -1) return false;

              text = pos + 1;

            }

            ret = xmlTextWriterWriteString(writer, (const xmlChar *)text);

            text_content = "";

        }

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
     * Write out the root start tag (unless non-archive, startUnit will handle).
     *
     * Overide for desired behaviour.
     */
    virtual void startRoot(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                           int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                           const xmlChar ** attributes, std::vector<srcml_element *> * meta_tags) {

        if(is_archive)
            write_start_tag(localname, prefix, URI, nb_namespaces, namespaces, nb_attributes, nb_defaulted, attributes);

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
     * Write out any saved text, then write out the unit tag.
     *
     * Overide for desired behaviour.
     */
    virtual void startUnit(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                           int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                           const xmlChar ** attributes) {

        // write out buffered root level characters
        write_content(content);

        write_start_tag(localname, prefix, URI, nb_namespaces, namespaces, nb_attributes, nb_defaulted, attributes);

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
     * Write out any saved text, then write out the elementtag.
     * 
     * Overide for desired behaviour.
     */
    virtual void startElementNs(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                                int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                                const xmlChar ** attributes) {

        // write out buffered characters
        write_content(content);

        write_start_tag(localname, prefix, URI, nb_namespaces, namespaces, nb_attributes, nb_defaulted, attributes);

    }

    /**
     * endRoot
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     *
     * SAX handler function for end of the root element.
     * Write out any saved content, then end the root tag.
     *
     * Overide for desired behaviour.
     */
    virtual void endRoot(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

        // write out buffered root level characters
        if(is_archive) {

            write_content(content);

            xmlTextWriterEndElement(writer);

        }

    }

    /**
     * endUnit
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     *
     * SAX handler function for end of an unit.
     * Write out any saved up content, then write out ending unit tag.
     *
     * Overide for desired behaviour.
     */
    virtual void endUnit(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

        // write out any buffered characters
        write_content(content);

        xmlTextWriterEndElement(writer);

    }

    /**
     * endElementNs
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     *
     * SAX handler function for end of an element.
     * Write out any saved content, then write out ending element tag.
     *
     * Overide for desired behaviour.
     */
    virtual void endElementNs(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

        // write out any buffered characters
        write_content(content);

        xmlTextWriterEndElement(writer);

    }

    /**
     * charactersRoot
     * @param ch the characers
     * @param len number of characters
     *
     * SAX handler function for character handling at the root level.
     * Collect/write root level charactes.
     * 
     * Characters may be called multiple times in succession
     * in some cases the text may need to be gathered all at once
     * before output. Both methods are shown here although the delayed
     * output is used.
     *
     * Overide for desired behaviour.
     */
    virtual void charactersRoot(const xmlChar * ch, int len) {


        //std::string content = "";
        content.append((const char *)ch, len);
        //write_content(content);

    }

    /**
     * charactersUnit
     * @param ch the characers
     * @param len number of characters
     *
     * SAX handler function for character handling within a unit.
     * Collect/write unit level charactes.
     * 
     * Characters may be called multiple times in succession
     * in some cases the text may need to be gathered all at once
     * before output. Both methods are shown here although the delayed
     * output is used.
     * 
     * Overide for desired behaviour.
     */
    virtual void charactersUnit(const xmlChar * ch, int len) {

        /*
            Characters may be called multiple times in succession
            in some cases the text may need to be gathered all at once
            before output. Both methods are shown here although the delayed
            output is used.
        */

        //std::string content = "";
        content.append((const char *)ch, len);
        //write_content(content);

    }

    /*
    virtual void comment(const xmlChar * value) {}
    virtual void cdataBlock(const xmlChar * value, int len) {}
    virtual void processingInstruction(const xmlChar * target, const xmlChar * data) {}
    */

#pragma GCC diagnostic pop

};

#endif
