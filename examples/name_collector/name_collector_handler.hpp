/**
 * @file nameColloctorHandler.hpp
 *
 */

#ifndef INCLUDED_NAME_COLLECTOR_HANDLER_HPP
#define INCLUDED_NAME_COLLECTOR_HANDLER_HPP

#include <libxml/xmlwriter.h>
#include <srcSAXHandler.hpp>
#include <iostream>
#include <string>
#include <vector>


/**
 * name_collector_handler
 * Base class that provides hooks for SAX processing
 *
 * This handler collect all the names in a single file (in srcML).
 * It creates a stack so the syntactic category of the name can be
 *  determined.
 *  Currently it prints out just user defined names.  But can easily
 *  print out all names.
 *  
 */
class name_collector_handler : public srcSAXHandler {
public:
    name_collector_handler() : collectContent(false), content() {};
    ~name_collector_handler() {};

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

      elementStack.push_back(localname);
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
                              int num_namespaces, const struct srcsax_namespace * namespaces,
                              int nb_attributes, const struct srcsax_attribute * attributes) {

          // check localname if it is a name and look at stack to see what it is in.
          // names can be nested, so you might only want to do this for top-level names
          // If you want to gather the text, then you need to set a flag when you start collecting (start_element)
          // stop when down (end_element)


          // this is adding all elements, so you might only want to push certain elements

        if ( elementStack.back() == "name")
            elementStack.push_back("name2");
        else
            elementStack.push_back(localname);
        if (std::string(localname) == "name") {
            collectContent = true;
        }

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
        elementStack.pop_back();
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
        if ((std::string(localname) == "name") && (content != ""))  {
            std::string category;
            if (elementStack.back() == "name2")
                category = elementStack[elementStack.size()-3];// <name> <name>
            else
                category = elementStack[elementStack.size()-2]; //Normal name

            //Only interested in: decl, function, class, struct, enum, typedef

            if ((category == "decl")   || (category == "function") || (category == "class") ||
                (category == "struct") || (category == "enum")     || (category == "typedef")) {
                std::cout << "Identifier: " << content << std::endl;
                std::cout << "Category: " << category << " name" << std::endl;

                /* Print the stack
                std::cout << "Stack: " ;
                for (int i=elementStack.size()-1; i>=0; --i) {
                    std::cout << elementStack[i] << ", ";
                }
                std::cout <<  std::endl;
                 */
                std::cout <<  std::endl;
            }

            content = "";
            collectContent = false;
        }
        elementStack.pop_back();
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
        if (collectContent) {
            content.append((const char *)ch, len);
        }

    }

    /*
    // Not typically in srcML documents 
    virtual void metaTag(const char* localname, const char* prefix, const char* URI,
                           int num_namespaces, const struct srcsax_namespace * namespaces, int nb_attributes,
                           const struct srcsax_attribute * attributes) {}
    virtual void comment(const char* value) {}
    virtual void cdataBlock(const char* value, int len) {}
    virtual void processingInstruction(const char* target, const char* data) {}
    */

#pragma GCC diagnostic pop

private:
    bool                     collectContent;
    std::string              content;
    std::vector<std::string> elementStack;

};

#endif
