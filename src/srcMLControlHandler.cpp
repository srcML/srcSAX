/*
  srcMLControlHandler.cpp

  Copyright (C) 2004-2013  SDML (www.sdml.info)

  This file is part of the srcML SAX2 Framework.

  The srcML SAX2 Framework is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  The srcML SAX2 Framework is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with the srcML SAX2 Framework; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <srcMLControlHandler.hpp>

/**
 * srcMLControlHandler
 * @param filename name of a file
 *
 * Constructor
 */
srcMLControlHandler::srcMLControlHandler(const char * filename) : sax2_handler() {

  ctxt = xmlCreateURLParserCtxt(filename, XML_PARSE_COMPACT | XML_PARSE_HUGE);
  sax = factory();
  ctxt->sax = &sax;

}

/**
 * ~srcMLControlHandler
 * @param filename name of a file
 *
 * Constructor
 */
srcMLControlHandler::~srcMLControlHandler() {

  ctxt->sax = NULL;
  if(ctxt) xmlFreeParserCtxt(ctxt);

}

/**
 * parse
 * @param handler srcMLHandler with hooks for sax parsing
 *
 * Parse the xml document with the supplied hooks.
 */
void srcMLControlHandler::parse(srcMLHandler * handler) {

  sax2_handler.process = handler;

  ctxt->sax = &sax;
  ctxt->_private = &sax2_handler;

  int status = xmlParseDocument(ctxt);

}
