
file(GLOB ELEMENT_COUNT_SOURCE *.cpp)
file(GLOB ELEMENT_COUNT_HEADER *.hpp)

add_executable(element_count ${ELEMENT_COUNT_SOURCE} ${ELEMENT_COUNT_HEADER})
target_link_libraries(element_count srcsax ${LIBXML2_LIBRARIES})

