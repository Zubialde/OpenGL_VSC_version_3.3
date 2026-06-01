#include "core/Application.h"

Application::Application() : init()
{
    ResourceManager::GetInstance().searchDirectory(ASSETS_DIR);

    Debugger::GetInstance().Log(ResourceManager::GetInstance().modelPaths["backpack/backpack.obj"].c_str());

    Window  mainWindow;
    this->window = mainWindow.window;

    newscene->Load();
    RenderingSystem::GetInstance().SetScene(newscene);
}

Application::~Application()
{
    glfwTerminate();
}

void Application::Run()
{
    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        

        //Scene
        newscene->Update(static_cast<float>(glfwGetTime()));



        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

void Application::currentScene(std::shared_ptr<Scene> scene)
{

}