set(CMAKE_RUNTIME_OUTPUT_DIRECTORY examples)

include_directories(examples)

set(EXAMPLE_SRC examples/example.cpp)

set(THREAD_SRC examples/thread.cpp)

set(THREAD_STOP_SRC examples/thread_stop.cpp)

add_executable(example ${EXAMPLE_SRC})
target_link_libraries(example sax2framework ${LIBXML2_LIBRARIES})

add_executable(thread ${THREAD_SRC})
target_link_libraries(thread sax2framework ${LIBXML2_LIBRARIES})

add_executable(thread_stop ${THREAD_STOP_SRC})
target_link_libraries(thread_stop sax2framework ${LIBXML2_LIBRARIES})

