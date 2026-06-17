#include "ECS/Systems/PreRenderer.h"

void PreRenderer::FetchRenderData(Scene& scene)
{
    FetchGlobalRenderData(scene);

    for(const std::shared_ptr<GameObject>& gameObject : scene.gameObjects)
    {
        if(gameObject->GetComponent<Model>() == nullptr)
            continue;

        GameObject* gameObjectPtr = gameObject.get();
        
        ModelData* models = gameObjectPtr->GetComponent<Model>()->model.get();
        Material* material = gameObjectPtr->GetComponent<Material>(); 
        glm::mat4 modelMatrix = gameObjectPtr->transform.GetModelMatrix();


        if (models == nullptr)
            continue;

        float distance = glm::distance(globalRenderPackage.cameraPosition, gameObjectPtr->transform.info.position);

        uint64_t depthInt = static_cast<uint64_t>(distance * 100.0f);

        for(const Mesh& mesh : models->mesh)
        {
            RenderPackage renderPackage;
            
            renderPackage.sortKey = 0;
            renderPackage.vaoID = mesh.vaoID;
            renderPackage.indexCount = mesh.indices.size();
            renderPackage.modelMatrix = modelMatrix;

            if(material != nullptr)
            {
                renderPackage.shaderID = material->instanceData.shaderID;
                renderPackage.textureID = material->instanceData.textures;
            }
            else
            {
                renderPackage.material = mesh.materialData;
                renderPackage.shaderID = mesh.materialData.shaderID;
                renderPackage.textureID = mesh.materialData.textures;                
            }



            uint64_t shader64 = static_cast<uint64_t>(renderPackage.shaderID);
            uint64_t texture64 = static_cast<uint64_t>(renderPackage.textureID[0]); 

            // Pack the 64-bit integer
            // Bit 63: 0 (Opaque Pass implied)
            // Bits 52-62: Shader ID
            // Bits 36-51: Texture ID
            // Bits 0-35: Depth (Uninverted for Front-To-Back sorting)
            renderPackage.sortKey = (shader64 << 52) | (texture64 << 36) | depthInt;

            renderPackages.push_back(renderPackage);
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
    
void PreRenderer::FetchGlobalRenderData(Scene& scene)
{
    std::shared_ptr<GameObject> currentCamera = scene.GetCurrentCamera();

    globalRenderPackage.cameraPosition = currentCamera->transform.info.position;
    globalRenderPackage.viewMatrix = currentCamera->GetComponent<Camera>()->GetViewMatrix();    
    globalRenderPackage.projectionMatrix = currentCamera->GetComponent<Camera>()->GetProjectionMatrix();

    std::vector<DirectionalLightInfo> directionalLights;
    std::vector<PointLightInfo> pointLights;
    std::vector<SpotLightInfo> spotLights;

    for(const DirectionalLight* light : scene.directionalLights)
    {
        DirectionalLightInfo lightInfo;
        lightInfo.direction = light->info.direction;
        lightInfo.color = light->info.color;
        lightInfo.intensity = light->info.intensity;
        directionalLights.push_back(lightInfo);
    }

    for(const PointLight* light : scene.pointLights)
    {
        PointLightInfo lightInfo;
        lightInfo.position = light->info.position;
        lightInfo.color = light->info.color;
        lightInfo.intensity = light->info.intensity;
        pointLights.push_back(lightInfo);
    }

    for(const SpotLight* light : scene.spotLights)
    {
        SpotLightInfo lightInfo;
        lightInfo.position = light->info.position;
        lightInfo.direction = light->info.direction;
        lightInfo.color = light->info.color;
        lightInfo.intensity = light->info.intensity;
        spotLights.push_back(lightInfo);
    }

    globalRenderPackage.directionalLights = directionalLights;
    globalRenderPackage.pointLights = pointLights;
    globalRenderPackage.spotLights = spotLights;
}