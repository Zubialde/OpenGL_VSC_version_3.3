#ifndef SHADERCLASS_H
#define SHADERCLASS_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class ShaderClass
{
    public:
        unsigned int ID;

    ShaderClass(const char* vertexPath, const char* fragmentPath);

    void use();
    void setBool(const std::string &name, bool value)const;
    void setInt(const std::string &name, int value)const;
    void setFloat(const std::string &name, float value)const;

    private:
        void checkCompileErrors(unsigned int shader, std::string type);
};
#endif