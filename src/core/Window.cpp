#include "core/Window.h"

Window::Window()
{
    window = Init(SCR_WIDTH, SCR_HEIGHT);

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glfwMakeContextCurrent(window);

    Checker(window);
}

GLFWwindow* Window::Init(int SCR_WIDTH, int SCR_HEIGHT)
{    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    return glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "White Box Engine"  , NULL, NULL);
}

void Window::Checker(GLFWwindow* window)
{
    if(window == NULL)
    {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return;
    }
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to load Glad" << std::endl;
        return;
    }
}

void Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0, width, height);
}