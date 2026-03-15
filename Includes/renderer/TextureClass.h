#ifndef TEXTURECLASS_H
#define TEXTURECLASS_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glad/glad.h>
#include <Stb_Image/stb_image.h>

class TextureClass
{
    public:
    unsigned int ID;
    TextureClass(const char* path ,GLint wrapS, GLint wrapT, GLint minFilter, GLint magFilter);
    void use(GLenum textureUnit);
    private:
};
#endif