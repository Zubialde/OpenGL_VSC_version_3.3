#include "core/ResourceManager.h"

void ResourceManager::searchDirectory(const std::string& directory)
{
    for(const auto& entry : std::filesystem::recursive_directory_iterator(directory))
    {
        if(entry.is_regular_file())
        {
            std::string file = entry.path().string();
            std::string extension = entry.path().extension().string();
            
            if(extension == "obj" || extension == "fbx" || extension == "gltf")
            {
                modelPaths[file] = file;
            }
            else if(extension == "png" || extension == "jpg" || extension == "jpeg")
            {
                texturePaths[file] = file;
            }
            else if(extension == "vs" || extension == "fs" || extension == "geo")
            {
                shaderPaths[file] = file;
            }
        }
    }
}

TextureClass* ResourceManager::GetTexture(const std::string& path)
{
    std::unordered_map<std::string, std::unique_ptr<TextureClass>>::iterator loadedIt = loadedTextures.find(path);

    //The .end is missleading it determines the boundaries so if it is nonexistant then this will not occur
    if(loadedIt != loadedTextures.end())
        return loadedIt->second.get();

    auto it = texturePaths.find(path);
    if(it != texturePaths.end())
    {
        loadedTextures[path] = std::make_unique<TextureClass>(it->second.c_str(), GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR);
        return loadedTextures[path].get();        
    }

    return nullptr;
}

ShaderClass* ResourceManager::GetShader(const std::string& path)
{
    std::unordered_map<std::string, std::unique_ptr<ShaderClass>>::iterator loadedIt = loadedShaders.find(path);

    if(loadedIt != loadedShaders.end())
        return loadedIt->second.get();

    auto it = shaderPaths.find(path);
    if(it != shaderPaths.end())
    {
        // Assume path is vertex shader, find fragment
        std::string base = it->second.substr(0, it->second.find_last_of('.'));
        std::string vs = base + ".vs";
        std::string fs = base + ".fs";
        loadedShaders[path] = std::make_unique<ShaderClass>(vs.c_str(), fs.c_str());
        return loadedShaders[path].get();
    }

    return nullptr;
}


std::shared_ptr<ModelData>ResourceManager::GetModel(const std::string& path)
{
    std::unordered_map<std::string, std::weak_ptr<ModelData>>::iterator loadedIt = loadedModels.find(path);

    if(loadedIt != loadedModels.end())
    {
        std::shared_ptr<ModelData> modelData = loadedIt->second.lock();
        if(modelData)
            return modelData;
    }

    Assimp::Importer import;

    const aiScene *scene = import.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals | aiProcess_OptimizeMeshes);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        std::cout << "ERROR::ASSIMP::" << import.GetErrorString() << std::endl;
        return nullptr;
    }

    std::shared_ptr<ModelData> modelData = std::make_shared<ModelData>();
    modelData->path = path;

    processNode(scene->mRootNode, scene, modelData);
    loadedModels[path] = modelData;

    return modelData;
}

void ResourceManager::processNode(aiNode* node, const aiScene* scene, std::shared_ptr<ModelData> modelData)
{
    for(unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh *mesh = scene->mMeshes[node->mMeshes[i]]; 
        processMesh(mesh, scene, modelData);
    }

    for(unsigned int i = 0; i < node->mNumChildren; i++)
    processNode(node->mChildren[i], scene, modelData);
}

void ResourceManager::processMesh(aiMesh* mesh, const aiScene* scene, std::shared_ptr<ModelData> modelData)
{
    
}