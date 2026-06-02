#include "core/SceneManager.h"

Scene& SceneManager::GetCurrentScene() const
{
    return *currentScene.get();
}

void SceneManager::setCurrentScene(std::unique_ptr<Scene> scene)
{
    currentScene = std::move(scene);
}