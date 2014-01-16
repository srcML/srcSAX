#ifndef INCLUDED_SRCMLHANDLERTHREAD_HPP
#define INCLUDED_SRCMLHANDLERTHREAD_HPP

#include <srcMLHandler.hpp>

#include <libxml/parser.h>
#include <stdio.h>
#include <boost/thread/condition_variable.hpp>
#include <boost/thread/locks.hpp>
#include <boost/thread/lock_types.hpp> 

class srcMLHandlerThreadStop : public srcMLHandler {

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
                         const xmlChar ** attributes) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  virtual void startUnit(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI,
                         int nb_namespaces, const xmlChar ** namespaces, int nb_attributes, int nb_defaulted,
                         const xmlChar ** attributes) {
    static int count = 0;
    if(count) {

      boost::unique_lock<boost::mutex> lock(mutex);
      cond.notify_all();
      stop_parser();

    }

    ++count;

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
