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
    std::vector<Material> materials;
};



class Model : public Component{
    public:

    Model(char* path, ShaderClass& shader) : Component(parent) {
        LoadModel(path);
    };

    void Draw(ShaderClass& shader);

    private:
    
    std::vector<ModelData> models;

    std::vector<std::unique_ptr<MeshLoader>> meshes;
    std::vector<Texture> textures_loaded; 

    std::string directory;

    void LoadModel(std::string path);
    void processNode(aiNode* node,  const aiScene* scene);
    std::unique_ptr<MeshLoader> processMesh(aiMesh* mesh, const aiScene* scene);
    std::vector<Texture> procesMaterial(aiMaterial* material);
    std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
    unsigned int TextureFromFile(const char *path, const std::string &directory);

};

#endif