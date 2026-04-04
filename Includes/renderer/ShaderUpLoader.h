#ifndef SHADERUPLOADER_H
#define SHADERUPLOADER_H


#include <renderer/ShaderClass.h>
#include <renderer/TextureClass.h>
#include <ECS/Components/Material.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>


struct TextureData{ 
    std::string path; //We store the path to check if its already loaded
    unsigned int id;
    std::string type;
};

class ShaderUploader
{
    public:

    TextureData textures;
    std::vector<TextureData> textures_loaded;

    MaterialData material;
    
    ShaderUploader(TextureData texture, MaterialData material, ShaderClass& shader);
    ~ShaderUploader();

    void Draw(ShaderClass& shader);

    private:

    void LoadTextures(ShaderClass& shader);
    void LoadVariables(ShaderClass& shader);
};

#endif