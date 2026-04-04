#ifndef MODEL_H
#define MODEL_H

#include <assimp/Importer.hpp>      // C++ importer
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

#include <renderer/ShaderClass.h>
#include <Stb_Image/stb_image.h>

#include <ECS/Components/MeshLoader.h>
#include <renderer/ShaderUpLoader.h>

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

struct ModelData{
    std::unique_ptr<MeshLoader> mesh;
    std::unique_ptr<ShaderUploader> materials;
};
class   Model : public Component{
    public:

    /// @brief Initializes the model component
    /// @param path Model path
    /// @param vertexPath Vertex shader path
    /// @param fragmentPath Fragment shader path
    Model( const std::string path){
        this->path = path;
    };
    
    void Start() override {LoadModel(MODEL_DIR + path);};
    void Update(float deltaTime) override;
    void OnDestroy() override {};

    private:
    
    std::string path;

    std::vector<ModelData> models;

    std::vector<TextureData> textures_loaded; 

    std::shared_ptr<ShaderClass> shader;

    std::string directory;

    void LoadModel(std::string path);
    void processNode(aiNode* node,  const aiScene* scene);
    ModelData processMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<TextureData> procesMaterial(aiMaterial* material);
    std::vector<TextureData> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
    unsigned int TextureFromFile(const char *path, const std::string &directory);

};

#endif