#ifndef MODEL_H
#define MODEL_H

#include <assimp/Importer.hpp>      // C++ importer
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

#include <renderer/ShaderClass.h>
#include <Stb_Image/stb_image.h>

#include <ECS/Components/Material.h>
#include <ECS/Components/MeshLoader.h>

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

struct ModelData{
    std::unique_ptr<MeshLoader> mesh;
    std::unique_ptr<Material> materials;
};
class Model : public Component{
    public:

    /// @brief Initializes the model component
    /// @param path Model path
    /// @param vertexPath Vertex shader path
    /// @param fragmentPath Fragment shader path
    Model(const char* path, const char* vertexPath, const char* fragmentPath) : Component(parent), shader(vertexPath, fragmentPath){
        LoadModel(path);
    };


    void Start() override {};
    void Update(float deltaTime) override;
    void OnDestroy() override {};

    private:
    
    std::vector<ModelData> models;

    std::vector<TextureData> textures_loaded; 

    std::string directory;

    ShaderClass shader;


    void LoadModel(std::string path);
    void processNode(aiNode* node,  const aiScene* scene);
    ModelData processMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<TextureData> procesMaterial(aiMaterial* material);
    std::vector<TextureData> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
    unsigned int TextureFromFile(const char *path, const std::string &directory);

};

#endif