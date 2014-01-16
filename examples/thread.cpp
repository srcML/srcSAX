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
