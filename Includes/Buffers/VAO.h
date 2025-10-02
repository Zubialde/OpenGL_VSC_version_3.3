#ifndef VAO_H
#define VAO_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

    

enum ObjectType
{
	Cube,
	Sphere,
	Cylinder,
	triangle
};


class VAO
{
public:
	VAO();
	~VAO();
	void create();
	void bind();
	void unbind();
	void draw();
	void update( ObjectType type);
	void clean();

private:
	GLuint id;
};

#endif // !VAO_H