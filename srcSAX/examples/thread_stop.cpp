/**
 * @file tread_stop.cpp
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

#include <srcSAXHandlerThreadStop.hpp>
#include <SAX2srcSAXHandler.hpp>
#include <srcSAXController.hpp>

#include <string>
#include <libxml/parserInternals.h>

#include <boost/thread/thread.hpp>

void * start_routine(void * arg) {

  srcSAXHandlerThreadStop * handler = (srcSAXHandlerThreadStop *)arg;

  srcSAXController control("thread.xml");
  control.parse(handler);

  return 0;

}

int main() {


  pthread_t thread;
  srcSAXHandlerThreadStop arg;
  pthread_create(&thread, 0, start_routine, &arg);


  arg.wait();
  arg.resume();

  arg.wait();

  void * ret;
  pthread_join(thread, &ret);

  return 0;
}
