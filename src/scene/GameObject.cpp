#include "scene/GameObject.h"

GameObject::GameObject()
{
    
}

GameObject* GameObject::Instantiate(std::string name)
{
    return new GameObject();
}

void GameObject::Update(float deltaTime)
{
    for(const std::unique_ptr<Component>& i : components)
    {
        i->Update(deltaTime);
    }
}