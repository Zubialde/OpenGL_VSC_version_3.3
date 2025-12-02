#include "EBO.h"

EBO::EBO()
{
    id = 0;
};

void EBO::create()
{
    glGenBuffers(1, &this->id);
}

void EBO::bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}

void EBO::unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::clean()
{
    if(id != 0)
    {
        glDeleteBuffers(1, &id);
        id = 0;  
    }
}

void EBO::update()
{
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Geometry::indices), Geometry::indices, GL_STATIC_DRAW);
}

void EBO::draw()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}