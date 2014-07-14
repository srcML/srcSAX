cmake_minimum_required(VERSION 2.8)
project(srcSAX)

cmake_policy(SET CMP0015 NEW)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY bin)

find_package(LibXml2 REQUIRED)

include_directories(${LIBXML2_INCLUDE_DIR} src/srcsax src/c src/cpp examples test)

set(CMAKE_CXX_FLAGS "-fPIC -O3 -DNDEBUG -Wno-long-long -Wall -Wextra")

enable_testing()

add_subdirectory(src)
add_subdirectory(examples)
add_subdirectory(test)

