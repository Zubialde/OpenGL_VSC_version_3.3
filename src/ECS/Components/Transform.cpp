#include "ECS/Components/Transform.h"

void Transform::Translate(glm::vec3 translation){
    this->info.position += translation;
}

void Transform::Rotate(glm::vec3 rotation){
    this->info.rotation += rotation;
}

void Transform::Scale(glm::vec3 scale){
    this->info.scale += scale;
}