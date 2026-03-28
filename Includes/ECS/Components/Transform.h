#pragma once

#include <ECS/Components/Component.h>

#include <glm/glm.hpp>

class Transform : public Component{
   
public:
    glm::vec3 position;
    glm::vec3 scale;
    glm::vec3 rotation;

    Transform(glm::vec3 position, glm::vec3 scale, glm::vec3 rotation) : Component(parent){ 
        this->position = position;
        this->scale = scale;
        this->rotation = rotation;};
    
    void Start() override;
    void Update(float deltaTime) override;
    void OnDestroy() override;

private:

};