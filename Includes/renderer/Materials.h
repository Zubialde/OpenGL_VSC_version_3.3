#ifndef MATERIALS_H
#define MATERIALS_H

#include <glm/glm.hpp>

#include <string>
#include <vector>
#include <array>

/**/
struct MaterialData{
    unsigned int RenderQueue {1};
    unsigned int textureIDs[16];

    virtual ~MaterialData() = default;

    virtual std::unique_ptr<MaterialData> Clone() = 0;
};

struct Lit : public MaterialData{
    //Color
    glm::vec3 ambient {0.2f, 0.2f, 0.2f};
    glm::vec3 diffuse {0.8f, 0.8f, 0.8f};
    glm::vec3 specular {1.0f, 1.0f, 1.0f};
    float shininess = 32.0f;

    //Here we override the MaterialData
    Lit(){

    }

    std::unique_ptr<MaterialData> Clone() override{
        return std::make_unique<Lit>(*this);
    };
};

struct Unlit: public MaterialData{
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