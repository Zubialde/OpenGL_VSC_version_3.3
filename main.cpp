#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const unsigned int SCR_WIDTH = 1200;
const unsigned int SCR_HEIGHT = 800;

int main() {
    //Inicia glfw y lo configura mediante WindowHint
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Crea la ventana (ventana != OpenGl)*
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hello Window :)" , NULL, NULL);

    //Se asegura de que se han iniciado tanto la ventana como GLAD
    if(window == NULL)
    {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    //Comprueba si ha cambiado el tamaño de la pantalla (especifica) y ejecuta la función
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to load Glad" << std::endl;
        return -1;
    }

    //Render loop 
    while(!glfwWindowShouldClose(window))
    {
        //Comandos de Renderizado 
                processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        //Comprueban eventos y cambian el Back por el Front buffer
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //Cierra la ventan
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height )
{
    glViewport(0,0, width, height);
}

void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);

    //if(glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) std::cout << "Failed to create window" << std::endl;git 
}