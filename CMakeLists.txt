cmake_minimum_required(VERSION 3.11)
project(OpenGL_App)

set(CMAKE_CXX_STANDARD 17)

# Genera unas varliables con la ruta de los Includes y las Librerias
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Includes")
set(GLFW_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/Lib")
set(SHADERS_DIR "${CMAKE_SOURCE_DIR}/assets/Shaders")
set(TEXTURE_DIR "${CMAKE_SOURCE_DIR}/assets/Textures")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(THP_DIR "${CMAKE_SOURCE_DIR}/third_party")

add_compile_definitions(SHADER_DIR="${SHADERS_DIR}")
add_compile_definitions(TEXTURE_DIR="${TEXTURE_DIR}")

# Añade las rutas de las librerias en un solo lugar
#-------------------------------------------------------------------

file(GLOB_RECURSE SOURCE ${SOURCE_DIR}/*.cpp
    ${THP_DIR}/*.c
    ${THP_DIR}/*.cpp)
#-------------------------------------------------------------------

#Añade las librerias de GLFW
include_directories(${INCLUDE_DIR} ${THP_DIR} )

link_directories(${GLFW_LIBRARY_DIR})   

# Adñado los src (Source Files)
add_executable(OpenGL_App main.cpp ${SOURCE})

target_compile_definitions(OpenGL_App PRIVATE GLFW_STATIC)

# Link GLFW + OpenGL
target_link_libraries(OpenGL_App glfw3 opengl32 assimp-vc143-mtd)


