#include "ECS/Systems/RenderQueue.h"
#include "ECS/GameObject.h"

void RenderQueue::setScene(std::shared_ptr<Scene> scene)
{
    currentScene = scene;
    gameObjects = scene->gameObjects;
}

void RenderQueue::RenderCycle()
{
    
}