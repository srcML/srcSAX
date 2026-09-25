// SPDX-License-Identifier: GPL-3.0-only
/**
 * @file name_collector.cpp
 *
 * @copyright Copyright (C) 2023-2026 srcML, LLC. (www.srcML.org)
 *
 * This file is part of the srcML Infrastructure.
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
