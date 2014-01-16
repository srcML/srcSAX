#include <srcMLHandlerExample.hpp>
#include <SAX2srcMLHandler.hpp>
#include <srcMLControlHandler.hpp>

#include <string>
#include <libxml/parserInternals.h>

int main() {

  srcMLControlHandler control("example.xml");
  srcMLHandlerExample handler;
  control.parse(&handler);

  return 0;
}
