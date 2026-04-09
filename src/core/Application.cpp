#include "core/Application.h"

Application::Application() : init()
{
    //Window window;
    newscene->Load();
    RenderingSystem::GetInstance().SetScene(newscene);

}

Application::~Application()
{
    glfwTerminate();
}

void Application::Run()
{
    newscene->Update(static_cast<float>(glfwGetTime()));
}