cmake_minimum_required(VERSION 2.8)
project(Example)

include_directories(. ../src)

find_package(LibXml2)
if(LIBXML2_FOUND)
        include_directories(${LIBXML2_INCLUDE_DIR})
endif()

set(EXAMPLE_SRC example.cpp)
file(GLOB HANDLER_SRC ../src/*.cpp)

set(THREAD_SRC thread.cpp)

set(THREAD_STOP_SRC thread_stop.cpp)

add_executable(example ${EXAMPLE_SRC} ${HANDLER_SRC})
target_link_libraries(example ${LIBXML2_LIBRARIES})

add_executable(thread ${THREAD_SRC} ${HANDLER_SRC})
target_link_libraries(thread ${LIBXML2_LIBRARIES})

add_executable(thread_stop ${THREAD_STOP_SRC} ${HANDLER_SRC})
target_link_libraries(thread_stop ${LIBXML2_LIBRARIES})
