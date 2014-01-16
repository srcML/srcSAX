cmake_minimum_required(VERSION 2.8)
project(SAX2Framework)

cmake_policy(SET CMP0015 NEW)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY bin)

find_package(LibXml2 REQUIRED)
include_directories(${LIBXML2_INCLUDE_DIR} ${Boost_INCLUDE_DIR} examples test src)

set(CMAKE_CXX_FLAGS "-fPIC -O3 -DNDEBUG -Wno-long-long -Wall -Wextra -Wshorten-64-to-32")

enable_testing()

file(GLOB HANDLER_SRC src/*.cpp)
add_library(sax2framework ${HANDLER_SRC})

subdirs(examples test)

