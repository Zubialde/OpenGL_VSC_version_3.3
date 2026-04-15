#ifndef RENDERINGSYSTEM_H
#define RENDERINGSYSTEM_H

#include <utils/Singleton.h>
#include <utils/Debugger.h>

#include <ECS/GameObject.h>
#include <core/ResourceManager.h>

#include <ECS/Components/DirectionalLight.h>
#include <ECS/Components/PointLight.h>
#include <ECS/Components/SpotLight.h>
#include <scene/CameraClass.h>

#include <scene/CameraClass.h>

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>

class Scene;

struct SceneInfo{
    std::vector<std::shared_ptr<GameObject>> gameObjects;
    std::vector<std::shared_ptr<DirectionalLight>> directionalLights;

    std::weak_ptr<CameraInfo> cameras;
};


/// Reads Queueu -> Loads data from ResourceManager -> Loads Buffer -> 

// TODO: Optimize the rendering system by using a more efficient data structure for the lights and cameras, maybe a map or a set to avoid duplicates and improve lookup times.
class RenderingSystem : public Singleton<RenderingSystem>
{    
    friend class Singleton<RenderingSystem>;

    public:
    
    std::vector<SpotLightInfo> SpotLights;
    std::vector<DirectionalLightInfo> directionalLights;
    std::vector<PointLightInfo> pointLights;    
    CameraInfo cameras;    

    void SetScene(std::shared_ptr<Scene> scene);

    void RenderCycle();

    private:
    
    RenderingSystem() = default;
    
    std::shared_ptr<Scene> currentScene;

    Camera camera;   
    
    void CheckLights(Scene& currentScene);

    void CheckCamera(Scene& currentScene);

    uint16_t currentCamera;

};
#endif