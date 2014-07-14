#include <srcsax.h>

#include <cstring>

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

struct srcsax_context * srcsax_create_context_filename(const char * filename) {

    srcsax_controller_init();

    struct srcsax_context * context = (struct srcsax_context *)malloc(sizeof(struct srcsax_context));

    input =
        xmlParserInputBufferCreateFilename(filename,
                                           encoding ? xmlParseCharEncoding(encoding) : XML_CHAR_ENCODING_NONE);

    xmlParserCtxtPtr ctxt = srcSAXCreateParserCtxt(input);

    context->libxml2_context = ctxt;


    if(ctxt == NULL) throw std::string("File does not exist");
    //sax = factory();

}

int srcsax_parse(struct srcsax_context * context) {

    int status = xmlParseDocument(context->libxml2_context);

    if(status != 0) {

        xmlErrorPtr ep = xmlCtxtGetLastError(context->libxml2_context);

        size_t str_length = strlen(ep->message);
        ep->message[str_length - 1] = '\0';

        if(context->srcsax_error)
            context->srcsax_error((const char *)ep->message, ep->code);

    }

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