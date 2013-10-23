cmake_minimum_required(VERSION 2.8)
project(SAX2Framework)

cmake_policy(SET CMP0015 NEW)

include_directories(examples src test)

find_package(LibXml2)
if(LIBXML2_FOUND)
        include_directories(${LIBXML2_INCLUDE_DIR})
endif()

enable_testing()

set(EXAMPLE_SRC examples/example.cpp)
file(GLOB HANDLER_SRC src/*.cpp)

set(THREAD_SRC examples/thread.cpp)

set(THREAD_STOP_SRC examples/thread_stop.cpp)

add_executable(example ${EXAMPLE_SRC} ${HANDLER_SRC})
target_link_libraries(example ${LIBXML2_LIBRARIES})

add_executable(thread ${THREAD_SRC} ${HANDLER_SRC})
target_link_libraries(thread ${LIBXML2_LIBRARIES})

add_executable(thread_stop ${THREAD_STOP_SRC} ${HANDLER_SRC})
target_link_libraries(thread_stop ${LIBXML2_LIBRARIES})

add_executable(test_sax2_srcml_handler test/test_sax2_srcml_handler.cpp ${HANDLER_SRC})
target_link_libraries(test_sax2_srcml_handler ${LIBXML2_LIBRARIES})
add_executable(test_srcml_control_handler test/test_srcml_control_handler.cpp ${HANDLER_SRC})
target_link_libraries(test_srcml_control_handler ${LIBXML2_LIBRARIES})
add_executable(test_srcml_handler test/test_srcml_handler.cpp ${HANDLER_SRC})
target_link_libraries(test_srcml_handler ${LIBXML2_LIBRARIES})

add_test(NAME test_sax2_srcml_handler COMMAND test_sax2_srcml_handler)
add_test(NAME test_srcml_control_handler COMMAND test_srcml_control_handler)
add_test(NAME test_srcml_handler COMMAND test_srcml_handler)
