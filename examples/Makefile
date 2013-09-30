all : Example

Example : Example.cpp srcMLHandlerExample.hpp
	g++ -I /usr/include/libxml2 -I . -I ../src Example.cpp ../src/SAX2srcMLHandler.cpp -lxml2 -o Example