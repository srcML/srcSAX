#include <srcsax.h>
#include <SAX2srcSAXHandler.hpp>

#include <libxml/parserInternals.h>

#include <cstring>

static void libxml_error(void * /*ctx*/, const char * /*msg*/, ...) {}

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

struct srcsax_context * srcsax_create_context_filename(const char * filename, const char * encoding) {

    srcsax_controller_init();

    struct srcsax_context * context = (struct srcsax_context *)malloc(sizeof(struct srcsax_context));
    context->pop_input = 1;

   context->input =
        xmlParserInputBufferCreateFilename(filename, encoding ? xmlParseCharEncoding(encoding) : XML_CHAR_ENCODING_NONE);

    if(context->input == 0) {

        free(context);
        return 0;

    }

    xmlParserCtxtPtr libxml2_context = srcSAXCreateParserCtxt(context->input);

    if(libxml2_context == NULL) {

        xmlFreeParserInputBuffer(context->input);
        free(context);
        return 0;

    }

    libxml2_context->_private = context;

    context->libxml2_context = libxml2_context;

    return context;

}

void srcsax_free_context(struct srcsax_context * context) {

    xmlParserInputPtr stream = inputPop(context->libxml2_context);
    stream->buf = 0;
    xmlFreeInputStream(stream);
    if(context->libxml2_context) xmlFreeParserCtxt(context->libxml2_context);
    if(context->pop_input) xmlFreeParserInputBuffer(context->input);

}

int srcsax_parse(struct srcsax_context * context, struct srcsax_handler * handler) {

    xmlSAXHandlerPtr save_sax = context->libxml2_context->sax;
    xmlSAXHandler sax = srcsax_sax2_factory();
    context->libxml2_context->sax = &sax;

    context->handler = handler;

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


void stop_srcsax_parser(struct srcsax_context * context) {

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