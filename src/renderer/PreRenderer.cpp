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
    for(GameObject* gameObject : renderableObjects)
    {
        ModelData* models = ResourceManager::GetInstance().GetModel(gameObject->GetComponent<Model>()->path).get();

        for(const Mesh& model : models->mesh)
        {
            RenderPacket renderPackage;
            renderPackage.sortKey = 0;
            renderPackage.vaoID = model.vaoID;
            renderPackage.indexCount = model.indices.size();
            renderPackage.shaderID = ResourceManager::GetInstance().GetShader(gameObject->GetComponent<Material>()->vertexPath)->ID;
            //renderPackage.textureID = gameObject->GetComponent<Material>()->textureID;
        }
    }
}


