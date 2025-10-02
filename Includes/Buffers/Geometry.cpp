#include "Geometry.h"

#include <iostream>

namespace Geometry{
    #pragma region Cube
    //Cube Vertices and Text Coordinates
    float CubeVertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };

    const unsigned int CubeVertexCount = sizeof(CubeVertices) / sizeof(float);
    #pragma endregion

    #pragma region Sphere
    float SphereVertices[] = {
        0.5f,  0.0f,  0.0f,  1.0f, 0.0f,
    };

    const unsigned int SphereVertexCount = sizeof(SphereVertices) / sizeof(float);
    #pragma endregion

    #pragma region Piramid
    float PyramidVertices[] = {
        // --- BASE (cuadrada) ---
        // Triángulo 1
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,   // esquina inferior izquierda
        0.5f, -0.5f, 0.0f,   1.0f, 0.0f,   // esquina inferior derecha
        0.5f,  0.5f, 0.0f,   1.0f, 1.0f,   // esquina superior derecha

        // Triángulo 2
        0.5f,  0.5f, 0.0f,   1.0f, 1.0f,   // esquina superior derecha
        -0.5f,  0.5f, 0.0f,   0.0f, 1.0f,   // esquina superior izquierda
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,   // esquina inferior izquierda

        // --- CARA FRONTAL ---
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,   // izquierda base
        0.5f, -0.5f, 0.0f,   1.0f, 0.0f,   // derecha base
        0.0f,  0.0f, 1.0f,   0.5f, 1.0f,   // vértice superior

        // --- CARA DERECHA ---
        0.5f, -0.5f, 0.0f,   0.0f, 0.0f,   // frontal base
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f,   // trasera base
        0.0f,  0.0f, 1.0f,   0.5f, 1.0f,   // vértice superior

        // --- CARA TRASERA ---
        0.5f,  0.5f, 0.0f,   1.0f, 0.0f,   // derecha base
        -0.5f,  0.5f, 0.0f,   0.0f, 0.0f,   // izquierda base
        0.0f,  0.0f, 1.0f,   0.5f, 1.0f,   // vértice superior

        // --- CARA IZQUIERDA ---
        -0.5f,  0.5f, 0.0f,   1.0f, 0.0f,   // trasera base
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,   // frontal base
        0.0f,  0.0f, 1.0f,   0.5f, 1.0f    // vértice superior
    };

    const unsigned int PyramidVertexCount = sizeof(PyramidVertices) / sizeof(float);
    #pragma endregion

}


