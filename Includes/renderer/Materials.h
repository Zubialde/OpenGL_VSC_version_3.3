#ifndef MATERIALS_H
#define MATERIALS_H

#include <glm/glm.hpp>



#include <string>
#include <vector>
#include <array>

struct Lit{
    //Material Queue Transparent = 0 Opaque = 1
    unsigned int RenderQueue {1};

    //Textures
    std::array<int, 16> textureIDs;

    //Color
    glm::vec3 ambient {0.2f, 0.2f, 0.2f};
    glm::vec3 diffuse {0.8f, 0.8f, 0.8f};
    glm::vec3 specular {1.0f, 1.0f, 1.0f};
    float shininess = 32.0f;
};

struct Unlit: Lit{
    //Material Queue Transparent = 0 Opaque = 1
    unsigned int RenderQueue {1};

    //Textures
    std::array<int, 16> textureIDs;

    //Color
    glm::vec3 ambient {0.2f, 0.2f, 0.2f};
    glm::vec3 diffuse {0.8f, 0.8f, 0.8f};
    glm::vec3 specular {1.0f, 1.0f, 1.0f};
    float shininess = 32.0f;
};

#endif