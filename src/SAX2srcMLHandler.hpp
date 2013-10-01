/*
  SAX2srcMLHandler.hpp

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

#ifndef INCLUDED_SAX2SRCMLHANDLER_HPP
#define INCLUDED_SAX2SRCMLHANDLER_HPP

#include <srcMLHandler.hpp>

#include <libxml/parser.h>

struct SAX2srcMLHandler {

  srcMLHandler * process;

};

xmlSAXHandler factory();

void startDocument(void * ctx);

void endDocument(void * ctx);
void startElementNs(void * ctx, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                           int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                           const xmlChar ** attributes);

void endElementNs(void * ctx, const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI);

void characters(void * ctx, const xmlChar * ch, int len);

#endif