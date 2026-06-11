#ifndef APPLICATION_H
#define APPLICATION_H

#include <glad/glad.h>  
#include <GLFW/glfw3.h>
#include <assimp/importer.hpp>      // C++ importer
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <renderer/ShaderClass.h>
#include <core/SceneManager.h>
#include <ECS/Components/CameraClass.h>
#include <core/Window.h>
#include <ECS/Scene.h>
#include <renderer/PreRenderer.h>


#include <iostream>

class Application
{
    public:

    Application() = default;
    ~Application();

    void Init();

    void Run();

    void Exit();

    private:

    GLFWwindow* window;
};

#endif