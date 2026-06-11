#include "core/Application.h"

void Application::Init()
{
    Window mainWindow(1920, 1080);

    this->window = std::move(mainWindow.window);

    ResourceManager::GetInstance().searchDirectory(ASSETS_DIR);

    std::unique_ptr<Scene> newscene = std::make_unique<Scene>("New Scene");

    SceneManager::GetInstance().setCurrentScene(move(newscene));
    SceneManager::GetInstance().GetCurrentScene().Load();    
}


void Application::Run()
{
    float lastFrame = 0.0f;

    while(!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float currentframe = static_cast<float>(glfwGetTime());
        float deltaTime = currentframe - lastFrame;
        lastFrame = currentframe;
        float frameRate = (deltaTime > 0.0f) ? 1.0f / deltaTime : 0.0f;

        std::cout << "deltaTime: " << deltaTime << " | FrameRate: " << frameRate << " FPS" << std::endl;

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