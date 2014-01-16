set(CMAKE_RUNTIME_OUTPUT_DIRECTORY examples)

find_package(Boost COMPONENTS system thread REQUIRED)

set(EXAMPLE_SRC example.cpp)

set(THREAD_SRC thread.cpp)

set(THREAD_STOP_SRC thread_stop.cpp)

add_executable(example ${EXAMPLE_SRC})
target_link_libraries(example sax2framework ${LIBXML2_LIBRARIES})

add_executable(thread ${THREAD_SRC})
target_link_libraries(thread sax2framework ${LIBXML2_LIBRARIES} ${Boost_SYSTEM_LIBRARY_DEBUG} ${Boost_THREAD_LIBRARY_DEBUG})

add_executable(thread_stop ${THREAD_STOP_SRC})
target_link_libraries(thread_stop sax2framework ${LIBXML2_LIBRARIES} ${Boost_SYSTEM_LIBRARY_DEBUG} ${Boost_THREAD_LIBRARY_DEBUG})

