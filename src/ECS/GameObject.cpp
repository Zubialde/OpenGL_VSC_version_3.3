#include "ECS/GameObject.h"

int GameObject::n_Components = 0;

void GameObject::Update(float deltaTime)
{
    transform.Update(deltaTime);
    for(const std::unique_ptr<Component>& i : components)
    {
        i->Update(deltaTime);
    }
}