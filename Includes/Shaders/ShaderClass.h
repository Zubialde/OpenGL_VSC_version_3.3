//Salvaguarda para evitar redefiniciones
#ifndef SHADERCLASS_H
#define SHADERCLASS_H

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>

class ShaderClass
{
    public:
        static std::string ShadersPath;
        unsigned int ID;

    ShaderClass(const char* vertexPath, const char* fragmentPath);

    void use();
    void setBool(const std::string &name, bool value)const;
    void setInt(const std::string &name, int value)const;
    void setFloat(const std::string &name, float value)const;
    void setMat4(const std::string &name ,glm::mat4 matrix)const;

    static void SetShaderPath(const std::string& path);

    private:
        void checkCompileErrors(unsigned int shader, std::string type);
};
#endif