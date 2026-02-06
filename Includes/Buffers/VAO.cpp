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
    glBindVertexArray(id);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void VAO::update()
{
    //Posicion de los vertices
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    //Normal Position
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //UV
    
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
}

void VAO::clean()
{
    if(id != 0){
        glDeleteVertexArrays(1, &id);
        id = 0;
    }
}