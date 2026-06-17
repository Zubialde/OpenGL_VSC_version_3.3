#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>

#include <ECS/Components/Component.h>
#include <renderer/ShaderClass.h>
#include <ECS/Components/Transform.h>

#include <renderer/MaterialData.h>
#include <core/ResourceManager.h>

#include <string>
#include <vector>
#include <string>
#include <type_traits>
#include <unordered_map>

/*struct MaterialData{
    enum class MaterialType{LIT, UNLIT, PBR};

    MaterialType type { MaterialType::LIT };

    unsigned int shaderID {0};
    std::array<unsigned int, 16> textures {0};

    glm::vec3 diffuse {0.0f};
    glm::vec3 specular {0.0f};
    glm::vec3 ambient {0.0f};

    float shininess {0.0f};
};*/


//TODO: Add acces to the materialData
class Material : public Component{
    public:

    Material(const char* vertexPath, const char* texturePath){
        this->vertexPath = vertexPath;
        this->texturePath = texturePath;
    }
    
    std::string vertexPath;
    std::string fragmentPath;
    std::string texturePath;

    MaterialData instanceData;
    
    void Start() override {        
        instanceData.shaderID = ResourceManager::GetInstance().GetShader(vertexPath)->ID;
        instanceData.textures[0] = ResourceManager::GetInstance().GetTexture(texturePath)->ID;
    };
    void Update(float deltaTime) override{};
    void OnDestroy() override {};
};

#endif