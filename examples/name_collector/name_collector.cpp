/**
 * @file nameCheck.cpp
 *
 *
 *To Compile:
 *clang++ nameCheck.cpp  -I /usr/local/include/srcsax -lsrcsax -o nameCheck
 *
 *You will need to replace -I with location of srcSAX includes
 ** -I /usr/local/include/srcsax
 *
 *Need to build srcSAX:
 *First install libxml2 - via brew
 *Then (in srcSAX folder):
 *cmake CMakeLists.txt
 *make
 *sudo make install
*/

#include "name_collector_handler.hpp"
#include <srcSAXController.hpp>
#include <iostream>

/**
 * main
 * @param argc number of arguments
 * @param argv the provided arguments (array of C strings)
 * 
 * Invoke srcSAX handler to copy the supplied srcML document and into the given
 * output file.
 */
int main(int argc, char * argv[]) {
    if(argc < 2) {
        std::cerr << "Useage: name_collector input_file.xml\n";
        exit(1);
    }

    srcSAXController control(argv[1]);
    name_collector_handler handler;
    control.parse(&handler);
    std::cout << "Done processing." << std::endl;
    return 0;
}
