// SPDX-License-Identifier: GPL-3.0-only
/**
 * @file identity_copy.hpp
 *
 * @copyright Copyright (C) 2013-2026 srcML, LLC. (www.srcML.org)
 *
 * This file is part of the srcML Infrastructure.
 */

 /*

  Copy the srcML document.

  Input: input_file.xml
  Input: output_file.xml
  Useage: identity_copy input_file.xml output_file.xml
  
  */

#include "identity_copy_handler.hpp"
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

  if(argc < 3) {

    std::cerr << "Useage: identify_copy input_file.xml output_file.xml\n";
    exit(1);

  }

  srcSAXController control(argv[1]);
  identity_copy_handler handler(argv[2]);
  control.parse(&handler);

  return 0;
}
