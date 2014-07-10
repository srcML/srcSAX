
file(GLOB PRINT_CALLBACKS_SOURCE *.cpp)
file(GLOB PRINT_CALLBACKS_HEADER *.hpp)

add_executable(print_callbacks ${PRINT_CALLBACKS_SOURCE} ${PRINT_BALLBACKS_HEADER})
target_link_libraries(example srcsax ${LIBXML2_LIBRARIES})

