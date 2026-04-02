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
#include <core/Window.h>
#include <iostream>

#include <core/Initialicer.h>
#include <ECS/Scene.h>


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
    private:
    GLFWwindow* window;
    Scene newscene = Scene("New Scene");
    Initialicer init;
};

#endif