#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <ECS/GameObject.h>

#include <ECS/Components/DirectionalLight.h>
#include <ECS/Components/PointLight.h>
#include <ECS/Components/SpotLight.h>

#include <scene/CameraClass.h>

#include <iostream>
#include <vector>
#include <memory>

class Scene;

/// @brief ResourceManager holds global information of the scene, this includes lights, cameras...
class ResourceManager
{
    public:

    std::vector<SpotLightInfo> SpotLights;
    std::vector<DirectionaLightInfo> directionalLights;
    std::vector<PointLightInfo> pointLights;    
    CameraInfo cameras;    

    void SetScene(std::shared_ptr<Scene> scene);

    static ResourceManager& GetInstance();

    private:

    std::shared_ptr<Scene> currentScene;

    Camera camera;   

    ResourceManager(){};
    
    void CheckLights();

    void CheckCamera();

};
#endif