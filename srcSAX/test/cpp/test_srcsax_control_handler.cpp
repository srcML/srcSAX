/**
 * @file test_srcsax_control_handler.cpp
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

#include <srcSAXController.hpp>
#include <srcSAXHandler.hpp>

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <cassert>

int main() {

  /*
    srcSAXController
   */
  {
    try {

      srcSAXController control(__FILE__);

    } catch(...) { assert(false); }
  }

  {
    try {

	srcSAXController control(__FILE__, "ISO-8859-1");

    } catch(...) { assert(false); }
  }

  {
    try {

      srcSAXController control(std::string("foobar"));

    } catch(...) { assert(false); }
  }

  {
    try {

      srcSAXController control(std::string("foobar", "ISO-8859-1"));

    } catch(...) { assert(false); }
  }

  {
    try {

    srcSAXController control(__FILE__, "ISO-8859-1");

    } catch(...) { assert(false); }
  }

  {
    try {

    FILE * file = fopen(__FILE__, "r");
    srcSAXController control(file);

    } catch(...) { assert(false); }
  }

  {
    try {

    FILE * file = fopen(__FILE__, "r");
    srcSAXController control(file, "ISO-8859-1");

    } catch(...) { assert(false); }
  }

  {
    try {

    int fd = open(__FILE__, O_RDONLY);
    srcSAXController control(fd);

    } catch(...) { assert(false); }
  }

  {
    try {

    int fd = open(__FILE__, O_RDONLY);
    srcSAXController control(fd, "ISO-8859-1");

    } catch(...) { assert(false); }
  }

  /*
    enable_startDocument
   */
  {

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control(__FILE__);
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

    srcSAXController control("test.xml");
    srcSAXHandler handler;
    try {
      control.parse(&handler);
    } catch(SAXError error) { assert(false); }

  }

  {

    srcSAXController control(__FILE__);
    srcSAXHandler handler;
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
