#include <srcMLHandlerThread.hpp>
#include <SAX2srcMLHandler.hpp>
#include <srcMLControlHandler.hpp>

#include <string>
#include <libxml/parserInternals.h>

void * start_routine(void * arg) {
  srcMLHandlerThread * handler = (srcMLHandlerThread *)arg;

  
  srcMLControlHandler control("test.xml");
  control.parse(handler);

  return 0;

}

int main(int argc, char * argv[]) {


  pthread_t thread;
  srcMLHandlerThread arg;
  pthread_create(&thread, 0, start_routine, &arg);
  void * ret;
  pthread_join(thread, &ret);

  arg.resume();

  return 0;
}
