
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY bin)

include_directories(${LIBXML2_INCLUDE_DIR} src/srcsax src/c src/cpp)

add_subdirectory(src)

if(BUILD_UNIT_TESTS)
    include_directories(test)
    add_subdirectory(test)
endif()

if(BUILD_EXAMPLES)
    include_directories(examples)
    add_subdirectory(examples)
endif()
