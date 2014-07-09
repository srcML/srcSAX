/**
 * @file srcSAXHandlerThread.hpp
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

#ifndef INCLUDED_SRCSAXHANDLERTHREAD_HPP
#define INCLUDED_SRCSAXHANDLERTHREAD_HPP

#include <srcSAXHandler.hpp>

#include <libxml/parser.h>
#include <stdio.h>
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition_variable.hpp>
#include <boost/thread/locks.hpp>
#include <boost/thread/lock_types.hpp> 

class srcSAXHandlerThread : public srcSAXHandler {

private :

  boost::mutex mutex;
  boost::condition_variable cond;

public :

  void wait() {

    boost::unique_lock<boost::mutex> lock(mutex);
    cond.wait(lock);

  }

  void resume() {

    boost::unique_lock<boost::mutex> lock(mutex);
    cond.notify_all();

  }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

  virtual void startDocument() {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  virtual void endDocument() {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  virtual void startRoot(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                         int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                         const xmlChar ** attributes, std::vector<srcMLElement> * meta_tags) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  virtual void startUnit(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                         int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                         const xmlChar ** attributes) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  virtual void startElementNs(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                              int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                              const xmlChar ** attributes) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  virtual void endRoot(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  virtual void endUnit(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

    // pause
    boost::unique_lock<boost::mutex> lock(mutex);
    cond.notify_all();
    cond.wait(lock);

  }

  virtual void endElementNs(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  virtual void charactersRoot(const xmlChar * ch, int len) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  virtual void charactersUnit(const xmlChar * ch, int len) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  virtual void comment(const xmlChar * value) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  virtual void cdataBlock(const xmlChar * value, int len) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

#pragma GCC diagnostic pop

};

#endif
