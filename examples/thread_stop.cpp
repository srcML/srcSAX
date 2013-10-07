#include <srcMLHandlerThreadStop.hpp>
#include <SAX2srcMLHandler.hpp>
#include <srcMLControlHandler.hpp>

#include <string>
#include <libxml/parserInternals.h>

#include <pthread.h>

void * start_routine(void * arg) {

  srcMLHandlerThreadStop * handler = (srcMLHandlerThreadStop *)arg;

  srcMLControlHandler control("thread.xml");
  control.parse(handler);

  return 0;

}

int main(int argc, char * argv[]) {


  pthread_t thread;
  srcMLHandlerThread arg;
  pthread_create(&thread, 0, start_routine, &arg);


  arg.wait();
  arg.resume();

  arg.wait();
  arg.resume();

  void * ret;
  pthread_join(thread, &ret);

  return 0;
}
