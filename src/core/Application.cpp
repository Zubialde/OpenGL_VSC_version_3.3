#include "core/Application.h"

Application::Application()
{
    this->window = mainWindow.window;

    ResourceManager::GetInstance().searchDirectory(ASSETS_DIR);

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
        Scene& currentScene = SceneManager::GetInstance().GetCurrentScene();
        currentScene.Update(static_cast<float>(glfwGetTime()));

        //Render
        PreRenderer::GetInstance().FetchRenderData(currentScene);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}