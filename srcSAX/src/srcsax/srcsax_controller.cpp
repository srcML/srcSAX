#include <srcsax.h>

static void libxml_error(void *ctx, const char *msg, ...) {}

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

int srcsax_create_context_filename(const char * filename, int options) {}

int srcsax_parse(struct srcsax_context * context) {}


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