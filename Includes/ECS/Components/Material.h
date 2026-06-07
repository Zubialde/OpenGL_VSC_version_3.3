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