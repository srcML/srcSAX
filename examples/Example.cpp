#include <srcMLHandlerExample.hpp>
#include <SAX2srcMLHandler.hpp>
#include <srcMLControlHandler.hpp>

#include <string>
#include <libxml/parserInternals.h>

int main(int argc, char * argv[]) {

  srcMLControlHandler control("example.xml");
  srcMLHandler handler;
  control.parse(&handler);

  return 0;
}
