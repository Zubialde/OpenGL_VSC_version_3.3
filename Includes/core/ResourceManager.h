#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

// CPP native
#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <unordered_map>
#include <memory>

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

struct Vertex{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

struct Meshes{
    std::vector<Vertex> vertices;
    //aiMatrix4x4 meshTransform;
    std::vector<unsigned int> indices;
};

struct ModelData{
    std::vector<Meshes> mesh;
    //aiMatrix4x4 modelTransform;
};

/// @brief ResourceManager stores the paths of all resources in a double lazy map to prevent loading resources that are not used.
class ResourceManager: public Singleton<ResourceManager>{
    
    friend class Singleton<ResourceManager>;
    public:

    std::unordered_map<std::string, std::string> texturePaths;
    std::unordered_map<std::string, std::string> shaderPaths;
    std::unordered_map<std::string, std::string> modelPaths;

    //Maybe this should be a shared_ptr since the Rendering System will need it to create Texture Packages and Models
    std::unordered_map<std::string, std::unique_ptr<TextureClass>> loadedTextures;
    std::unordered_map<std::string, std::unique_ptr<ShaderClass>> loadedShaders;
    std::unordered_map<std::string, std::weak_ptr<ModelData>> loadedModels;

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