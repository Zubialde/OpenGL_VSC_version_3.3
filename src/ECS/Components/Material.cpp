#include <ECS/Components/Material.h>

void Material::Draw()
{
    LoadTextures(shader);
    LoadVariables(shader);
}

void Material::LoadTextures(ShaderClass& shader)
{
    unsigned int diffuseNr = 1;
    unsigned int specularNr = 1;

    for(unsigned int i = 0; i < textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i);
        // retrieve texture number (the N in diffuse_textureN)s
        std::string number;
        std::string name = textures[i].type;
        if(name == "texture_diffuse")
            number = std::to_string(diffuseNr++);
        else if(name == "texture_specular")
            number = std::to_string(specularNr++);

        shader.setInt(("material." + name + number).c_str(), i);
        glBindTexture(GL_TEXTURE_2D, textures[i].id);
    }
    glActiveTexture(GL_TEXTURE0);
}

void Material::LoadVariables(ShaderClass& shader)
{
    shader.setVec3("material.ambient", data.ambient);
    shader.setVec3("material.diffuse", data.diffuse);
    shader.setVec3("material.specular", data.specular);
    shader.setFloat("material.shininess", data.shininess);
}

