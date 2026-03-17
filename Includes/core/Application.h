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
#include <iostream>

#include <Stb_Image/stb_image.h>

class Application
{
    public:    
        
        int SCR_WIDTH;
        int SCR_HEIGHT;

        Application();
        ~Application();

        void Run();

        std::unique_ptr<Camera> camera;
    private:
    
    #pragma region Global variables
    GLFWwindow* window;

    #pragma endregion

    GLFWwindow* Init(int SCR_WIDTH, int SCR_HEIGHT);
    void framebuffer_size_callback(GLFWwindow *window, int width, int height);
    
};

#endif