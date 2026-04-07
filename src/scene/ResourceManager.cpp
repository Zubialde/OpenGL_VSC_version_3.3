#include "scene/ResourceManager.h"
#include "ECS/scene.h"

void ResourceManager::SetScene(std::shared_ptr<Scene> scene)
{
    currentScene = scene;
    CheckLights();
    CheckCamera();
}

void ResourceManager::CheckLights()
{
    for(int i = 0; i < currentScene->gameObjects.size(); i++)
    {
        if(DirectionalLight* light = currentScene->gameObjects[i]->GetComponent<DirectionalLight>(); light != nullptr)
        {
            directionalLights.push_back(light->info);
        }
        if(PointLight* light = currentScene->gameObjects[i]->GetComponent<PointLight>(); light != nullptr)
        {
            pointLights.push_back(light->info);
        }
        if(SpotLight* light = currentScene->gameObjects[i]->GetComponent<SpotLight>(); light != nullptr)
        {
            SpotLights.push_back(light->info);
        }
    }
}

void ResourceManager::CheckCamera()
{
    this->cameras = camera.info;
    cameras.position = glm::vec3(0.0f, 0.0f, 3.0f);
}