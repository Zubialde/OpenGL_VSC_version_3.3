    cmake_minimum_required(VERSION 3.10)
project(OpenGL_App)

set(CMAKE_CXX_STANDARD 17)

set(GLFW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Includes")
set(GLFW_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/Lib")

include_directories(${GLFW_INCLUDE_DIR})

link_directories(${GLFW_LIBRARY_DIR})

add_executable(OpenGL_App main.cpp glad.c)

target_compile_definitions(OpenGL_App PRIVATE GLFW_STATIC)

# Link GLFW + OpenGL
target_link_libraries(OpenGL_App glfw3 opengl32)