cmake_minimum_required(VERSION 2.8)
project(srcSAX)

cmake_policy(SET CMP0015 NEW)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY bin)

find_package(LibXml2 REQUIRED)

set(Boost_NO_BOOST_CMAKE ON)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system thread REQUIRED)

include_directories(${LIBXML2_INCLUDE_DIR} ${Boost_INCLUDE_DIR} examples test src)

set(CMAKE_CXX_FLAGS "-fPIC -O3 -DNDEBUG -Wno-long-long -Wall -Wextra -Wshorten-64-to-32")

enable_testing()

file(GLOB HANDLER_SOURCE src/*.cpp)
file(GLOB HANDLER_INCLUDE src/*.hpp)

add_library(srcsax ${HANDLER_SOURCE} ${HANDLER_INCLUDE})

subdirs(examples test)

