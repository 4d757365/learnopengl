cmake_minimum_required(VERSION 3.22 FATAL_ERROR)

project(hello_window VERSION 1.0)

# add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall" "-Werror" "-Wextra" "-fsanitize=undefined,address")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")
set(CMAKE_BUILD_TYPE Debug)


add_executable(hello_window src/config.h src/main.cpp src/glad.c)


find_package(glfw3 3.4 REQUIRED)
find_package(OpenGL REQUIRED)

target_include_directories(hello_window PUBLIC ${OPENGL_INCLUDE_DIR})


target_link_libraries(hello_window "-framework Cocoa")
target_link_libraries(hello_window "-framework OpenGL")
target_link_libraries(hello_window "-framework IOKit")
target_link_libraries(hello_window glfw ${OPENGL_gl_LIBRARY})