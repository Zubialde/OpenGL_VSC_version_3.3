#include "ECS/GameObject.h"

int GameObject::n_Components = 0;

void GameObject::Update(float deltaTime)
{
    if(components.size() <= 0)
        return;

    for(const std::unique_ptr<Component>& i : components)
    {
        if(i == nullptr)
            continue;
            
        i->Update(deltaTime);
    }
}