cmake_minimum_required(VERSION 3.10)
project(OpenGL_App)

set(CMAKE_CXX_STANDARD 17)

# Genera unas varliables con la ruta de los Includes y las Librerias
set(GLFW_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Includes")
set(GLFW_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/Lib")
set(GLFW_SHADERS_DIR"${CMAKE_SOURCE_DIR}/Shaders")

# Añade las rutas de las librerias en un solo lugar
#-------------------------------------------------------------------
set(SOURCE ${GLFW_LIBRARY_DIR}/glad.c )

set(HEADER ${GLFW_INCLUDE_DIR}/Shaders/ShaderClass.cpp 
            ${GLFW_INCLUDE_DIR}/Stb_Image/stb_image.h)
#-------------------------------------------------------------------

#Añade las librerias de GLFW
include_directories(${GLFW_INCLUDE_DIR})

link_directories(${GLFW_LIBRARY_DIR})

# Adñado los src (Source Files)
add_executable(OpenGL_App main.cpp ${SOURCE} ${HEADER})

target_compile_definitions(OpenGL_App PRIVATE GLFW_STATIC)

# Link GLFW + OpenGL
target_link_libraries(OpenGL_App glfw3 opengl32)


