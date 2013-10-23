set(CMAKE_RUNTIME_OUTPUT_DIRECTORY test)

add_executable(test_sax2_srcml_handler test/test_sax2_srcml_handler.cpp ${HANDLER_SRC})
target_link_libraries(test_sax2_srcml_handler ${LIBXML2_LIBRARIES})
add_executable(test_srcml_control_handler test/test_srcml_control_handler.cpp ${HANDLER_SRC})
target_link_libraries(test_srcml_control_handler ${LIBXML2_LIBRARIES})
add_executable(test_srcml_handler test/test_srcml_handler.cpp ${HANDLER_SRC})
target_link_libraries(test_srcml_handler ${LIBXML2_LIBRARIES})

add_test(NAME test_sax2_srcml_handler COMMAND test_sax2_srcml_handler)
add_test(NAME test_srcml_control_handler COMMAND test_srcml_control_handler)
add_test(NAME test_srcml_handler COMMAND test_srcml_handler)
