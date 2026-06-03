#ifndef PRERENDERER_H
#define PRERENDERER_H

#include <assimp/Importer.hpp>      // C++ importer
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include <glm/glm.hpp>


#include <core/SceneManager.h>
#include <core/ResourceManager.h>
#include <ECS/GameObject.h>

#include <memory>
#include <vector>
struct RenderPackage
{
    glm::mat4 modelMatrix;
    int modelID;
    int shaderID;
    int textureID;
};

class PreRenderer : public Singleton<PreRenderer>
{
    friend class Singleton<PreRenderer>;
    public:

    void FilterGameObjects();
    void CreateRenderPackages(std::vector<RenderPackage>& renderPackages);
    

    private:
    PreRenderer() = default;
    ~PreRenderer() = default;

    std::vector<GameObject*> gameObjects;
};


#endif