#ifndef VAO_H
#define VAO_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


class VAO
{
public:
	VAO();
	~VAO();
	void create();
	void bind();
	void unbind();
	void draw();
	void update();
	void clean();

private:
	GLuint id;
};

#endif // !VAO_H