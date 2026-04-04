#pragma once

#include <ECS/Components/Component.h>

#include <glm/glm.hpp>



struct TransformData{
    glm::vec3 position;
    glm::vec3 scale;
    glm::vec3 rotation;
};

class Transform : public Component{
   
public:
    TransformData data;

    glm::vec3 position;
    glm::vec3 scale;
    glm::vec3 rotation;

    Transform(glm::vec3 position, glm::vec3 scale, glm::vec3 rotation){ 
        this->position = position;
        this->scale = scale;
        this->rotation = rotation;};
    
    void Start() override {};
    void Update(float deltaTime) override{};
    void OnDestroy() override{};
    
    void Translate(glm::vec3 translation);

    void Rotate(glm::vec3 rotation);

    void Scale(glm::vec3 scale);

};