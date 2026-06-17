#ifndef MODEL_H
#define MODEL_H

#include <assimp/Importer.hpp>      // C++ importer
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include <Stb_Image/stb_image.h>

#include <renderer/ShaderClass.h>
#include <ECS/Components/Component.h>
#include <core/ResourceManager.h>
#include <ECS/Components/Material.h>

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>

class Model : public Component{
    public:

    /// @brief Initializes the model component
    /// @param path Model path
    Model( const std::string path){
        this->path = path;
    };

    std::string path;
    std::shared_ptr<ModelData> model;


    void Start() override{
    this->model = ResourceManager::GetInstance().GetModel(path);

    };
    void Update(float deltaTime) override{

    };
    void OnDestroy() override{};

    private:
};

#endif