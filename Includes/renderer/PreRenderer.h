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
    Mesh* mesh {nullptr};
    ShaderClass* shader {nullptr};
    //std::array<TextureClass*, 16> textures {nullptr};
    Lit* material {nullptr};
    glm::mat4 modelMatrix {glm::mat4(1.0f)};
    int viewDepth {0};
    uint64_t id {0};    
};

//Should i store the information 
struct RenderPacket
{
    uint64_t sortKey;
    unsigned int vaoID;
    unsigned int indexCount;
    int shaderID;
    int textureID;
    glm::mat4 modelMatrix;
};

class PreRenderer : public Singleton<PreRenderer>
{
    friend class Singleton<PreRenderer>;
    public:


    void FetchGameObjects();
    void CreateRenderPackages();
    
    std::vector<RenderPacket>* renderPackages;

    private:
    PreRenderer() = default;
    ~PreRenderer() = default;

    std::vector<GameObject*> renderableObjects;
};



#endif