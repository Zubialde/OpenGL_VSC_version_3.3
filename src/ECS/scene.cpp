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
    object->AddComponent<Model>("backpack.obj");
    object->AddComponent<Material>("Vertex.vs", "Fragment.fs");
    AddGameObject(object);

    std::shared_ptr<GameObject> object2 = Instantiate("Directional Light");
    object2->AddComponent<DirectionalLight>();
    AddGameObject(object2);

    std::shared_ptr<GameObject> object3 = Instantiate("MainCamera");
    object3->AddComponent<Camera>();
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