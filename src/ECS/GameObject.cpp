#include "ECS/GameObject.h"

GameObject::GameObject()
{
    
}

void GameObject::Update(float deltaTime)
{
    for(const std::unique_ptr<Component>& i : components)
    {
        i->Update(deltaTime);
    }
}