// SPDX-License-Identifier: GPL-3.0-only
/**
 * @file srcsax.h
 *
 * @copyright Copyright (C) 2013-2026 srcML, LLC. (www.srcML.org)
 *
 * This file is part of the srcML Infrastructure.
 */

#ifndef INCLUDED_SRCSAX_H
#define INCLUDED_SRCSAX_H

#include <libxml/parser.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function export macro */
#if defined(WIN32) && !defined(__MINGW32__)
#define SRCSAX_EXPORT __declspec(dllexport)
#else
#define SRCSAX_EXPORT
#endif

/** srcsax_controller api */

/**
 * srcsax_context
 *
 * Context data structure passed between callbacks.
 */
struct srcsax_context {

    /** user provided data */
    void* data;

    /** srcSAX handler callbacks */
    struct srcsax_handler* handler;

    /** error callback need to figure this one out probably message and errorcode. or struct.  Might not need, but might be nice to avoid libxml2 stuff */
    void (*srcsax_error)(const char* message, int error_code);

    /** is the document an archive */
    int is_archive;

    /** the current unit count */
    int unit_count;

    /** size of the srcml_element stack */
    size_t stack_size;

    /** stack of open srcML elements */
    const char** srcml_element_stack;

    /** the xml documents encoding */
    const char* encoding;

    /* Internal context handling NOT FOR PUBLIC USE */

    /** xml parser input buffer */
    xmlParserInputBufferPtr input;

    /** boolean to indicate need to free input buffer */
    int free_input;

    /** internally used libxml2 context */
    xmlParserCtxtPtr libxml2_context;

    /** indicate stop parser */
    int terminate;

};

/* srcSAX context creation/open functions */
SRCSAX_EXPORT struct srcsax_context* srcsax_create_context_filename(const char* filename, const char* encoding);
SRCSAX_EXPORT struct srcsax_context* srcsax_create_context_memory(const char* buffer, size_t buffer_size, const char* encoding);
SRCSAX_EXPORT struct srcsax_context* srcsax_create_context_FILE(FILE * srcml_file, const char* encoding);
SRCSAX_EXPORT struct srcsax_context* srcsax_create_context_fd(int srcml_fd, const char* encoding);
SRCSAX_EXPORT struct srcsax_context* srcsax_create_context_io(void* srcml_context, int (*read_callback)(void* context, char* buffer, int len), int (*close_callback)(void* context), const char* encoding);
SRCSAX_EXPORT struct srcsax_context* srcsax_create_context_parser_input_buffer(xmlParserInputBufferPtr input);

/* srcSAX free function */
SRCSAX_EXPORT void srcsax_free_context(struct srcsax_context* context);

/* srcSAX parse function */
SRCSAX_EXPORT int srcsax_parse(struct srcsax_context* context);
SRCSAX_EXPORT int srcsax_parse_handler(struct srcsax_context* context, struct srcsax_handler* handler);

/* srcSAX terminate parse function */
SRCSAX_EXPORT void srcsax_stop_parser(struct srcsax_context* context);

/** srcsax_handler api */


/**
 * srcsax_namespace
 *
 * Data structure for a srcML/xml namespace
 */
struct srcsax_namespace {

    /** a namespace prefix */
    const char* prefix;

    /** a namespace uri */
    const char* uri;

};

/**
 * srcsax_attribute
 *
 * Data structure for a srcML/xml attribute
 */
 struct srcsax_attribute {

    /** attribute name */
    const char* localname;

    /** attribute namespace prefix */
    const char* prefix;

    /** attribute namespace uri */
    const char* uri;

    /** attribute value */
    const char* value;

};

/**
 * srcsax_handler
 *
 * Struct of srcSAX callback functions i.e. srcSAX handler.
 */
struct srcsax_handler {

/**
 * start_document
 * @param context a srcSAX context
 *
 * Signature for srcSAX handler function for start of document.
 */
void (*start_document)(struct srcsax_context* context);

/**
 * end_document
 * @param context a srcSAX context
 *
 * Signature for srcSAX handler function for end of document.
 */
void (*end_document)(struct srcsax_context* context);

/**
 * start_root
 * @param context a srcSAX context
 * @param localname the name of the element tag
 * @param prefix the tag prefix
 * @param URI the namespace of tag
 * @param num_namespaces number of namespaces definitions
 * @param namespaces the defined namespaces
 * @param num_attributes the number of attributes on the tag
 * @param attributes list of attributes
 *
 * Signature for srcSAX handler function for start of the root element.
 */
void (*start_root)(struct srcsax_context* context, const char* localname, const char* prefix, const char* URI,
                       int num_namespaces, const struct srcsax_namespace* namespaces, int num_attributes,
                       const struct srcsax_attribute* attributes);

/**
 * start_unit
 * @param context a srcSAX context
 * @param localname the name of the element tag
 * @param prefix the tag prefix
 * @param URI the namespace of tag
 * @param num_namespaces number of namespaces definitions
 * @param namespaces the defined namespaces
 * @param num_attributes the number of attributes on the tag
 * @param attributes list of attributes
 *
 * Signature srcSAX handler function for start of an unit.
 */
void (*start_unit)(struct srcsax_context* context, const char* localname, const char* prefix, const char* URI,
                       int num_namespaces, const struct srcsax_namespace* namespaces, int num_attributes,
                       const struct srcsax_attribute* attributes);

/**
 * start_function
 * @param context a srcSAX context
 * @param name the function's name
 * @param return_type the function return type
 * @param parameter_list a list of the function parameters in struct containing (declaration.type/declaration.name)
 * @param is_decl indicates if the call is a function declaration (true) or definition (false)
 *
 * Signature for srcSAX handler function for start of function with prototype.
 */
//void (*start_function(struct srcsax_context* context, const char* name, const char* return_type, const struct declaration * parameter_list, _Bool is_decl);

/**
 * start_element
 * @param context a srcSAX context
 * @param localname the name of the element tag
 * @param prefix the tag prefix
 * @param URI the namespace of tag
 * @param num_namespaces number of namespaces definitions
 * @param namespaces the defined namespaces
 * @param num_attributes the number of attributes on the tag
 * @param attributes list of attributes
 *
 * Signature for srcSAX handler function for start of an element.
 */
void (*start_element)(struct srcsax_context* context, const char* localname, const char* prefix, const char* URI,
                            int num_namespaces, const struct srcsax_namespace* namespaces, int num_attributes,
                            const struct srcsax_attribute* attributes);

/**
 * end_root
 * @param context a srcSAX context
 * @param localname the name of the element tag
 * @param prefix the tag prefix
 * @param URI the namespace of tag
 *
 * Signature for srcSAX handler function for end of the root element.
 */
void (*end_root)(struct srcsax_context* context, const char* localname, const char* prefix, const char* URI);

/**
 * end_unit
 * @param context a srcSAX context
 * @param localname the name of the element tag
 * @param prefix the tag prefix
 * @param URI the namespace of tag
 *
 * Signature for srcSAX handler function for end of an unit.
 */
void (*end_unit)(struct srcsax_context* context, const char* localname, const char* prefix, const char* URI);

/**
 * end_function
 * @param context a srcSAX context
 *
 * Signature for srcSAX handler function for end of a function.
 */
//void (*end_function(struct srcsax_context* context);

/**
 * end_element
 * @param context a srcSAX context
 * @param localname the name of the element tag
 * @param prefix the tag prefix
 * @param URI the namespace of tag
 *
 * Signature for srcSAX handler function for end of an element.
 */
void (*end_element)(struct srcsax_context* context, const char* localname, const char* prefix, const char* URI);

/**
 * characters_root
 * @param context a srcSAX context
 * @param ch the characers
 * @param len number of characters
 *
 * Signature for srcSAX handler function for character handling at the root level.
 */
void (*characters_root)(struct srcsax_context* context, const char* ch, int len);

/**
 * characters_unit
 * @param ch the characers
 * @param len number of characters
 *
 * Signature for srcSAX handler function for character handling within a unit.
 */
void (*characters_unit)(struct srcsax_context* context, const char* ch, int len);

/**
 * meta_tag
 * @param context a srcSAX context
 * @param localname the name of the element tag
 * @param prefix the tag prefix
 * @param URI the namespace of tag
 * @param num_namespaces number of namespaces definitions
 * @param namespaces the defined namespaces
 * @param num_attributes the number of attributes on the tag
 * @param attributes list of attributes
 *
 * Signature for srcSAX handler function for meta tags.
 */
void (*meta_tag)(struct srcsax_context* context, const char* localname, const char* prefix, const char* URI,
                       int num_namespaces, const struct srcsax_namespace* namespaces, int num_attributes,
                       const struct srcsax_attribute* attributes);

/**
 * comment
 * @param context a srcSAX context
 * @param value the comment content
 *
 * Signature for srcSAX handler function for a XML comment.
 */
void (*comment)(struct srcsax_context* context, const char* value);

/**
 * cdata_block
 * @param context a srcSAX context
 * @param value the pcdata content
 * @param len the block length
 *
 * Signature for srcSAX handler function for pcdata block.
 */
void (*cdata_block)(struct srcsax_context* context, const char* value, int len);

/**
 * processing_instruction
 * @param context a srcSAX context
 * @param target the processing instruction target.
 * @param data the processing instruction data.
 *
 * Signature for srcSAX handler function for processing instruction.
 */
void (*processing_instruction)(struct srcsax_context* context, const char* target, const char* data);

};


#ifdef __cplusplus
}
#endif

#endif
