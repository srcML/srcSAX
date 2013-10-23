cmake_minimum_required(VERSION 2.8)
project(SAX2Framework)

cmake_policy(SET CMP0015 NEW)

include_directories(examples src test)

find_package(LibXml2)
if(LIBXML2_FOUND)
        include_directories(${LIBXML2_INCLUDE_DIR})
endif()

enable_testing()

file(GLOB HANDLER_SRC src/*.cpp)

include(examples/CMakeLists.txt)
include(test/CMakeLists.txt)

