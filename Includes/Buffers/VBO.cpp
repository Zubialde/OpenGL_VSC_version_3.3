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

void VBO::update(ObjectType type)
{
    switch(type)
    {
        case Cube:
            glBufferData(GL_ARRAY_BUFFER, Geometry::CubeVertexCount * sizeof(float), Geometry::CubeVertices, GL_STATIC_DRAW);
            break;
        case Sphere:
            glBufferData(GL_ARRAY_BUFFER, Geometry::SphereVertexCount * sizeof(float), Geometry::SphereVertices, GL_STATIC_DRAW);
            break;
        case Pyramid:
            glBufferData(GL_ARRAY_BUFFER, Geometry::PyramidVertexCount * sizeof(float), Geometry::PyramidVertices, GL_STATIC_DRAW);
            break;
        case CubeEBO:
            glBufferData(GL_ARRAY_BUFFER, Geometry::CubeVertexEBOCount * sizeof(float), Geometry::vertices, GL_STATIC_DRAW);
            break;
    }   
}

void VBO::clean()
{
    if(id != 0)
    {
        glDeleteBuffers(1, &id);
        id = 0;
    }
}