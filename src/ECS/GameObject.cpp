#include "ECS/GameObject.h"

void GameObject::Update(float deltaTime)
{
    transform.Update(deltaTime);
    for(const std::unique_ptr<Component>& i : components)
    {
        i->Update(deltaTime);
    }
}