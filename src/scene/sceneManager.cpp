#include "scene/sceneManager.h"
#include "ECS/Components/DirectionalLight.h"

SceneManager::SceneManager()
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

void CheckLights()
{

}