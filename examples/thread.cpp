/**
 * @file thread.cpp
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

#include <srcMLHandlerThread.hpp>
#include <SAX2srcMLHandler.hpp>
#include <srcMLControlHandler.hpp>

#include <string>
#include <libxml/parserInternals.h>

#include <boost/thread/thread.hpp>

void * start_routine(void * arg) {

  srcMLHandlerThread * handler = (srcMLHandlerThread *)arg;

  srcMLControlHandler control("thread.xml");
  control.parse(handler);

  return 0;

}

int main() {

  srcMLHandlerThread arg;

  boost::thread thread = boost::thread(start_routine, &arg);

  arg.wait();
  arg.resume();

  arg.wait();
  arg.resume();

  thread.join();

  return 0;
}
