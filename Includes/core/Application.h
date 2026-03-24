#ifndef APPLICATION_H
#define APPLICATION_H

#include <glad/glad.h>  
#include <GLFW/glfw3.h>
#include <assimp/importer.hpp>      // C++ importer
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <renderer/ShaderClass.h>
#include <scene/CameraClass.h>
#include <renderer/TextureClass.h>
#include <renderer/Geometry.h>
#include <scene/Mesh.h>
#include <renderer/VBO.h>
#include <renderer/VAO.h>
#include <core/Window.h>
#include <iostream>

#include <Stb_Image/stb_image.h>

class Application
{
    public:
        Application();
        ~Application();

        void Run();
    private:
    int SCR_WIDTH = 1920;
    int SCR_HEIGHT = 1080;

    #pragma region Global variables

    #pragma endregion
    GLFWwindow* window;    
};

#endif