#include <ECS/Components/Material.h>
#include <ECS/GameObject.h>

Material::Material(const char* vertexPath, const char* fragmentPath)
{
    shader = GetShader(vertexPath, fragmentPath);
}


void Material::Draw()
{

}

std::shared_ptr<ShaderClass> Material::GetShader(std::string vertexPath, std::string fragmentPath)  
{
    std::string cacheKey = vertexPath + "_" + fragmentPath;
    auto it = shaderCache.find(cacheKey);
    if (it != shaderCache.end()) {
        return it->second;
    }

    shaders.push_back(std::make_shared<ShaderClass>(vertexPath.c_str(), fragmentPath.c_str()));
    shaderCache[cacheKey] = shaders.back();
    return shaders.back();
}



