#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <utils/Singleton.h>
#include <ECS/Scene.h>

#include <vector>
#include <memory>


class SceneManager : public Singleton<SceneManager>
{
    friend class Singleton<SceneManager>;
    public:

    //Gets the current scene
    Scene& GetCurrentScene() const;

    //Sets the current scene
    void setCurrentScene(std::unique_ptr<Scene> scene);

    private:
    SceneManager() = default;

    //Holds the current scene
    std::unique_ptr<Scene> currentScene;    
};

#endif