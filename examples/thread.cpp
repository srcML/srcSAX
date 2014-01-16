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

int main(int argc, char * argv[]) {


  //pthread_t thread;
  srcMLHandlerThread arg;
  //pthread_create(&thread, 0, start_routine, &arg);
  boost::thread thread = boost::thread(start_routine, &arg);
  fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);

  arg.wait();
  arg.resume();
  fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
  arg.wait();
  arg.resume();
  fprintf(stderr, "HERE: %s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
  void * ret;
  //pthread_join(thread, &ret);
  thread.join();

  return 0;
}
