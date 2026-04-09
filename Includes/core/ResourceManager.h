#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <stb_image/stb_image.h>
#include <assimp/Importer.hpp>      // C++ importer
#include <assimp/scene.h>           // Output data structure

#include <utils/Singleton.h>

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <unordered_map>

struct Vertex{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

struct ModelData{
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::string name;
};

class ResourceManager: public Singleton<ResourceManager>{
    
    friend class Singleton<ResourceManager>;
    public:

    std::unordered_map<std::string, std::string> textures;
    std::unordered_map<std::string, std::string> shaders;
    std::unordered_map<std::string, std::string> models;

    void searchDirectory(const std::string& directory);

    private:
    ResourceManager() = default;
};

#endif