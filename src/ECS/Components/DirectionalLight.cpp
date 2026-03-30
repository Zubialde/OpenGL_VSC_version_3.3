#include "ECS/Components/DirectionalLight.h"
#include "ECS/GameObject.h"
#include "ECS/Components/Transform.h"


DirectionalLight::DirectionalLight(glm::vec3 direction, glm::vec3 color, float intensity) : Component(parent) { 
    info.direction = direction; 
    info.color = color; 
    info.intensity = intensity; 
};