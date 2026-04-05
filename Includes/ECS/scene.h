#ifndef SCENE_H
#define SCENE_H

#include <scene/CameraClass.h>
#include <ECS/GameObject.h>
#include <ECS/Components/Transform.h>
#include <ECS/Components/Model.h>
#include <ECS/Components/Material.h>
#include <ECS/Components/DirectionalLight.h>
#include <ECS/Components/PointLight.h>
#include <ECS/Components/SpotLight.h>


#include <iostream>
#include <vector>


class Scene{
    public:
    
    std::string name;

    std::vector<std::shared_ptr<GameObject>> gameObjects;

    Scene(std::string name);

    void Update(float deltaTime);

    void AddGameObject(std::shared_ptr<GameObject>& gameObject);

    std::shared_ptr<GameObject> Instantiate(std::string name);
    
    void Load();

    void Unload();
};

#endif