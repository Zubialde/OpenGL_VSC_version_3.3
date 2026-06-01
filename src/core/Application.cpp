#include "core/Application.h"

Application::Application() : init()
{
    ResourceManager::GetInstance().searchDirectory(ASSETS_DIR);

    Debugger::GetInstance().Log(ResourceManager::GetInstance().modelPaths["backpack/backpack.obj"].c_str());

    Window window;
    
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

void Application::currentScene(std::shared_ptr<Scene> scene)
{

}