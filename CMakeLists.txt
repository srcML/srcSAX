cmake_minimum_required(VERSION 2.8)
project(SAX2Framework)

cmake_policy(SET CMP0015 NEW)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY bin)

find_package(LibXml2 REQUIRED)
include_directories(${LIBXML2_INCLUDE_DIR})

enable_testing()

include_directories(src)
file(GLOB HANDLER_SRC src/*.cpp)
add_library(sax2framework ${HANDLER_SRC})

include(examples/CMakeLists.txt)
include(test/CMakeLists.txt)

