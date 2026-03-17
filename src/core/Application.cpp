#include "core/Application.h"

Application::Application()
{
    window = Init(SCR_WIDTH, SCR_HEIGHT);

    if(window == NULL)
    {
        std::cout << "Failed to create window" << std::endl;
        Application::~Application();
        return;
    }
    glfwMakeContextCurrent(window);

}

GLFWwindow* Application::Init(int SCR_WIDTH, int SCR_HEIGHT)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    return glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hola ventana :)"  , NULL, NULL);
}

void Application::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0,0, width, height);
}

Application::~Application()
{
    glfwTerminate();
}

void Application::Run()
{
    while(!glfwWindowShouldClose(window))
    {
        
    }

    Application::~Application();
}