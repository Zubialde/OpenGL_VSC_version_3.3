#ifndef SCENE_H
#define SCENE_H

#include <scene/Mesh.h>
#include <scene/CameraClass.h>
#include <ECS/GameObject.h>
#include <ECS/Components/Transform.h>
#include <ECS/Components/Model.h>
#include <ECS/Components/DirectionalLight.h>

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