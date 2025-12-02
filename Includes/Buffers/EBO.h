#ifndef EBO_H
#define EBO_H

#include <glad/glad.h>
#include <iostream>
#include <GLFW/glfw3.h>
#include <Buffers/Geometry.h>

class EBO
{
    public:
    EBO();
    void create();
    void bind();
    void unbind();
    void clean();
    void update();
    void draw();

    private:
    GLuint id;
};



#endif 