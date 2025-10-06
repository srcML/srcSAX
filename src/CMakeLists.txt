file(GLOB HANDLER_SOURCE srcsax/*.cpp cpp/*.cpp)
file(GLOB HANDLER_INCLUDE srcsax/*.h srcsax/*.hpp cpp/*.hpp)

file(GLOB WINDOWS_SOURCE windows/*.cpp)
file(GLOB WINDOWS_INCLUDE windows/*.hpp)

# build_lib
#  Used to help with the creation of the srcML library.
#  - LIB_NAME is the name of the library and target
#  - LIB_TYPE is either STATIC or SHARED.
# 
macro(build_lib LIB_NAME LIB_TYPE)

    add_library(${LIB_NAME} ${LIB_TYPE} ${HANDLER_SOURCE} ${HANDLER_INCLUDE} ${WINDOWS_SOURCE} ${WINDOWS_INCLUDE})

if("${CMAKE_SYSTEM_NAME}" STREQUAL "Windows")
    if("${LIB_TYPE}" STREQUAL "STATIC")
        set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME libsrcsax_static)
    else()
        set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME libsrcsax)
    endif()
elseif(APPLE)
    set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME srcsax MACOSX_RPATH OFF)
else()
    set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME srcsax)
endif()

endmacro()

find_package(LibXml2 REQUIRED)

build_lib(srcsax_static STATIC)
target_link_libraries(srcsax_static PRIVATE LibXml2::LibXml2)

build_lib(srcsax_shared SHARED)
target_link_libraries(srcsax_shared PRIVATE LibXml2::LibXml2)

install(TARGETS srcsax_shared srcsax_static RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${HANDLER_INCLUDE} DESTINATION include/srcsax)
