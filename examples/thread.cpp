#include <srcMLHandlerThread.hpp>
#include <SAX2srcMLHandler.hpp>
#include <srcMLControlHandler.hpp>

#include <string>
#include <libxml/parserInternals.h>

void * start_routine(void *) {

  
  srcMLControlHandler control("test.xml");
  srcMLHandlerThread handler;
  control.parse(&handler);

  return 0;

}

int main(int argc, char * argv[]) {


  pthread_t thread;
  pthread_create(&thread, 0, start_routine, &arg);

  return 0;
}
