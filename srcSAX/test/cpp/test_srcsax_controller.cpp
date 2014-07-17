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
#include <cppCallbackAdapter.hpp>

#include <srcsax.h>

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <string.h>
#include <cassert>

/**
 * read_callback
 * @param context the context to read from
 * @param buffer the buffer to read into
 * @param len the number of bytes to read
 *
 * FILE read callback for testing io.
 *
 * @returns the number of bytes read.
 */
int read_callback(void * context, char * buffer, int len) {

    return (int)fread(buffer, 1, len, (FILE *)context);

}

/**
 * close_callback
 * @param context the context to read from
 *
 * FILE close callback for testing io.
 *
 * @returns 0 on success EOF otherwise.
 */
int close_callback(void * context) {

    return fclose((FILE *)context);

}

/**
 * main
 *
 * Test the srcsax functions.
 *
 * @returns 0 on success.
 */
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

      srcSAXController control(std::string("foobar"), "ISO-8859-1");

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

  {
    try {

    FILE * file = fopen(__FILE__, "r");
    srcSAXController control((void *)file, read_callback, close_callback);

    } catch(...) { assert(false); }
  }

  {
    try {

    FILE * file = fopen(__FILE__, "r");
    srcSAXController control((void *)file, read_callback, close_callback, "ISO-8859-1");

    } catch(...) { assert(false); }
  }

  /*
    enable_startDocument
   */
  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_startDocument(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_startDocument(false);
    assert(sax.start_document == 0);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_startDocument(false);
    control.enable_startDocument(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  /*
    enable_endDocument
   */
  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_endDocument(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_endDocument(false);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == 0);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_endDocument(false);
    control.enable_endDocument(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  /*
    enable_startRoot
   */
  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_startRoot(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_startRoot(false);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == 0);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_startRoot(false);
    control.enable_startRoot(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  /*
    enable_startUnit
   */
  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_startUnit(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_startUnit(false);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == 0);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_startUnit(false);
    control.enable_startUnit(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  /*
    enable_startElement
   */
  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_startElement(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_startElement(false);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == 0);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_startElement(false);
    control.enable_startElement(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  /*
    enable_endRoot
   */
  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_endRoot(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_endRoot(false);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == 0);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_endRoot(false);
    control.enable_endRoot(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  /*
    enable_endUnit
   */
  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_endUnit(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_endUnit(false);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == 0);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_endUnit(false);
    control.enable_endUnit(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  /*
    enable_endElement
   */
  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_endElement(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_endElement(false);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == 0);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_endElement(false);
    control.enable_endElement(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  /*
    enable_charactersRoot
   */
  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_charactersRoot(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_charactersRoot(false);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == 0);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_charactersRoot(false);
    control.enable_charactersRoot(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  /*
    enable_charactersUnit
   */
  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_charactersUnit(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_charactersUnit(false);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == 0);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_charactersUnit(false);
    control.enable_charactersUnit(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  /*
    enable_metaTag
   */
  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_metaTag(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_metaTag(false);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == 0);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_metaTag(false);
    control.enable_metaTag(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  /*
    enable_comment
   */
  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_comment(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_comment(false);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == 0);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_comment(false);
    control.enable_comment(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  /*
    enable_cdataBlock
   */
  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_cdataBlock(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_cdataBlock(false);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == 0);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_cdataBlock(false);
    control.enable_cdataBlock(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  /*
    enable_processingInstruction
   */
  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_processingInstruction(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_processingInstruction(false);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == 0);
  }

  {

    srcSAXController control(__FILE__);
    srcsax_handler sax = cppCallbackAdapter::factory(); 
    control.getContext()->handler = &sax;

    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
    control.enable_processingInstruction(false);
    control.enable_processingInstruction(true);
    assert(sax.start_document == cppCallbackAdapter::start_document);
    assert(sax.end_document == cppCallbackAdapter::end_document);
    assert(sax.start_root == cppCallbackAdapter::start_root);
    assert(sax.start_unit == cppCallbackAdapter::start_unit);
    assert(sax.start_element == cppCallbackAdapter::start_element);
    assert(sax.end_root == cppCallbackAdapter::end_root);
    assert(sax.end_unit == cppCallbackAdapter::end_unit);
    assert(sax.end_element == cppCallbackAdapter::end_element);
    assert(sax.characters_root == cppCallbackAdapter::characters_root);
    assert(sax.characters_unit == cppCallbackAdapter::characters_unit);
    assert(sax.meta_tag == cppCallbackAdapter::meta_tag);
    assert(sax.comment == cppCallbackAdapter::comment);
    assert(sax.cdata_block == cppCallbackAdapter::cdata_block);
    assert(sax.processing_instruction == cppCallbackAdapter::processing_instruction);
  }

  /*
    parse
   */

  {

    srcSAXController control(std::string("<unit/>"));
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
      assert(error.message != "");
      assert(error.error_code != 0);
    }

  }

  return 0;
}
