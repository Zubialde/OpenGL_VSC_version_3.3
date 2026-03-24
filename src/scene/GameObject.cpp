#include "scene/GameObject.h"

GameObject::GameObject()
{

}

void GameObject::Update(float deltaTime)
{
    for(unsigned int i = 0; i < components.size(); i++)
    {
        components[i]->Update(deltaTime);
    }
}

void GameObject::AddComponent(std::shared_ptr<Components> component)
{
    components.push_back(component);
}
