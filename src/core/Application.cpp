#include "core/Application.h"

void Application::Init()
{
    mainWindow.SCR_HEIGHT = 540;
    mainWindow.SCR_WIDTH = 960;
    
    this->window = mainWindow.window;

    ResourceManager::GetInstance().searchDirectory(ASSETS_DIR);

    std::unique_ptr<Scene> newscene = std::make_unique<Scene>("New Scene");

    SceneManager::GetInstance().setCurrentScene(move(newscene));
    SceneManager::GetInstance().GetCurrentScene().Load();    
}


void Application::Run()
{
    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float currentframe = static_cast<float>(glfwGetTime());
        float lastFrame = currentframe;
        float deltaTime = (currentframe - lastFrame);

        std::cout << "deltaTime: " << deltaTime << std::endl;

        //Scene
        Scene& currentScene = SceneManager::GetInstance().GetCurrentScene();
        currentScene.Update(static_cast<float>(glfwGetTime()));

        //Render
        PreRenderer::GetInstance().FetchRenderData(currentScene);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

Application::~Application()
{
    glfwTerminate();
}