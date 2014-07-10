
file(GLOB IDENTITY_COPY_SOURCE *.cpp)
file(GLOB IDENTITY_COPY_HEADER *.hpp)

add_executable(identity_copy ${IDENTITY_COPY_SOURCE} ${IDENTITY_COPY_HEADER})
target_link_libraries(identity_copy srcsax ${LIBXML2_LIBRARIES})

