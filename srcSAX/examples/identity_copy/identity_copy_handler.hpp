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
     * @param num_namespaces number of namespaces definitions
     * @param namespaces the defined namespaces
     * @param nb_attributes the number of attributes on the tag
     * @param attributes list of attributes
     *
     * SAX handler function for start of the root element.
     * Write out a start tag.
     *
     * Overide for desired behaviour.
     */
    void write_start_tag(const char* localname, const char* prefix, const char* URI,
                           int num_namespaces, const struct srcsax_namespace * namespaces, int num_attributes,
                           const struct srcsax_attribute * attributes) {

        xmlTextWriterStartElementNS(writer, (const xmlChar *)prefix, (const xmlChar *)localname, 0);

        for(int pos = 0; pos < num_namespaces; ++pos) {

            std::string name = "xmlns";
            if(namespaces[pos].prefix) {
                name += ":";

                name += (const char *)namespaces[pos].prefix;

            }

            xmlTextWriterWriteAttribute(writer, (const xmlChar *)name.c_str(), (const xmlChar *)namespaces[pos].uri);

        }

        for(int pos = 0; pos < num_attributes; ++pos) {

            xmlTextWriterWriteAttributeNS(writer, (const xmlChar *)attributes[pos].prefix, (const xmlChar *)attributes[pos].localname,
                (const xmlChar *)attributes[pos].uri, (const xmlChar *)attributes[pos].value);

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
     * @param num_namespaces number of namespaces definitions
     * @param namespaces the defined namespaces
     * @param nb_attributes the number of attributes on the tag
     * @param attributes list of attributes
     *
     * SAX handler function for start of the root element.
     * Write out the root start tag (unless non-archive, startUnit will handle).
     *
     * Overide for desired behaviour.
     */
    virtual void startRoot(const char* localname, const char* prefix, const char* URI,
                           int num_namespaces, const struct srcsax_namespace * namespaces, int nb_attributes,
                           const struct srcsax_attribute * attributes) {

        if(is_archive)
            write_start_tag(localname, prefix, URI, num_namespaces, namespaces, nb_attributes, attributes);

    }

    /**
     * startUnit
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     * @param num_namespaces number of namespaces definitions
     * @param namespaces the defined namespaces
     * @param nb_attributes the number of attributes on the tag
     * @param attributes list of attributes
     *
     * SAX handler function for start of an unit.
     * Write out any saved text, then write out the unit tag.
     *
     * Overide for desired behaviour.
     */
    virtual void startUnit(const char* localname, const char* prefix, const char* URI,
                           int num_namespaces, const struct srcsax_namespace * namespaces, int nb_attributes,
                           const struct srcsax_attribute * attributes) {

        // write out buffered root level characters
        write_content(content);

        write_start_tag(localname, prefix, URI, num_namespaces, namespaces, nb_attributes, attributes);

    }

    /**
     * startElement
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     * @param num_namespaces number of namespaces definitions
     * @param namespaces the defined namespaces
     * @param nb_attributes the number of attributes on the tag
     * @param attributes list of attributes
     *
     * SAX handler function for start of an element.
     * Write out any saved text, then write out the elementtag.
     * 
     * Overide for desired behaviour.
     */
    virtual void startElement(const char* localname, const char* prefix, const char* URI,
                                int num_namespaces, const struct srcsax_namespace * namespaces, int nb_attributes,
                                const struct srcsax_attribute * attributes) {

        // write out buffered characters
        write_content(content);

        write_start_tag(localname, prefix, URI, num_namespaces, namespaces, nb_attributes, attributes);

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
    virtual void endRoot(const char* localname, const char* prefix, const char* URI) {

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
    virtual void endUnit(const char* localname, const char* prefix, const char* URI) {

        // write out any buffered characters
        write_content(content);

        xmlTextWriterEndElement(writer);

    }

    /**
     * endElement
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     *
     * SAX handler function for end of an element.
     * Write out any saved content, then write out ending element tag.
     *
     * Overide for desired behaviour.
     */
    virtual void endElement(const char* localname, const char* prefix, const char* URI) {

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
    virtual void charactersRoot(const char* ch, int len) {


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
    virtual void charactersUnit(const char* ch, int len) {

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

    /**
     * metaTag
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     * @param num_namespaces number of namespaces definitions
     * @param namespaces the defined namespaces
     * @param nb_attributes the number of attributes on the tag
     * @param attributes list of attributes
     *
     * SAX handler function for meta tag.
     * Write out the meta tags.
     *
     * Overide for desired behaviour.
     */
    virtual void metaTag(const char* localname, const char* prefix, const char* URI,
                           int num_namespaces, const struct srcsax_namespace * namespaces, int nb_attributes,
                           const struct srcsax_attribute * attributes) {

        // write out any buffered characters
        write_content(content);

        write_start_tag(localname, prefix, URI, num_namespaces, namespaces, nb_attributes, attributes);
        xmlTextWriterEndElement(writer);

    }

    /*
    // Not typically in srcML documents 
    virtual void comment(const char* value) {}
    virtual void cdataBlock(const char* value, int len) {}
    virtual void processingInstruction(const char* target, const char* data) {}
    */

#pragma GCC diagnostic pop

};

#endif
