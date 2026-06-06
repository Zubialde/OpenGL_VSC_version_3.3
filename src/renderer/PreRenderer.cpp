#include "renderer/PreRenderer.h"

void PreRenderer::FetchGameObjects()
{
    for(const auto& gameObject : SceneManager::GetInstance().GetCurrentScene().gameObjects)
    {
        if(gameObject->GetComponent<Model>() != nullptr)
            renderableObjects.push_back(gameObject.get());
    }

    CreateRenderPackages();
}

void PreRenderer::CreateRenderPackages()
{
    //Loop through all renderable gameObjects and creates  a RenderPackage for each mesh
    for(auto* gameObject : renderableObjects)
    {
        ModelData* models = ResourceManager::GetInstance().GetModel(gameObject->GetComponent<Model>()->path).get();

        for(auto& model : models->mesh)
        {
            RenderPackage renderPackage;
            renderPackage.mesh = &model;
            renderPackage.shader = ResourceManager::GetInstance().GetShader(gameObject->GetComponent<Material>()->vertexPath);
            renderPackage.material = &model.material;
            renderPackage.modelMatrix = gameObject->transform.GetModelMatrix();
            
            renderPackage.viewDepth = 0;
            renderPackage.id = 0;
            renderPackages->push_back(renderPackage);
        }
    }
}


