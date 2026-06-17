#include "ECS/scene.h"

Scene::Scene(std::string name)
{
    this->name = name;
    }

void Scene::Update(float deltaTime)
{
    for(const std::shared_ptr<GameObject> i : gameObjects)
    {
        i->Update(deltaTime);
    }
    currentCamera->Update(deltaTime);
}

void Scene::AddGameObject(std::shared_ptr<GameObject>& gameObject)
{
    gameObjects.push_back(gameObject);
}

std::shared_ptr<GameObject> Scene::Instantiate(std::string name)
{
    std::shared_ptr<GameObject> newObject = std::make_shared<GameObject>();
    newObject->name = name;
    return newObject;
}

//IMPORTANT: DO NOT USE THIS FUNCTION FOR ANY OTHER PURPOSE THAN LOADING OBJECTS OR ADDING COMPONENTS
void Scene::Load()
{
    std::shared_ptr<GameObject> object = Instantiate("Cube");
    object->transform.info.position = glm::vec3(0.0f, 0.0f, 0.0f);
    object->AddComponent<Model>("backpack.obj");
    object->AddComponent<Material>("BaseLit.vs", "diffuse.jpg");
    AddGameObject(object);
    
    std::shared_ptr<GameObject> object3 = Instantiate("MainCamera");
    object3->transform.info.position = glm::vec3(0.0f, 0.0f, 10.0f);
    object3->AddComponent<Camera>();
    object3->AddComponent<CameraFlightControl>();
    SetCurrentCamera(object3);
}

void Scene::SetCurrentCamera(std::shared_ptr<GameObject> camera)
{
    currentCamera = camera;
}

std::shared_ptr<GameObject> Scene::GetCurrentCamera()
{
    return currentCamera;
}

//For destroying gameObjects never used it thought :P
void Scene::Unload()
{

}