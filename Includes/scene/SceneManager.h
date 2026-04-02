#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H


#include <ECS/GameObject.h>

#include <ECS/Components/DirectionalLight.h>
#include <ECS/Components/PointLight.h>
#include <ECS/Components/SpotLight.h>

#include <ECS/scene.h>

#include <iostream>
#include <vector>
#include <memory>

class SceneManager
{
    public:

    std::vector<SpotLightInfo> SpotLights;
    std::vector<DirectionaLightInfo> directionalLights;
    std::vector<PointLightInfo> pointLights;

    SceneManager();

    void CheckLights();

    private:
    std::unique_ptr<Scene> currentScene;
};
#endif