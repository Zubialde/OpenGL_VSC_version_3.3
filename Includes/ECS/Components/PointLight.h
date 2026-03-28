#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include <glm/glm.hpp>

#include <ECS/Components/Component.h>

struct PointLightInfo{
    glm::vec3 position;
    glm::vec3 color;
    float intensity;
};

class PointLight : public Component
{
    public:
    
    PointLightInfo info;

    PointLight(glm::vec3 position, glm::vec3 color, float intensity);

    void Start() override;
    void Update(float deltaTime) override;
    void OnDestroy() override;

    private:
};
#endif