
#add_subdirectory(srcsax)
#add_subdirectory(cpp)

file(GLOB HANDLER_SOURCE srcsax/*.cpp)
file(GLOB HANDLER_INCLUDE srcsax/*.hpp)

add_library(srcsax ${HANDLER_SOURCE} ${HANDLER_INCLUDE})