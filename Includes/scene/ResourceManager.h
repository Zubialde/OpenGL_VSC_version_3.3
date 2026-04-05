#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <ECS/GameObject.h>

#include <ECS/Components/DirectionalLight.h>
#include <ECS/Components/PointLight.h>
#include <ECS/Components/SpotLight.h>

#include <scene/CameraClass.h>

#include <ECS/scene.h>

#include <iostream>
#include <vector>
#include <memory>

/// @brief ResourceManager holds global information of the scene, this includes lights, cameras...
class ResourceManager
{
    public:
    std::vector<SpotLightInfo> SpotLights;
    std::vector<DirectionaLightInfo> directionalLights;
    std::vector<PointLightInfo> pointLights;

    CameraInfo cameras;

    ResourceManager(std::unique_ptr<Scene> scene);

    void CheckLights();

    void CheckCamera();

    private:
    std::unique_ptr<Scene> currentScene;

     Camera camera;
};
#endif