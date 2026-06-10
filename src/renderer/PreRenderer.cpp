#include "renderer/PreRenderer.h"

void PreRenderer::FetchGlobalRenderData(Scene& scene)
{

}

void PreRenderer::FetchRenderData(Scene& scene)
{
    for(const std::shared_ptr<GameObject>& gameObject : scene.gameObjects)
    {
        if(gameObject->GetComponent<Model>() == nullptr)
            continue;

        GameObject* gameObjectPtr = gameObject.get();
        
        ModelData* models = ResourceManager::GetInstance().GetModel(gameObjectPtr->GetComponent<Model>()->path).get();
        Material* material = gameObjectPtr->GetComponent<Material>();
        glm::mat4 modelMatrix = gameObjectPtr->transform.GetModelMatrix();

        for(const Mesh& mesh : models->mesh)
        {
            RenderPackage renderPackage;
            
            renderPackage.sortKey = 0;
            renderPackage.vaoID = mesh.vaoID;
            renderPackage.indexCount = mesh.indices.size();
            renderPackage.modelMatrix = modelMatrix;

            if(material != nullptr)
            {
                renderPackage.shaderID = material->instanceData->shaderID;
                renderPackage.textureID = material->instanceData->textures;
            }
            else
            {
                renderPackage.shaderID = mesh.materialData.shaderID;
                renderPackage.textureID = mesh.materialData.textures;
            }

            renderPackages->push_back(renderPackage);
        }
    }
}

    void SortRenderPackages(std::vector<RenderPackage>* renderPackages)
    {
        std::sort(renderPackages->begin(), renderPackages->end(), [](const RenderPackage& a, const RenderPackage& b)
        {
            return a.sortKey < b.sortKey;
        });
    }