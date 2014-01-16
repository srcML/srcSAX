#include <srcMLHandlerThreadStop.hpp>
#include <SAX2srcMLHandler.hpp>
#include <srcMLControlHandler.hpp>

#include <string>
#include <libxml/parserInternals.h>

#include <boost/thread/thread.hpp>

void * start_routine(void * arg) {

  srcMLHandlerThreadStop * handler = (srcMLHandlerThreadStop *)arg;

  srcMLControlHandler control("thread.xml");
  control.parse(handler);

  return 0;

}

int main(int argc, char * argv[]) {


  pthread_t thread;
  srcMLHandlerThreadStop arg;
  pthread_create(&thread, 0, start_routine, &arg);


  arg.wait();
  arg.resume();

  arg.wait();

  void * ret;
  pthread_join(thread, &ret);

  return 0;
}
