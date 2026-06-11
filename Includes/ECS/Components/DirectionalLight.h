#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H

#include <glm/glm.hpp>

#include <ECS/Components/Component.h>

 struct DirectionalLightInfo{
    glm::vec3 direction {0.0f, 0.0f, 0.0f};
    glm::vec3 color {1.0f, 1.0f, 1.0f};
    float intensity {0.5f}; 
};

class DirectionalLight : public Component
{
    public:
    
    DirectionalLightInfo info;

    DirectionalLight() = default;

    void Start() override {};
    void Update(float deltaTime) override {}
    void OnDestroy() override {}
    
    private:
};
#endif