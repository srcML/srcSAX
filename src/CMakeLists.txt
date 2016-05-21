file(GLOB HANDLER_SOURCE srcsax/*.cpp cpp/*.cpp)
file(GLOB HANDLER_INCLUDE srcsax/*.hpp cpp/*.hpp)

file(GLOB WINDOWS_SOURCE windows/*.cpp)
file(GLOB WINDOWS_INCLUDE windows/*.hpp)

# build_lib
#  Used to help with the creation of the srcML library.
#  - LIB_NAME is the name of the library and target
#  - LIB_TYPE is either STATIC or SHARED.
# 
macro(build_lib LIB_NAME LIB_TYPE)

    add_library(${LIB_NAME} ${LIB_TYPE} ${HANDLER_SOURCE} ${HANDLER_INCLUDE} ${WINDOWS_SOURCE} ${WINDOWS_INCLUDE})

if("x${CMAKE_CXX_COMPILER_ID}" STREQUAL "xMSVC")
    set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME libsrcsax LINK_FLAGS_DEBUG "/SAFESEH:NO")
elseif(APPLE)
    set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME srcsax MACOSX_RPATH OFF)
else()
    set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME srcsax)
endif()

endmacro()

build_lib(srcsax_static STATIC)
build_lib(srcsax_shared SHARED)
target_link_libraries(srcsax_shared PRIVATE ${LIBXML2_LIBRARIES})
