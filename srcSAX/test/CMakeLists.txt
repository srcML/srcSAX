
add_executable(test_srcsax test_srcsax.cpp)
target_link_libraries(test_srcsax srcsax ${LIBXML2_LIBRARIES})
add_executable(test_sax2_srcsax_handler test_sax2_srcsax_handler.cpp)
target_link_libraries(test_sax2_srcsax_handler srcsax ${LIBXML2_LIBRARIES})

add_test(NAME test_srcsax COMMAND test_srcsax)
add_test(NAME test_sax2_srcsax_handler COMMAND test_sax2_srcsax_handler)
