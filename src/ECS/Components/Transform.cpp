#include "ECS/Components/Transform.h"

void Transform::Translate(glm::vec3 translation){
    this->data.position += translation;
}

void Transform::Rotate(glm::vec3 rotation){
    this->data.rotation += rotation;
}

void Transform::Scale(glm::vec3 scale){
    this->data.scale += scale;
}