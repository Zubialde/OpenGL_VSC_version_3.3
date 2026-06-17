#ifndef SCENE_H
#define SCENE_H

#include <ECS/Components/CameraClass.h>
#include <ECS/GameObject.h>
#include <ECS/Components/Transform.h>
#include <ECS/Components/Model.h>
#include <ECS/Components/Material.h>
#include <ECS/Components/DirectionalLight.h>
#include <ECS/Components/PointLight.h>
#include <ECS/Components/SpotLight.h>
#include <ECS/Components/CameraFlightControl.h>

#include <iostream>
#include <vector>


class Scene{
    public:
    
    std::string name;

    std::vector<std::shared_ptr<GameObject>> gameObjects;

    std::vector<PointLight*> pointLights;
    std::vector<DirectionalLight*> directionalLights;
    std::vector<SpotLight*> spotLights;

    void SetCurrentCamera(std::shared_ptr<GameObject> camera);

    std::shared_ptr<GameObject> GetCurrentCamera();

    Scene(std::string name);

    void Update(float deltaTime);

    void Load();

    void Unload();

    private:

    std::shared_ptr<GameObject> currentCamera;  

    void AddGameObject(std::shared_ptr<GameObject>& gameObject);

    std::shared_ptr<GameObject> Instantiate(std::string name);    

    void AddPointLight(std::shared_ptr<GameObject> gameObject);
    void AddSpotLight(std::shared_ptr<GameObject> gameObject);
    void AddDirectionalLight(std::shared_ptr<GameObject> gameObject);
};

#endif