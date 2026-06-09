#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>

#include <ECS/Components/Component.h>
#include <renderer/ShaderClass.h>
#include <ECS/Components/Transform.h>

#include <renderer/Materials.h>

#include <string>
#include <vector>
#include <string>
#include <type_traits>
#include <unordered_map>

//TODO: Add acces to the materialData
class Material : public Component{
    public:

    Material(const char* vertexPath, const char* fragmentPath, MaterialData materialData){
        this->vertexPath = vertexPath;
        this->fragmentPath = fragmentPath;
    }
    
    std::string vertexPath;
    std::string fragmentPath;

    std::unique_ptr<MaterialData> materialData;

    
    template<typename T>
    requires std::is_base_of_v<MaterialData, T>
    void ConstructMaterial(){
        materialData = T();
    }
    
    void Start() override {};
    void Update(float deltaTime) override{};
    void OnDestroy() override {};
};

#endif