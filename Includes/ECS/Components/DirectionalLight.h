#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H

#include <glm/glm.hpp>

#include <ECS/Components/Component.h>

 struct DirectionalLightInfo{
    glm::vec3 direction;
    glm::vec3 color;
    float intensity;
};

class DirectionalLight : public Component
{
    public:
    
    DirectionalLightInfo info;

    DirectionalLight(glm::vec3 direction, glm::vec3 color, float intensity);

    void Start() override {};
    void Update(float deltaTime) override {}
    void OnDestroy() override {}
    private:
};
#endif