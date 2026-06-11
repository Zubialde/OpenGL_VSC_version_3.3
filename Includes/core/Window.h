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
    int SCR_WIDTH {960};
    int SCR_HEIGHT {540};

    Window();
    GLFWwindow* window;

    private:

    static GLFWwindow* Init(int SCR_WIDTH, int SCR_HEIGHT);
    void Checker(GLFWwindow* window);

    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

};

#endif