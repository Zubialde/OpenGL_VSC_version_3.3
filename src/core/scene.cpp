#include "core/scene.h"

Scene::Scene(std::string name)
{
    this->name = name;
}

void Scene::Update(float deltaTime)
{
    for(const std::shared_ptr<GameObject>& i : gameObjects)
    {
        i->Update(deltaTime);
    }

}

void Scene::AddGameObject(std::shared_ptr<GameObject>& gameObject)
{
    gameObjects.push_back(gameObject);
}

void Scene::Load()
{
    std::shared_ptr<GameObject> object = std::make_shared<GameObject>();
    object->AddComponent<Transform>(glm::vec3(1000.0f, 0.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

    AddGameObject(object);
}

//Unload all the gameObjects (this is probably not needed since the gameObject will be destroyed when the program ends anyway)
void Scene::Unload()
{

}