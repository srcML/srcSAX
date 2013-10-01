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
  pthread_mutex_t is_done_mutex;
  pthread_cond_t cond;
  pthread_mutex_init(&is_done_mutex, 0);
  pthread_cond_init(&cond, 0);
  //srcMLHandlerThread arg;
  srcMLHandlerThread arg(&is_done_mutex, &cond);
  pthread_create(&thread, 0, start_routine, &arg);

  /*
  while(true) {
    pthread_mutex_lock(&is_done_mutex);
    if(is_done) {

      is_done = false;
      pthread_mutex_unlock(&mutex);
      break;

    }
    pthread_mutex_unlock(&mutex);

  }
}
  */
  arg.wait();
  arg.resume();


void * ret;
pthread_join(thread, &ret);

return 0;
}
