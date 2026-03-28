#ifndef SPOTLIGHT_H
#define SPOTLIGHT_H

#include <glm/glm.hpp>

#include <ECS/Components/Component.h>

struct SpotLightInfo{
    glm::vec3 position;
    glm::vec3 direction;
    glm::vec3 color;
    float intensity;
    float cutOff;
    float outerCutOff;
};

class SpotLight : public Component
{
    public:
    
    SpotLightInfo info;

    SpotLight(glm::vec3 position, glm::vec3 direction, glm::vec3 color, float intensity, float cutOff, float outerCutOff);

    void Start() override;
    void Update(float deltaTime) override;
    void OnDestroy() override;

    private:
};
#endif