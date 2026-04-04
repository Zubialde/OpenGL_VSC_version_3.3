cmake_minimum_required(VERSION 3.11)
project(WhiteBox_Engine)

set(CMAKE_CXX_STANDARD 20)


# Genera unas varliables con la ruta de los Includes y las Librerias
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Includes")
set(GLFW_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/Lib")
set(SHADERS_DIR "${CMAKE_SOURCE_DIR}/assets/Shaders")
set(TEXTURE_DIR "${CMAKE_SOURCE_DIR}/assets/Texture")
set(MODEL_DIR "${CMAKE_SOURCE_DIR}/assets/Model")
set(SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(THP_DIR "${CMAKE_SOURCE_DIR}/third_party")

add_compile_definitions(SHADER_DIR="${SHADERS_DIR}")
add_compile_definitions(TEXTURE_DIR="${TEXTURE_DIR}")
add_compile_definitions(MODEL_DIR="${MODEL_DIR}")

# Añade las rutas de las librerias en un solo lugar
file(GLOB_RECURSE SOURCE ${SOURCE_DIR}/*.cpp)

set(GLAD ${THP_DIR}/glad/glad.c)


#Añade las librerias de GLFW
include_directories(${INCLUDE_DIR} ${THP_DIR} )

link_directories(${GLFW_LIBRARY_DIR})   


# Añade los src (Source Files)
add_executable(WhiteBox ${SOURCE_DIR}/main.cpp ${SOURCE} ${GLAD})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_SOURCE_DIR}/bin)

add_custom_command(TARGET WhiteBox POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_SOURCE_DIR}/Lib/assimp-vc143-mtd.dll  $<TARGET_FILE_DIR:WhiteBox>)

target_compile_definitions(WhiteBox PRIVATE GLFW_STATIC)

# Link GLFW + OpenGL
target_link_libraries(WhiteBox glfw3 opengl32 assimp-vc143-mtd)

