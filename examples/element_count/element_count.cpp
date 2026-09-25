// SPDX-License-Identifier: GPL-3.0-only
/**
 * @file element_count.hpp
 *
 * @copyright Copyright (C) 2013-2026 srcML, LLC. (www.srcML.org)
 *
 * This file is part of the srcML Infrastructure.
 */

 /*

  Count each the occurrences of each srcML element.

  Input: input_file.xml
  Useage: element_count input_file.xml
  
  */

#include "element_count_handler.hpp"
#include <srcSAXController.hpp>

#include <map>
#include <iostream>

/**
 * main
 * @param argc number of arguments
 * @param argv the provided arguments (array of C strings)
 * 
 * Invoke srcSAX handler to count element occurences and print out the resulting element counts.
 */
int main(int argc, char * argv[]) {

  if(argc < 2) {

    std::cerr << "Useage: element_count input_file.xml\n";
    exit(1);

  }

  srcSAXController control(argv[1]);
  element_count_handler handler;
  control.parse(&handler);

  for(std::map<std::string, unsigned long long>::const_iterator citr = handler.get_counts().begin(); citr != handler.get_counts().end(); ++citr) {

  	std::cout << citr->first << ": " << citr->second << '\n';

  }

  return 0;
}
