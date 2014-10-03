
#add_subdirectory(srcsax)
#add_subdirectory(cpp)

file(GLOB HANDLER_SOURCE srcsax/*.cpp cpp/*.cpp)
file(GLOB HANDLER_INCLUDE srcsax/*.hpp cpp/*.hpp)

file(GLOB COMMON_SOURCE ${PROJECT_SOURCE_DIR}/common/src)
file(GLOB COMMON_INCLUDE ${PROJECT_SOURCE_DIR}/common/include)

add_library(srcsax ${HANDLER_SOURCE} ${HANDLER_INCLUDE} ${COMMON_SOURCE} ${COMMON_INCLUDE})