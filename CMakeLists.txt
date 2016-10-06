project(libevuse)
cmake_minimum_required(VERSION 2.8.12)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(libevuse libevtest.c)
target_link_libraries(libevuse ${CONAN_LIBS} m)

