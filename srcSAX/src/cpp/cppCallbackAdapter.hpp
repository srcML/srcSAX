
class cppCallbackAdapter {

private:
    srcSAXHandler * handler;

public:

    cppCallbackAdapter(srcSAXHandler * handler) : handler(handler) {}

    static srcsax_handler factory() {

        srcsax_handler handler;

        handler.start_document = start_document;
        handler.end_document = end_document;
        handler.start_root = start_root;
        handler.start_unit = start_unit;
        handler.start_element_ns = start_element_ns;
        handler.end_root = end_root;
        handler.end_unit = end_unit;
        handler.end_element_ns = end_element_ns;
        handler.characters_root = characters_root;
        handler.characters_unit = characters_unit;
        handler.comment = comment;
        handler.cdata_block = cdata_block;
        handler.processing_instruction = processing_instruction;

        return handler;

    }

    /**
     * start_document
     *
     * Signature for srcSAX handler function for start of document.
     */
    static void start_document(struct srcsax_context * context) {

        cppCallbackAdapter * cpp_adapter = (cppCallbackAdapter *)context->data;

        cpp_adapter->handler->startDocument();

    }

    /**
     * end_document
     *
     * Signature for srcSAX handler function for end of document.
     */
    static void end_document(struct srcsax_context * context) {

        cppCallbackAdapter * cpp_adapter = (cppCallbackAdapter *)context->data;

        cpp_adapter->handler->endDocument();


    }

    /**
     * start_root
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     * @param nb_namespaces number of namespaces definitions
     * @param namespaces the defined namespaces
     * @param nb_attributes the number of attributes on the tag
     * @param nb_defaulted the number of defaulted attributes
     * @param attributes list of attribute name value pairs (localname/prefix/URI/value/end)
     * @param nb_meta_tags number of meta tags
     * @param meta_tags vector of elements composed of metage tags defined after root tag
     *
     * Signature for srcSAX handler function for start of the root element.
     */
    static void start_root(struct srcsax_context * context, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                           int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                           const xmlChar ** attributes, size_t nb_meta_tags, struct srcml_element * meta_tags[]) {

        cppCallbackAdapter * cpp_adapter = (cppCallbackAdapter *)context->data;

        std::vector<srcml_element *> meta_tags_vector(nb_meta_tags);
        for(size_t i = 0; i < nb_meta_tags; ++i)
            meta_tags_vector.push_back(meta_tags[i]);

        cpp_adapter->handler->startRoot(localname, prefix, URI, nb_namespaces, namespaces, nb_attributes, nb_defaulted, attributes, &meta_tags_vector);

    }

    /**
     * start_unit
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     * @param nb_namespaces number of namespaces definitions
     * @param namespaces the defined namespaces
     * @param nb_attributes the number of attributes on the tag
     * @param nb_defaulted the number of defaulted attributes
     * @param attributes list of attribute name value pairs (localname/prefix/URI/value/end)
     *
     * Signature srcSAX handler function for start of an unit.
     * Overide for desired behaviour.
     */
    static void start_unit(struct srcsax_context * context, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                           int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                           const xmlChar ** attributes) {

        cppCallbackAdapter * cpp_adapter = (cppCallbackAdapter *)context->data;

        cpp_adapter->handler->startUnit(localname, prefix, URI, nb_namespaces, namespaces, nb_attributes, nb_defaulted, attributes);


    }

    /**
     * start_function
     * @param name the function's name
     * @param return_type the function return type
     * @param parameter_list a list of the function parameters in struct containing (declaration.type/declaration.name)
     * @param is_decl indicates if the call is a function declaration (true) or definition (false)
     *
     * Signature for srcSAX handler function for start of function with prototype.
     * Accessing references after callback termination is undefined.

     */
/*   
     static void start_functionconst char * name, const char * return_type, const struct declaration * parameter_list, _Bool is_decl) {

        cppCallbackAdapter * cpp_adapter = (cppCallbackAdapter *)context->data;


     }
*/

    /**
     * start_element_ns
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     * @param nb_namespaces number of namespaces definitions
     * @param namespaces the defined namespaces
     * @param nb_attributes the number of attributes on the tag
     * @param nb_defaulted the number of defaulted attributes
     * @param attributes list of attribute name value pairs (localname/prefix/URI/value/end)
     *
     * Signature for srcSAX handler function for start of an element.
     */
    static void start_element_ns(struct srcsax_context * context, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                                int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                                const xmlChar ** attributes) {

        cppCallbackAdapter * cpp_adapter = (cppCallbackAdapter *)context->data;

        cpp_adapter->handler->startElementNs(localname, prefix, URI, nb_namespaces, namespaces, nb_attributes, nb_defaulted, attributes);


    }

    /**
     * end_root
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     *
     * Signature for srcSAX handler function for end of the root element.
     */
    static void end_root(struct srcsax_context * context, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

        cppCallbackAdapter * cpp_adapter = (cppCallbackAdapter *)context->data;

        cpp_adapter->handler->endRoot(localname, prefix, URI);

    }

    /**
     * end_unit
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     *
     * Signature for srcSAX handler function for end of an unit.
     */
    static void end_unit(struct srcsax_context * context, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

        cppCallbackAdapter * cpp_adapter = (cppCallbackAdapter *)context->data;

        cpp_adapter->handler->endUnit(localname, prefix, URI);

    }

    /**
     * end_function
     *
     * Signature for srcSAX handler function for end of a function.
     */
 /*
    static void end_function) {

        cppCallbackAdapter * cpp_adapter = (cppCallbackAdapter *)context->data;


    }
*/
    /**
     * end_element_ns
     * @param localname the name of the element tag
     * @param prefix the tag prefix
     * @param URI the namespace of tag
     *
     * Signature for srcSAX handler function for end of an element.
     */
    static void end_element_ns(struct srcsax_context * context, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

        cppCallbackAdapter * cpp_adapter = (cppCallbackAdapter *)context->data;

        cpp_adapter->handler->endElementNs(localname, prefix, URI);

    }

    /**
     * characters_root
     * @param ch the characers
     * @param len number of characters
     *
     * Signature for srcSAX handler function for character handling at the root level.
     */
    static void characters_root(struct srcsax_context * context, const xmlChar * ch, int len) {

        cppCallbackAdapter * cpp_adapter = (cppCallbackAdapter *)context->data;

        cpp_adapter->handler->charactersRoot(ch, len);


    }

    /**
     * characters_unit
     * @param ch the characers
     * @param len number of characters
     *
     * Signature for srcSAX handler function for character handling within a unit.
     */
    static void characters_unit(struct srcsax_context * context, const xmlChar * ch, int len) {

        cppCallbackAdapter * cpp_adapter = (cppCallbackAdapter *)context->data;

        cpp_adapter->handler->charactersUnit(ch, len);

    }

    /**
     * comment
     * @param value the comment content
     *
     * Signature for srcSAX handler function for a XML comment.
     */
    static void comment(struct srcsax_context * context, const xmlChar * value) {

        cppCallbackAdapter * cpp_adapter = (cppCallbackAdapter *)context->data;

        cpp_adapter->handler->comment(value);

    }

    /**
     * cdata_block
     * @param value the pcdata content
     * @param len the block length
     *
     * Signature for srcSAX handler function for pcdata block.
     */
    static void cdata_block(struct srcsax_context * context, const xmlChar * value, int len) {

        cppCallbackAdapter * cpp_adapter = (cppCallbackAdapter *)context->data;

        cpp_adapter->handler->cdataBlock(value, len);

    }

    /**
     * processing_instruction
     * @param target the processing instruction target.
     * @param data the processing instruction data.
     *
     * Signature for srcSAX handler function for processing instruction
     */
    static void processing_instruction(struct srcsax_context * context, const xmlChar * target, const xmlChar * data) {

        cppCallbackAdapter * cpp_adapter = (cppCallbackAdapter *)context->data;

        cpp_adapter->handler->processingInstruction(target, data);

    }

};
