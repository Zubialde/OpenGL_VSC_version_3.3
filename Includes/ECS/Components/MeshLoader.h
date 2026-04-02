#ifndef MESHLOADER_H
#define MESHLOADER_H

#include <assimp/Importer.hpp>      // C++ importer
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <ECS/Components/Component.h>
#include <renderer/ShaderClass.h>

#include <iostream>
#include <vector>
#include <string>


struct Vertex{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

class MeshLoader{
    public:

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    MeshLoader(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
    
    void Draw();

    private:
    uint32_t vaoID;
    uint32_t vboID; 
    uint32_t eboID;

    void SetupMesh();
};



#endif