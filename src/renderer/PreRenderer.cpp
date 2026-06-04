#include "renderer/PreRenderer.h"
#include "ECS/GameObject.h"

/*void PreRenderer::FetchGameObjects()
{
    //Iterador que busca todos los gameObjects en escena y guarda los que tengan el componente Model
    for(const auto& gameObject : SceneManager::GetInstance().GetCurrentScene().gameObjects)
    {
        if(gameObject->GetComponent<Model>() != nullptr)
            gameObjects.push_back(gameObject.get());
    }
}

void PreRenderer::CreateRenderPackages(std::vector<RenderPackage>& renderPackages)
{
    //Loop through all renderable gameObjects
    for(const auto& gameObject : gameObjects)
    {
        std::vector<ModelData*> models = ResourceManager::GetInstance().GetModel(gameObject->GetComponent<Model>()->path);

        foreach(ModelData* model in models)
        {
            //Pasa toda la información del RenderPackage 
            // ModelMatrix & 

            RenderPackage renderPackage;
            renderPackage.modelMatrix = gameObject.transform.GetMatrix() * model->transform;
            renderPackages.push_back(renderPackage);
        }
        ResourceManager::GetInstance().GetModel(gameObject->GetComponent<Model>()->path);

    }
}*/
