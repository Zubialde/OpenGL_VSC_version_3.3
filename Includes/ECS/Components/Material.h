#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>

#include <ECS/Components/Component.h>
#include <renderer/ShaderClass.h>
#include <ECS/Components/Transform.h>


#include <string>
#include <vector>
#include <string>
#include <type_traits>
#include <unordered_map>

/// @brief  Holds the material data, if u want to add a new variable just add it here
/// @param MaterialQueue Transparent = 0 Opaque = 1
struct MaterialData{
    //Material Queue
    bool MaterialQueue = true;
    
    //Colors
    glm::vec3 ambient {0.2f, 0.2f, 0.2f};
    glm::vec3 diffuse {0.8f, 0.8f, 0.8f};
    glm::vec3 specular {1.0f, 1.0f, 1.0f};

    float shininess = 32.0f;
};
class Material : public Component{
    public:

    Material(const char* vertexPath, const char* fragmentPath){
        this->vertexPath = vertexPath;
        this->fragmentPath = fragmentPath;
    }

    std::string vertexPath;
    std::string fragmentPath;
    
    void Start() override {};
    void Update(float deltaTime) override{};
    void OnDestroy() override {};
};

#endif