#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <renderer/ShaderClass.h>

#include <vector>
#include <string>

struct Vertex{
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

struct Texture{
    unsigned int id;
    std::string name;
};

class Mesh{
    public:
        std::vector<Vertex> vertices;
        std::vector<unsigned int> indices;
        std::vector<Texture> textures;

        Mesh(std::vector<Vertex> vertices, std::vector<GLuint> indices, std::vector<Texture> textures);
        void Draw(ShaderClass &shader);

    private:
        unsigned int vao;
        unsigned int vbo;
        unsigned int ebo;

        void setUpMesh();
};
#endif