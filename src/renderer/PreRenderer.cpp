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
        Material* material = gameObject->GetComponent<Material>();
        glm::mat4 modelMatrix = gameObject->transform.GetModelMatrix();

        for(const Mesh& model : models->mesh)
        {
            RenderPacket renderPackage;
            
            renderPackage.sortKey = 0;
            renderPackage.vaoID = model.vaoID;
            renderPackage.indexCount = model.indices.size();
            renderPackage.modelMatrix = modelMatrix;
            //renderPackage.textureID = gameObject->GetComponent<Material>()->textureID;

            if(material != nullptr)
            {
                renderPackage.shaderID = material->instanceData->shaderID;
                renderPackage.textureID = material->instanceData->textures[0];
            }
            else
            {
                renderPackage.shaderID = model.materialData.shaderID;
                renderPackage.textureID = model.materialData.textures[0];
            }
            
        }
    }
}


