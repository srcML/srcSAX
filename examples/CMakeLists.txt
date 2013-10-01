cmake_minimum_required(VERSION 2.8)
project(Example)

include_directories(. ../src)

find_package(LibXml2)
if(LIBXML2_FOUND)
        include_directories(${LIBXML2_INCLUDE_DIR})
endif()

file(GLOB EXAMPLE_SRC *.cpp)
file(GLOB HANDLER_SRC ../src/*.cpp)

add_executable(example ${EXAMPLE_SRC} ${HANDLER_SRC})
