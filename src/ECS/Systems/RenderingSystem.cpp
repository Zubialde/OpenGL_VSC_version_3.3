#include "ECS/Systems/RenderingSystem.h"
#include "ECS/GameObject.h"
#include "ECS/scene.h"

void RenderingSystem::SetScene(std::shared_ptr<Scene> scene)
{
    currentScene = scene;
    CheckLights(*scene);
    CheckCamera(*scene);
}

void RenderingSystem::CheckLights(Scene& currentScene)
{
    for(int i = 0; i < currentScene.gameObjects.size(); i++)
    {
        if(DirectionalLight* light = currentScene.gameObjects[i]->GetComponent<DirectionalLight>(); light != nullptr)
        {
            directionalLights.push_back(light->info);
        }
        if(PointLight* light = currentScene.gameObjects[i]->GetComponent<PointLight>(); light != nullptr)
        {
            pointLights.push_back(light->info);
        }
        if(SpotLight* light = currentScene.gameObjects[i]->GetComponent<SpotLight>(); light != nullptr)
        {
            SpotLights.push_back(light->info);
        }
    }
}

void RenderingSystem::CheckCamera(Scene& currentScene)
{
    this->cameras = camera.info;
    cameras.position = glm::vec3(0.0f, 0.0f, 3.0f);
}