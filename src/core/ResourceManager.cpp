#include "core/ResourceManager.h"

void ResourceManager::searchDirectory(const std::string& directory)
{
    for(const auto& entry : std::filesystem::recursive_directory_iterator(directory))
    {
        if(entry.is_regular_file())
        {
            std::string file = entry.path().string();
            std::string extension = file.substr(file.find_last_of(".") + 1);
            
            if(extension == "obj" || extension == "fbx" || extension == "gltf")
            {
                models[file] = file;
            }
            else if(extension == "png" || extension == "jpg" || extension == "jpeg")
            {
                textures[file] = file;
            }
            else if(extension == "vs" || extension == "fs" || extension == "geo")
            {
                shaders[file] = file;
            }
        }
    }
}