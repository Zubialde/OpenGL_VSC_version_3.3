#ifndef MODEL_H
#define MODEL_H

#include <assimp/Importer.hpp>      // C++ importer
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include <Stb_Image/stb_image.h>

#include <renderer/ShaderClass.h>
#include <ECS/Components/MeshLoader.h>
#include <renderer/ShaderUpLoader.h>

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

class   Model : public Component{
    public:

    /// @brief Initializes the model component
    /// @param path Model path
    /// @param vertexPath Vertex shader path
    /// @param fragmentPath Fragment shader path
    Model( const std::string path){
        ResourceManager::GetInstance().GetModel(path);
    };

    void Start() override{};
    void Update(float deltaTime) override{};
    void OnDestroy() override{};

    private:
};

#endif