#include "ECS/Components/Transform.h"

void Transform::Translate(glm::vec3 translation){
    this->position += translation;
}

void Transform::Rotate(glm::vec3 rotation){
    this->rotation += rotation;
}

void Transform::Scale(glm::vec3 scale){
    this->scale += scale;
}