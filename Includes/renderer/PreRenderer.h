#ifndef PRERENDERER_H
#define PRERENDERER_H

#include <assimp/Importer.hpp>      // C++ importer
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include <glm/glm.hpp>

#include <core/ResourceManager.h>
#include <ECS/GameObject.h>
#include <ECS/Scene.h>

#include <ECS/Components/DirectionalLight.h>
#include <ECS/Components/PointLight.h>
#include <ECS/Components/SpotLight.h>
#include <ECS/Components/CameraFlightControl.h>

#include <memory>
#include <vector>


/// @brief RenderPackage stores the information for a renderable object
/// @param textureID The maximum number of textures permited by OpenGL is 16
struct RenderPackage
{
    uint64_t sortKey;
    unsigned int vaoID;
    unsigned int indexCount;
    int shaderID;
    std::array<unsigned int, 16> textureID;
    glm::mat4 modelMatrix;
};

struct GlobalRenderPackage
{
    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;

    std::vector<DirectionalLightInfo> directionalLights;
    std::vector<PointLightInfo> pointLights;
    std::vector<SpotLightInfo> spotLights;
};

class PreRenderer : public Singleton<PreRenderer>
{
    friend class Singleton<PreRenderer>;
    public:

    void FetchGlobalRenderData(Scene& scene);

    void FetchRenderData(Scene& scene);

    void SortRenderPackages(std::vector<RenderPackage>* renderPackages);
    
    std::vector<RenderPackage> renderPackages;
    GlobalRenderPackage* globalRenderPackage;

    private:
    PreRenderer() = default;
    ~PreRenderer() = default;
};



#endif