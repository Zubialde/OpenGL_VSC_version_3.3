#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>  
#include <GLFW/glfw3.h>

#include <utils/Singleton.h>


#include <iostream>

class Window : public Singleton<Window>
{
    friend class Singleton<Window>;

    public: 
    int SCR_WIDTH {1920};
    int SCR_HEIGHT {1080};

    Window();
    GLFWwindow* window;

    private:

    static GLFWwindow* Init(int SCR_WIDTH, int SCR_HEIGHT);
    void Checker(GLFWwindow* window);

    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

};

#endif