// SPDX-License-Identifier: GPL-3.0-only
/**
 * @file print_callbacks.hpp
 *
 * @copyright Copyright (C) 2013-2026 srcML, LLC. (www.srcML.org)
 *
 * This file is part of the srcML Infrastructure.
 */

 /*

  Print each callback as it is called (callback trace).

  Input: input_file.xml
  Useage: print_callbacks input_file.xml
  
  */

#include "print_callbacks_handler.hpp"
#include <srcSAXController.hpp>

#include <iostream>

/**
 * main
 * @param argc number of arguments
 * @param argv the provided arguments (array of C strings)
 * 
 * Invoke srcSAX handler to print out each callback as it is called.
 */
int main(int argc, char * argv[]) {

  if(argc < 2) {

    std::cerr << "Useage: print_callbacks input_file.xml\n";
    exit(1);

  }

  srcSAXController control(argv[1]);
  //control.enable_function(true);
  print_callbacks_handler handler;
  control.parse(&handler);

  return 0;
}
