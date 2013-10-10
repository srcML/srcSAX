cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)

find_package(LibXml2)
if(LIBXML2_FOUND)
        include_directories(${LIBXML2_INCLUDE_DIR})
endif()

include_directories(. ../src)
enable_testing()

file(GLOB HANDLER_SRC ../src/*.cpp)

add_executable(test_sax2_srcml_handler test_sax2_srcml_handler.cpp ${HANDLER_SRC})
target_link_libraries(test_sax2_srcml_handler ${LIBXML2_LIBRARIES})
add_executable(test_srcml_control_handler test_srcml_control_handler.cpp ${HANDLER_SRC})
target_link_libraries(test_srcml_control_handler ${LIBXML2_LIBRARIES})
add_executable(test_srcml_handler test_srcml_handler.cpp ${HANDLER_SRC})
target_link_libraries(test_srcml_handler ${LIBXML2_LIBRARIES})
