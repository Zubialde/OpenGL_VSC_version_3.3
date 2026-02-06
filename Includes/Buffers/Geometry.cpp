#include "Geometry.h"

#include <iostream>

namespace Geometry{
    #pragma region Cube
    //Cube Vertices and Text Coordinates
float CubeVertices[] = {
    // Position           // Normal           // UV
    // Back Face
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

    // Front Face
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f,

    // Left Face
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

    // Right Face
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

    // Bottom Face
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
     0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

    // Top Face
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
     0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
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
        // --- BASE (Bottom) ---
        // Pos                  // Normal             // UV
        -0.5f, -0.5f, 0.0f,     0.0f, 0.0f, -1.0f,    0.0f, 0.0f, 
        0.5f, -0.5f, 0.0f,     0.0f, 0.0f, -1.0f,    1.0f, 0.0f,
        0.5f,  0.5f, 0.0f,     0.0f, 0.0f, -1.0f,    1.0f, 1.0f,

        0.5f,  0.5f, 0.0f,     0.0f, 0.0f, -1.0f,    1.0f, 1.0f,
        -0.5f,  0.5f, 0.0f,     0.0f, 0.0f, -1.0f,    0.0f, 1.0f,
        -0.5f, -0.5f, 0.0f,     0.0f, 0.0f, -1.0f,    0.0f, 0.0f,

        // --- FRONT FACE ---
        -0.5f, -0.5f, 0.0f,     0.0f, -0.894f, 0.447f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f,     0.0f, -0.894f, 0.447f, 1.0f, 0.0f,
        0.0f,  0.0f, 1.0f,     0.0f, -0.894f, 0.447f, 0.5f, 1.0f,

        // --- RIGHT FACE ---
        0.5f, -0.5f, 0.0f,     0.894f, 0.0f, 0.447f,  0.0f, 0.0f,
        0.5f,  0.5f, 0.0f,     0.894f, 0.0f, 0.447f,  1.0f, 0.0f,
        0.0f,  0.0f, 1.0f,     0.894f, 0.0f, 0.447f,  0.5f, 1.0f,

        // --- BACK FACE ---
        0.5f,  0.5f, 0.0f,     0.0f, 0.894f, 0.447f,  1.0f, 0.0f,
        -0.5f,  0.5f, 0.0f,     0.0f, 0.894f, 0.447f,  0.0f, 0.0f,
        0.0f,  0.0f, 1.0f,     0.0f, 0.894f, 0.447f,  0.5f, 1.0f,

        // --- LEFT FACE ---
        -0.5f,  0.5f, 0.0f,     -0.894f, 0.0f, 0.447f, 1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,     -0.894f, 0.0f, 0.447f, 0.0f, 0.0f,
        0.0f,  0.0f, 1.0f,     -0.894f, 0.0f, 0.447f, 0.5f, 1.0f
    };

    const unsigned int PyramidVertexCount = sizeof(PyramidVertices) / sizeof(float);
    #pragma endregion


    #pragma region EBOCube
    float vertices[] = {
        0.5f,  0.5f, 0.0f,  1.0f, 1.0f, // top right
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f,// bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, 0.0f,  0.0f, 1.0f, // top left 

        0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // 4: Top Right
        0.5f, 0.5f, -1.0f,   1.0f, 0.0f, // 5: Bottom Right (Fixed Y to -0.5)
        -0.5f, 0.5f, -1.0f,   0.0f, 0.0f, // 6: Bottom Left (Fixed Y to -0.5, Z to 1.0)
        -0.5f,  0.5f, 0.0f,   0.0f, 1.0f,  //

        0.5f,  -0.5f, 0.0f,   1.0f, 1.0f, // 4: Top Right
        0.5f, -0.5f, -1.0f,   1.0f, 0.0f, // 5: Bottom Right (Fixed Y to -0.5)
        -0.5f, -0.5f, -1.0f,   0.0f, 0.0f, // 6: Bottom Left (Fixed Y to -0.5, Z to 1.0)
        -0.5f,  -0.5f, 0.0f,   0.0f, 1.0f,  //

        0.5f,  0.5f, -1.0f,  1.0f, 1.0f, // top right
        0.5f, -0.5f, -1.0f,  1.0f, 0.0f,// bottom right
        -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, // bottom left
        -0.5f,  0.5f, -1.0f,  0.0f, 1.0f, // top left 

        0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // 4: Top Right
        0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // 5: Bottom Right (Fixed Y to -0.5)
        0.5f, -0.5f, -1.0f,   0.0f, 0.0f, // 6: Bottom Left (Fixed Y to -0.5, Z to 1.0)
        0.5f,  0.5f, -1.0f,   0.0f, 1.0f,  //

        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // 4: Top Right
        -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // 5: Bottom Right (Fixed Y to -0.5)
        -0.5f, -0.5f, -1.0f,   0.0f, 0.0f, // 6: Bottom Left (Fixed Y to -0.5, Z to 1.0)
        -0.5f,  0.5f, -1.0f,   0.0f, 1.0f,  //
    };

    int indices[] = {  // note that we start from 0!
        0, 1, 3,   // first triangle
        1, 2, 3,// second triangle
        
        4, 5, 7,   // first triangle
        5, 6, 7,// second triangle

        8, 9, 11,
        9, 10, 11,

        12, 13, 15,
        13, 14, 15,

        16,17,19,
        17,18,19,

        20, 21, 23,
        21, 22, 23,
    };
    
    const unsigned int CubeVertexEBOCount = sizeof(vertices) / sizeof(float);
    const unsigned int indexCount = sizeof(indices) / sizeof(int);

    #pragma endregion

}


