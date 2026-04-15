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

// FIXME: This function dosent support materials and loses data.
void ResourceManager::processMesh(aiMesh* mesh, const aiScene* scene, std::shared_ptr<ModelData> modelData)
{
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    
    for(unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        glm:: vec3 vec;
        vec.x = mesh->mVertices[i].x;
        vec.y = mesh->mVertices[i].y;
        vec.z = mesh->mVertices[i].z;
        vertices.push_back(Vertex{vec, glm::vec3(0.0f), glm::vec2(0.0f)});

        if(mesh->HasNormals())
        {
            glm:: vec3 vec;
            vec.x = mesh->mNormals[i].x;
            vec.y = mesh->mNormals[i].y;
            vec.z = mesh->mNormals[i].z;
            vertices.back().normal = vec;
        }
        else
            vertices.back().normal = glm::vec3(0.0f);
        
        if(mesh->HasTextureCoords(0))
        {
            glm::vec2 vec;
            vec.x = mesh->mTextureCoords[0][i].x;
            vec.y = mesh->mTextureCoords[0][i].y;
            vertices.back().texCoords = vec;
        }
        else
            vertices.back().texCoords = glm::vec2(0.0f);
    }

    for(unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        for(unsigned int j = 0; j < face.mNumIndices; j++)
        {
            indices.push_back(face.mIndices[j]);
        }
    }

    modelData->mesh.push_back(Meshes{vertices, indices});
}