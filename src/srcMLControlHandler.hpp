/*
  srcMLControlHandler.hpp

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

#ifndef INCLUDED_SRCMLCONTROLHANDLER_HPP
#define INCLUDED_SRCMLCONTROLHANDLER_HPP

#include <srcMLHandler.hpp>
#include <SAX2srcMLHandler.hpp>

#include <libxml/parser.h>
#include <libxml/parserInternals.h>

class srcMLControlHandler {

private :

  xmlParserCtxtPtr ctxt;
  xmlSAXHandler sax;
  SAX2srcMLHandler sax2_handler;

public :

  srcMLControlHandler(const char * filename);
  ~srcMLControlHandler();

  void parse(srcMLHandler * handler);

};

#endif
