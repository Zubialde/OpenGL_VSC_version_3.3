#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>

#include <ECS/Components/Component.h>
#include <renderer/ShaderClass.h>
#include <renderer/TextureClass.h>

#include <string>
#include <vector>
#include <string>
#include <type_traits>

/// @brief  Holds the material data, if u want to add a new variable just add it here
struct MaterialData{
    glm::vec3 ambient = glm::vec3(0.2f, 0.2f, 0.2f);
    glm::vec3 diffuse = glm::vec3(0.8f, 0.8f, 0.8f);
    glm::vec3 specular = glm::vec3(1.0f, 1.0f, 1.0f);
    float shininess = 32.0f;
};
    

struct TextureData{ 
    std::string path; //We store the path to check if its already loaded
    unsigned int id;
    std::string type;
};

class Material{
    public:

    MaterialData data;
    std::vector <TextureData> textures;
    std::vector <TextureData> loaded_textures;

    Material(ShaderClass& shader){
        this->shader = shader;
    }


    void LoadTextures(ShaderClass& shader);
    void LoadVariables(ShaderClass& shader);

    void Draw();

    private:

    const char* vertexPath;
    const char* fragmentPath;

    ShaderClass shader = ShaderClass("vertexPath", "fragmentPath");
};

#endif