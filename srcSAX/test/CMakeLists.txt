add_unit_test(test_srcsax.cpp srcsax ${LIBXML2_LIBRARIES})
add_unit_test(test_sax2_srcsax_handler.cpp srcsax ${LIBXML2_LIBRARIES})
add_unit_test(test_srcsax_handler.cpp srcsax ${LIBXML2_LIBRARIES})

add_subdirectory(cpp)
