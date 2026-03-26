#pragma once

#include <utils/Component.h>

#include <glm/glm.hpp>

class Transform : public Component{
   
public:
    glm::vec3 position;
    glm::vec3 scale;
    glm::vec3 rotation;

    Transform(glm::vec3 position, glm::vec3 scale, glm::vec3 rotation) : Component(parent){};
    
    void Start() override;
    void Update(float deltaTime) override;
    void OnDestroy() override;

private:

};