#include "renderer/PreRenderer.h"
#include "ECS/GameObject.h"

/*void PreRenderer::FilterGameObjects()
{
    for(const auto& gameObject : SceneManager::GetInstance().GetCurrentScene().gameObjects)
    {
        if(gameObject->GetComponent<Model>() != nullptr)
            gameObjects.push_back(gameObject.get());
    }
}

void PreRenderer::CreateRenderPackages(std::vector<RenderPackage>& renderPackages)
{
    for(const auto& gameObject : gameObjects)
    {
        ResourceManager::GetInstance().GetModel(gameObject->GetComponent<Model>()->path);

    }
}*/
