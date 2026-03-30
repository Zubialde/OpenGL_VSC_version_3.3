#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>

#include <ECS/Components/Component.h>
#include <scene/SceneManager.h>

struct MaterialData{
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;
};

struct Texture{
    unsigned int id;
    std::string type;
    std::string path; // We store the path to check if its already loaded
};


class Material : public Component{
    public:

    MaterialData data;

    Material(std::string& path);


    private:
    };

#endif