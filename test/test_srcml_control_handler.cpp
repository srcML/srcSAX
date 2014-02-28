/**
 * @file test_srcml_control_handler.cpp
 *
 * @copyright Copyright (C) 2013-2014  SDML (www.srcML.org)
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

#include <srcMLControlHandler.hpp>
#include <srcMLHandler.hpp>

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cassert>

int main() {

  /*
    srcMLControlHandler
   */
  {
    try {

      srcMLControlHandler control(__FILE__);

    } catch(...) { assert(false); }
  }

  {
    try {

      srcMLControlHandler control("foobar");
      assert(false);
    } catch(...) {}
  }

  {
    try {

      xmlParserInputBufferPtr buffer = xmlParserInputBufferCreateFilename(__FILE__, xmlParseCharEncoding(0));
      srcMLControlHandler control(buffer);
    } catch(...) { assert(false); }
  }

  {
    try {

      xmlParserInputBufferPtr buffer = xmlParserInputBufferCreateFilename(__FILE__, xmlParseCharEncoding("ISO-8859-1"));
      srcMLControlHandler control(buffer, "ISO-8859-1");
    } catch(...) { assert(false); }
  }

  {
    try {

      xmlParserInputBufferPtr buffer = xmlParserInputBufferCreateFilename(__FILE__, xmlParseCharEncoding(0));
      srcMLControlHandler control(buffer, NULL);
    } catch(...) { assert(false); }
  }

  {
    try {

	srcMLControlHandler control((xmlParserInputBufferPtr)NULL);
      assert(false);
    } catch(...) {}
  }

  /*
    getSAX
   */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"

  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  /*
    enable_startDocument
   */
  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_startDocument(true);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_startDocument(false);
    assert(sax.startDocument == 0);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_startDocument(false);
    control.enable_startDocument(true);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  /*
    enable_endDocument
   */
  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_endDocument(true);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_endDocument(false);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == 0);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_endDocument(false);
    control.enable_endDocument(true);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  /*
    enable_startElementNs
   */
  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_startElementNs(true);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_startElementNs(false);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == 0);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_startElementNs(false);
    control.enable_startElementNs(true);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  /*
    enable_endElementNs
   */
  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_endElementNs(true);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_endElementNs(false);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == 0);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_endElementNs(false);
    control.enable_endElementNs(true);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  /*
    enable_characters
   */
  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_characters(true);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_characters(false);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == 0);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_characters(false);
    control.enable_characters(true);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  /*
    enable_comment
   */
  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_comment(true);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_comment(false);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == 0);
    assert(sax.cdataBlock == cdataBlock);
  }

  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_comment(false);
    control.enable_comment(true);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  /*
    enable_cdataBlock
   */
  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_cdataBlock(true);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_cdataBlock(false);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == 0);
  }

  {

    srcMLControlHandler control(__FILE__);
    const xmlSAXHandler & sax = control.getSAX();

    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
    control.enable_cdataBlock(false);
    control.enable_cdataBlock(true);
    assert(sax.startDocument == startDocument);
    assert(sax.endDocument == endDocument);
    assert(sax.startElementNs == startRoot);
    assert(sax.endElementNs == endElementNs);
    assert(sax.characters == charactersFirst);
    assert(sax.comment == comment);
    assert(sax.cdataBlock == cdataBlock);
  }

#pragma GCC diagnostic pop

  /*
    parse
   */

  {

    srcMLControlHandler control("test.xml");
    srcMLHandler handler;
    try {
      control.parse(&handler);
    } catch(SAXError error) { assert(false); }

  }

  {

    srcMLControlHandler control(__FILE__);
    srcMLHandler handler;
    try {
      control.parse(&handler);
      assert(false);
    } catch(SAXError error) {
      assert(error->message != "");
      assert(error.error_code != 0);
    }

  }

  return 0;
}
