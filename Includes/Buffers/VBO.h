#ifndef VBO_H
#define VBO_H

#include <glad/glad.h>
#include <iostream>
#include <Buffers/Geometry.h>
#include <GLFW/glfw3.h>

enum ObjectType
{
	Cube,
	Sphere,
	Cylinder,
	triangle,
    Pyramid
};

class VBO
{
    public:
    VBO();
	~VBO();
    void create();
    void bind();
    void unbind();
    void update(enum ObjectType type);

    
    private:

    GLuint id;
};

#endif