#pragma once

#include <ECS/Components/Component.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
struct Transforminfo{
    glm::vec3 position;
    glm::vec3 scale;
    glm::vec3 rotation;
};
class Transform : public Component{
    
public:
    Transforminfo info;
    glm::mat4 model {glm::mat4(1.0f)};

    Transform(glm::vec3 position, glm::vec3 scale, glm::vec3 rotation){ 
        this->info.position = position;
        this->info.scale = scale;
        this->info.rotation = rotation;
    };
    
    void Start() override {model = glm::mat4(1.0f);
        model = glm::translate(model, info.position);
        model = glm::rotate(model, glm::radians(info.rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(info.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, glm::radians(info.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, info.scale);
    };

    void Update(float deltaTime) override{ 
        model = glm::translate(model, info.position);
        model = glm::rotate(model, glm::radians(info.rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(info.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, glm::radians(info.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, info.scale);
    };
    
    void OnDestroy() override{};
    
    void Translate(glm::vec3 translation);

    void Rotate(glm::vec3 rotation);

    void Scale(glm::vec3 scale);

};