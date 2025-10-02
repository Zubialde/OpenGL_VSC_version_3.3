#include "VBO.H"

VBO::VBO()
{
    id = 0;   
}

VBO::~VBO()
{
    if(id != 0){
        glDeleteBuffers(1, &id);
        id = 0;
    }
}

void VBO::create()
{
    glGenBuffers(1, &this->id);
}

void VBO::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::update(enum ObjectType type)
{

    glBufferData(GL_ARRAY_BUFFER, sizeof(Geometry::CubeVertices), Geometry::CubeVertices, GL_STATIC_DRAW);
}