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
struct MaterialData{
    glm::vec3 ambient = glm::vec3(0.2f, 0.2f, 0.2f);
    glm::vec3 diffuse = glm::vec3(0.8f, 0.8f, 0.8f);
    glm::vec3 specular = glm::vec3(1.0f, 1.0f, 1.0f);
    float shininess = 32.0f;
};
class Material : public Component{
    public:

    MaterialData data;
    std::shared_ptr<ShaderClass> shader;
    MaterialData materialData;

    Material(const char* vertexPath, const char* fragmentPath);
    
    void Start() override {};
    void Update(float deltaTime) override{};
    void OnDestroy() override {};

    void Draw();

    std::shared_ptr<ShaderClass> GetShader(std::string type, std::string path);

    private:

    std::vector<std::shared_ptr<ShaderClass>> shaders;

    std::unordered_map<std::string, std::shared_ptr<ShaderClass>> shaderCache;

};

#endif