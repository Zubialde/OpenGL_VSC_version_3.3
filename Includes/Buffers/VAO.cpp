#include "VAO.h"


VAO::VAO()
{
	id = 0;
}

VAO::~VAO()
{
	clean();
}

void VAO::create()
{
    glGenVertexArrays(1, &this->id);
}

void VAO::bind()
{
	glBindVertexArray(id);
}

void VAO::unbind()
{
	glBindVertexArray(0);
}

void VAO::draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void VAO::update( ObjectType type)
{
    switch (type)
    {
    case Cube:
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        break;
    case Sphere:
        std::cout << "Sphere not implemented yet" << std::endl;
        break;
    default:
        break;
    }
}

void VAO::clean()
{
    if(id != 0){
        glDeleteVertexArrays(1, &id);
        id = 0;
    }
}