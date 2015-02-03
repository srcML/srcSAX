include_directories(${LIBXML2_INCLUDE_DIR} srcsax cpp windows)

file(GLOB HANDLER_SOURCE srcsax/*.cpp cpp/*.cpp)
file(GLOB HANDLER_INCLUDE srcsax/*.hpp cpp/*.hpp)

file(GLOB WINDOWS_SOURCE windows/*.cpp)
file(GLOB WINDOWS_INCLUDE windows/*.hpp)

add_library(srcsax ${HANDLER_SOURCE} ${HANDLER_INCLUDE} ${WINDOWS_SOURCE} ${COMMON_INCLUDE})
