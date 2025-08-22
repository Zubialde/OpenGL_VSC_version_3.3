#ifndef TEXTURECLASS_H
#define TEXTURECLASS_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class TextureClass
{
    public:
    unsigned int ID;
    TextureClass(const char* path);
    void usePng();
    void useJpg();
    private:
};








#endif