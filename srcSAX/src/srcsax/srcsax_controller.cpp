/**
 * @file srcsax_controller.cpp
 *
 * @copyright Copyright (C) 2013-2014 SDML (www.srcML.org)
 *
 * srcSAX is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * srcSAX is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the srcML Toolkit; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#include <srcsax.h>
#include <sax2_srcsax_handler.hpp>

#include <libxml/parserInternals.h>

#include <cstring>

/** 
 * libxml_error
 *
 * Silence/catch/default libxml2 errors.
 */
static void libxml_error(void * /*ctx*/, const char * /*msg*/, ...) {}

/* srcsax_create_parser_context forward declaration */
static xmlParserCtxtPtr srcsax_create_parser_context(xmlParserInputBufferPtr buffer_input);

#ifdef LIBXML2_NEW_BUFFER
struct _xmlBuf {
    xmlChar *content;           /* The buffer content UTF8 */
    unsigned int compat_use;    /* for binary compatibility */
    unsigned int compat_size;   /* for binary compatibility */
    xmlBufferAllocationScheme alloc; /* The realloc method */
    xmlChar *contentIO;         /* in IO mode we may have a different base */
    size_t use;                 /* The buffer size used */
    size_t size;                /* The buffer size */
    xmlBufferPtr buffer;        /* wrapper for an old buffer */
    int error;                  /* an error code if a failure occured */
};

#define _CHECK_COMPAT(buf)                      \
    if (buf->size != (size_t) buf->compat_size) \
        if (buf->compat_size < INT_MAX)         \
            buf->size = buf->compat_size;       \
    if (buf->use != (size_t) buf->compat_use)   \
        if (buf->compat_use < INT_MAX)          \
            buf->use = buf->compat_use;

/**
 * xmlBufResetInput
 * @param buf XML buffer
 * @param input XML parser input
 *
 * Function is taken from libxml2.
 *
 * @returns 0 on success and -1 on error.
 */
int
_xmlBufResetInput(xmlBuf * buf, xmlParserInputPtr input) {
    if ((input == NULL) || (buf == NULL) || (buf->error))
        return(-1);
    _CHECK_COMPAT(buf)
        input->base = input->cur = buf->content;
    input->end = &buf->content[buf->use];
    return(0);

}
#else
/**
 * xmlBufResetInput
 * @param buf XML buffer
 * @param input XML parser input
 *
 * Function is taken fro libxml2.
 *
 * @returns 0 on success and -1 on error.
 */
int
_xmlBufResetInput(xmlBuffer * buf, xmlParserInputPtr input) {
    if ((input == NULL) || (buf == NULL))
        return -1;
    input->base = input->buf->buffer->content;
    input->cur = input->buf->buffer->content;
    input->end = &input->buf->buffer->content[input->buf->buffer->use];
    return 0;
}

#endif

/**
 * srcsax_controller_init
 *
 * Internal method to initialize the controller module.
 */
static void srcsax_controller_init() {

    static bool initialized = false;

    if(initialized) return;

    xmlGenericErrorFunc error_handler = (xmlGenericErrorFunc) libxml_error;
    initGenericErrorDefaultFunc(&error_handler);
    initialized = true;

}

/**
 * srcsax_create_context_filename
 * @param filename a filename
 * @param encoding the files character encoding
 *
 * Open the filename with the specified encoding and return a srcSAX context for parsing.
 *
 * @returns srcsax_context context to be used for srcML parsing.
 */
struct srcsax_context * srcsax_create_context_filename(const char * filename, const char * encoding) {

    srcsax_controller_init();

    struct srcsax_context * context = (struct srcsax_context *)malloc(sizeof(struct srcsax_context));
    memset(context, 0, sizeof(struct srcsax_context));
    context->pop_input = 1;

    context->input =
        xmlParserInputBufferCreateFilename(filename, encoding ? xmlParseCharEncoding(encoding) : XML_CHAR_ENCODING_NONE);

    if(context->input == 0) {

        free(context);
        return 0;

    }

    xmlParserCtxtPtr libxml2_context = srcsax_create_parser_context(context->input);

    if(libxml2_context == NULL) {

        xmlFreeParserInputBuffer(context->input);
        free(context);
        return 0;

    }

    libxml2_context->_private = context;

    context->libxml2_context = libxml2_context;

    return context;

}

/**
 * srcsax_create_context_libxml2
 * @param input an libxml2 xmlParserInputBufferPtr allows multiple different inputs.
 *
 * Use the provided libxml2 input for parsing
 *
 * @returns srcsax_context context to be used for srcML parsing.
 */
struct srcsax_context * srcsax_create_context_libxml2(xmlParserInputBufferPtr input) {

    if(input == 0) return 0;

    srcsax_controller_init();

    struct srcsax_context * context = (struct srcsax_context *)malloc(sizeof(struct srcsax_context));
    memset(context, 0, sizeof(struct srcsax_context));
    context->pop_input = 0;

    context->input = input;

    xmlParserCtxtPtr libxml2_context = srcsax_create_parser_context(context->input);

    if(libxml2_context == NULL) {

        xmlFreeParserInputBuffer(context->input);
        free(context);
        return 0;

    }

    libxml2_context->_private = context;

    context->libxml2_context = libxml2_context;

    return context;

}

/**
 * srcsax_free_context
 * @param context a srcSAX context
 *
 * Free the resources associated with a srcsax_context as created
 * by a previous srcsax_create_context_*.
 */
void srcsax_free_context(struct srcsax_context * context) {

    xmlParserInputPtr stream = inputPop(context->libxml2_context);
    stream->buf = 0;
    xmlFreeInputStream(stream);
    if(context->libxml2_context) xmlFreeParserCtxt(context->libxml2_context);
    if(context->pop_input) xmlFreeParserInputBuffer(context->input);

    free(context);

}

/**
 * srcsax_parse
 * @param context srcSAX context
 * @param handler sax callback handlers
 *
 * Parse the context using the provide sax handlers.
 * On error calls the error callback function before returning.
 *
 * @returns 0 on success -1 on error.
 */
int srcsax_parse(struct srcsax_context * context, struct srcsax_handler * handler) {

    xmlSAXHandlerPtr save_sax = context->libxml2_context->sax;
    xmlSAXHandler sax = srcsax_sax2_factory();
    context->libxml2_context->sax = &sax;

    context->handler = handler;

    sax2_srcsax_handler state;
    state.context = context;
    context->libxml2_context->_private = &state;

    int status = xmlParseDocument(context->libxml2_context);

    context->libxml2_context->sax = save_sax;

    if(status != 0) {

        xmlErrorPtr ep = xmlCtxtGetLastError(context->libxml2_context);

        size_t str_length = strlen(ep->message);
        ep->message[str_length - 1] = '\0';

        if(context->srcsax_error)
            context->srcsax_error((const char *)ep->message, ep->code);

    }

    return status;

}

/**
 * srcsax_create_parser_context
 * @param buffer_input a parser input buffer
 *
 * Create a ctxt from a parser input buffer.
 * Modeled after function in libxml2.
 *
 * @returns xml parser ctxt
 */
xmlParserCtxtPtr
srcsax_create_parser_context(xmlParserInputBufferPtr buffer_input) {
    xmlParserCtxtPtr ctxt;
    xmlParserInputPtr input;
    xmlParserInputBufferPtr buf;

    ctxt = xmlNewParserCtxt();
    if (ctxt == NULL)
        return(NULL);

    xmlCtxtUseOptions(ctxt, XML_PARSE_COMPACT | XML_PARSE_HUGE | XML_PARSE_NODICT);

    buf = buffer_input;
    if (buf == NULL) {
        xmlFreeParserCtxt(ctxt);
        return(NULL);
    }

    input = xmlNewInputStream(ctxt);
    if (input == NULL) {
        xmlFreeParserCtxt(ctxt);
        return(NULL);
    }

    input->filename = NULL;
    input->buf = buf;
    _xmlBufResetInput(input->buf->buffer, input);

    inputPush(ctxt, input);

    return(ctxt);
}

/**
 * srcsax_stop_parser
 * @param context a srcSAX context
 *
 * Stop srcSAX parser.
 */
void srcsax_stop_parser(struct srcsax_context * context) {

    xmlParserCtxtPtr ctxt = context->libxml2_context;

    ctxt->sax->startDocument = 0;
    ctxt->sax->endDocument = 0;
    ctxt->sax->startElementNs = 0;
    ctxt->sax->endElementNs = 0;
    ctxt->sax->characters = 0;
    ctxt->sax->cdataBlock = 0;
    ctxt->sax->comment = 0;
    ctxt->sax->ignorableWhitespace = 0;

    xmlStopParser(ctxt);
    
}
