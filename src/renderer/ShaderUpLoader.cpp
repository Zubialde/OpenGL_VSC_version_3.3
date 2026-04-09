#include "renderer/ShaderUpLoader.h"

ShaderUploader::ShaderUploader(TextureData texture, MaterialData material, ShaderClass& shader, glm::mat4 model)
{
    this->textures = texture;
    this->material = material;
    this->model = model;
}

ShaderUploader::~ShaderUploader()
{

}

void ShaderUploader::Draw(ShaderClass& shader)
{
    shader.use();
    LoadTextures(shader);
    LoadVariables(shader);
    LoadMatrices(shader);

}

void ShaderUploader::LoadTextures(ShaderClass& shader)
{
    unsigned int diffuseNr = 1;
    unsigned int specularNr = 1;

    for(unsigned int i = 0; i < textures_loaded.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i);
        // retrieve texture number (the N in diffuse_textureN)s
        std::string number;
        std::string name = textures_loaded[i].type;
        if(name == "texture_diffuse")
            number = std::to_string(diffuseNr++);
        else if(name == "texture_specular")
            number = std::to_string(specularNr++);

        shader.setInt(("material." + name + number).c_str(), i);
        glBindTexture(GL_TEXTURE_2D, textures_loaded[i].id);
    }
    glActiveTexture(GL_TEXTURE0);
}

void ShaderUploader::LoadVariables(ShaderClass& shader)
{
    shader.setFloat("material.shininess", material.shininess);
    shader.setVec3("material.ambient", material.ambient);
    shader.setVec3("material.diffuse", material.diffuse);
    shader.setVec3("material.specular", material.specular);
}

void ShaderUploader::LoadMatrices(ShaderClass& shader)
{
    shader.setMat4("view", RenderingSystem::GetInstance().cameras.view);
    shader.setMat4("projection", RenderingSystem::GetInstance().cameras.projection);
    shader.setMat4("model", model);
}
