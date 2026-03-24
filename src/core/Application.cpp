#include "core/Application.h"

Application::Application()
{
    Window window;
    

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