/**
 * @file srcSAXController.cpp
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

#include <srcSAXController.hpp>
#include <srcSAXHandler.hpp>
#include <cppCallbackAdapter.hpp>

#include <sax2_srcsax_handler.hpp>

#include <string>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

/**
 * srcSAXController
 * @param filename name of a file
 *
 * Constructor
 */
srcSAXController::srcSAXController(const char * filename, const char * encoding) {

    context = srcsax_create_context_filename(filename, encoding);

    if(context == NULL) throw std::string("File does not exist");


}


/**
 * srcSAXController
 * @param input pointer to a parser input buffer
 *
 * Constructor
 */
srcSAXController::srcSAXController(xmlParserInputBufferPtr input) {

    context = srcsax_create_context_xml_parser_input_buffer(input);

    if(context == NULL) throw std::string("File does not exist");

}

/**
 * ~srcSAXController
 *
 * Constructor
 */
srcSAXController::~srcSAXController() {

    if(context) srcsax_free_context(context);

}

/**
 * getCtxt
 *
 * Return the used parser context.
 */
srcsax_context * srcSAXController::getContext() {

    return context;

}

/**
 * enable_startDocument
 * @param enable bool indicate enable or disable SAX parsing.
 *
 * Enables or disables startDocument parsing.
 */
void srcSAXController::enable_startDocument(bool enable) {

    if(enable) context->libxml2_context->sax->startDocument = start_document;
    else context->libxml2_context->sax->startDocument = 0;

}

/**
 * enable_endDocument
 * @param enable bool indicate enable or disable SAX parsing.
 *
 * Enables or disables endDocument parsing.
 */
void srcSAXController::enable_endDocument(bool enable) {

    if(enable) context->libxml2_context->sax->endDocument = end_document;
    else context->libxml2_context->sax->endDocument = 0;

}

/**
 * enable_startElementNs
 * @param enable bool indicate enable or disable SAX parsing.
 *
 * Enables or disables startElementNs parsing.
 */
void srcSAXController::enable_startElementNs(bool enable) {

    if(enable) context->libxml2_context->sax->startElementNs = start_root;
    else context->libxml2_context->sax->startElementNs = 0;

}

/**
 * enable_endElementNs
 * @param enable bool indicate enable or disable SAX parsing.
 *
 * Enables or disables endElementNs parsing.
 */
void srcSAXController::enable_endElementNs(bool enable) {

    if(enable) context->libxml2_context->sax->endElementNs = end_element_ns;
    else context->libxml2_context->sax->endElementNs = 0;

}

/**
 * enable_characters
 * @param enable bool indicate enable or disable SAX parsing.
 *
 * Enables or disables characters parsing.
 */
void srcSAXController::enable_characters(bool enable) {

    if(enable) {

        context->libxml2_context->sax->characters = characters_first;
        context->libxml2_context->sax->ignorableWhitespace = characters_first;

    } else {

        context->libxml2_context->sax->characters = 0;
        context->libxml2_context->sax->ignorableWhitespace = 0;

    }

}

/**
 * enable_comment
 * @param enable bool indicate enable or disable SAX parsing.
 *
 * Enables or disables comment parsing.
 */
void srcSAXController::enable_comment(bool enable) {

    if(enable) context->libxml2_context->sax->comment = comment;
    else context->libxml2_context->sax->comment = 0;

}

/**
 * enable_cdataBlock
 * @param enable bool indicate enable or disable SAX parsing.
 *
 * Enables or disables cdataBlock parsing.
 */
void srcSAXController::enable_cdataBlock(bool enable) {

    if(enable) context->libxml2_context->sax->cdataBlock = cdata_block;
    else context->libxml2_context->sax->cdataBlock = 0;

}

/**
 * enable_processingInstruction
 * @param enable bool indicate enable or disable SAX parsing.
 *
 * Enables or disables processingInstruction parsing.
 */
void srcSAXController::enable_processingInstruction(bool enable) {

    if(enable) context->libxml2_context->sax->processingInstruction = processing_instruction;
    else context->libxml2_context->sax->processingInstruction = 0;

}

/**
* enable_function
* @param enable bool indicate enable or disable special function parsing.
*
* Enables or disables special function parsing.
*/
void srcSAXController::enable_function(bool enable) {

    //sax2_handler.parse_function = enable;

}

/**
 * parse
 * @param handler srcMLHandler with hooks for sax parsing
 *
 * Parse the xml document with the supplied hooks.
 */
void srcSAXController::parse(srcSAXHandler * handler) {

    cppCallbackAdapter adapter(handler);
    context->data = &adapter;
    srcsax_handler sax_handler = cppCallbackAdapter::factory();

    int status = srcsax_parse(context, &sax_handler);

    context->data = 0;

    if(status != 0) {

        xmlErrorPtr ep = xmlCtxtGetLastError(context->libxml2_context);

        size_t str_length = strlen(ep->message);
        ep->message[str_length - 1] = '\0';
        SAXError error = { std::string((const char *)ep->message), ep->code };

        throw error;
    }

}

