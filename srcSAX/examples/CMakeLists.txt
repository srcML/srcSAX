
set(EXAMPLE_SRC example.cpp)

add_executable(example ${EXAMPLE_SRC})
target_link_libraries(example srcsax ${LIBXML2_LIBRARIES})

