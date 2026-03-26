#include "core/Application.h"

Application::Application()
{
    //Window window;
    newscene.Load();

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
        newscene.Update(1.0f);

    Application::~Application();
}