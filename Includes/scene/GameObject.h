#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <utils/Components.h>

#include <iostream>
#include <vector>

class GameObject{
    public:

    std::vector<std::shared_ptr<Components>> components;

    GameObject();

    void Update(float deltaTime);

    void AddComponent(std::shared_ptr<Components> component);

    private:
};

#endif