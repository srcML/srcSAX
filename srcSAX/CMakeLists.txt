cmake_minimum_required(VERSION 2.8)
project(srcSAX)

cmake_policy(SET CMP0015 NEW)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY bin)

find_package(LibXml2 REQUIRED)

include_directories(${LIBXML2_INCLUDE_DIR} examples test src)

set(CMAKE_CXX_FLAGS "-fPIC -O3 -DNDEBUG -Wno-long-long -Wall -Wextra")

enable_testing()

file(GLOB HANDLER_SOURCE src/*.cpp)
file(GLOB HANDLER_INCLUDE src/*.hpp)

add_library(srcsax ${HANDLER_SOURCE} ${HANDLER_INCLUDE})

subdirs(examples test)

