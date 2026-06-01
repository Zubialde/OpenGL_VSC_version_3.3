#ifndef RENDERQUEUE_H
#define RENDERQUEUE_H

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>    

#include <utils/Singleton.h>

#include <ECS/scene.h>
#include <ECS/GameObject.h>



class RenderQueue : public Singleton<RenderQueue>
{
    friend class Singleton<RenderQueue>;
    public:

    std::shared_ptr<Scene> currentScene;

    std::vector<std::shared_ptr<GameObject>> gameObjects;
    
    void setScene(std::shared_ptr<Scene> scene);

    void RenderCycle();

    private:
    RenderQueue() = default;

};

#endif