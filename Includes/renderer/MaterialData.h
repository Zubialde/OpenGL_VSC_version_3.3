#ifndef MATERIALDATA_H
#define MATERIALDATA_H

#include <glm/glm.hpp>

#include <array>

struct MaterialData{
    enum class MaterialType{LIT, UNLIT, PBR};

    MaterialType type { MaterialType::LIT };

    unsigned int shaderID {0};
    std::array<unsigned int, 16> textures {0};

    glm::vec3 diffuse {0.0f};
    glm::vec3 specular {0.0f};
    glm::vec3 ambient {0.0f};

    float shininess {0.0f};
};


#endif