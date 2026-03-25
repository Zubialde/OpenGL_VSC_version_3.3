#ifndef SCENE_H
#define SCENE_H

#include <scene/Mesh.h>
#include <scene/CameraClass.h>
#include <scene/GameObject.h>
#include <utils/Transform.h>

#include <iostream>
#include <vector>


class Scene{
    public:
    
    std::string name;

    std::vector<std::shared_ptr<GameObject>> gameObjects;

    Scene(std::string name);

    void Update(float deltaTime);

    void AddGameObject(std::shared_ptr<GameObject>& gameObject);

    void Load();

    void Unload();
    
};

#endif