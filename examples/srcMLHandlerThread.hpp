#ifndef INCLUDED_SRCMLHANDLERTHREAD_HPP
#define INCLUDED_SRCMLHANDLERTHREAD_HPP

#include <srcMLHandler.hpp>

#include <libxml/parser.h>
#include <stdio.h>
#include <pthread.h>

class srcMLHandlerThread : public srcMLHandler {

private :

  pthread_mutex_t mutex;
  pthread_mutex_t is_done_mutex;
  pthread_cond_t cond;
  pthread_cond_t is_done_cond;

  bool is_done;
public :

  srcMLHandlerThread() : is_done(false) {

    pthread_mutex_init(&mutex, 0);
    pthread_mutex_init(&is_done_mutex, 0);
    pthread_cond_init(&cond, 0);
    pthread_cond_init(&is_done_cond, 0);
  }

  ~srcMLHandlerThread() {

    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&is_done_mutex);
    pthread_cond_destroy(&cond);
    pthread_cond_destroy(&is_done_cond);
  }

  void wait() {

    pthread_cond_wait(&is_done_cond, &is_done_mutex);

  }

  void resume() {
    pthread_cond_broadcast(&cond);
  }

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
    pthread_cond_broadcast(&is_done_cond);
    pthread_cond_wait(&cond, &mutex);

  }

  virtual void endElementNs(const xmlChar * localname, const xmlChar * prefix, const xmlChar * URI) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

  virtual void characters(const xmlChar * ch, int len) {

    fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  }

};

#endif
