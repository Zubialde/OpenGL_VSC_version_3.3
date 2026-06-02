#include "core/Application.h"

Application::Application() : init()
{
    Debugger::Log("Initializing Application...");

    this->window = mainWindow.window;

    auto newscene = std::make_unique<Scene>("New Scene");

    SceneManager::GetInstance().setCurrentScene(move(newscene));
    SceneManager::GetInstance().GetCurrentScene().Load();
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
        SceneManager::GetInstance().GetCurrentScene().Update(static_cast<float>(glfwGetTime()));


        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}