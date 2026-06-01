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

void Scene::Load()
{
    std::shared_ptr<GameObject> object = Instantiate("Cube");
    object->AddComponent<DirectionalLight>(glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f), 1.0f);
    object->AddComponent<Model>("backpack/backpack.obj");

    AddGameObject(object);
}

//Unload all the gameObjects (this is probably not needed since the gameObject will be destroyed when the program ends anyway)
void Scene::Unload()
{

}