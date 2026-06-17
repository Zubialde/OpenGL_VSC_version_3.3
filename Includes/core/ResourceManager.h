#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H


// Third party
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <stb_image/stb_image.h>
#include <assimp/Importer.hpp>      // C++ importer
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

//Own
#include <utils/Singleton.h>
#include <renderer/ShaderClass.h>
#include <renderer/TextureClass.h>
#include <utils/Debugger.h>
#include <renderer/MaterialData.h>

// CPP native
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <unordered_map>
#include <memory>

struct Vertex{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

struct Mesh{
    std::vector<Vertex> vertices;
    //aiMatrix4x4 meshTransform;
    std::vector<unsigned int> indices {0};
    unsigned int vaoID {0};
    unsigned int vboID {0};
    unsigned int eboID {0};

    MaterialData materialData;
};

struct ModelData{
    std::vector<Mesh> mesh;
};

/// @brief ResourceManager stores the paths of all resources in a double lazy map to prevent loading resources that are not used.
class ResourceManager: public Singleton<ResourceManager>{
    
    friend class Singleton<ResourceManager>;
    public:

    std::unordered_map<std::string, std::string> texturePaths;
    std::unordered_map<std::string, std::string> shaderPaths;
    std::unordered_map<std::string, std::string> modelPaths;

    std::unordered_map<std::string, std::unique_ptr<TextureClass>> loadedTextures;
    std::unordered_map<std::string, std::unique_ptr<ShaderClass>> loadedShaders;
    std::unordered_map<std::string, std::weak_ptr<ModelData>> loadedModels;

    //Do i add Registries? and how?

    void searchDirectory(const std::string& directory);

    TextureClass* GetTexture(const std::string& path);
    ShaderClass* GetShader(const std::string& path);
    std::shared_ptr<ModelData> GetModel(const std::string& path);

    private:
    ResourceManager() = default;    
    
    void processNode(aiNode* node, const aiScene* scene, std::shared_ptr<ModelData> modelData);
    void processMesh(aiMesh* mesh, const aiScene* scene, std::shared_ptr<ModelData> modelData);
};
#endif