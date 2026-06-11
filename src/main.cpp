#pragma region Preprocessor directives
#include <glad/glad.h>  
#include <GLFW/glfw3.h>
#include <assimp/importer.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <renderer/ShaderClass.h>
#include <ECS/Components/CameraClass.h>
#include <renderer/TextureClass.h>
#include <renderer/Geometry.h>
#include <renderer/Buffers/VBO.h>
#include <renderer/Buffers/VAO.h>
#include <iostream>

#include <Stb_Image/stb_image.h>
#include <core/Application.h>

#pragma endregion

#pragma region Global variables
void Init();
void Timer();
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

//Refocator to a Input class for better management
void processInput(GLFWwindow *window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);


glm::vec3 lightPos = glm::vec3(4.0f, 2.0f,4.0f);

//Camera
float lastX = 600.0f, lastY = 400.0f;

float deltaTime {0.0};
float lastFrame {0.0};

const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;
        
double mouseX, mouseY;

float lanternAngle {12.5f};

glm::vec3 cubePositions[10] = {
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(2.0f, 0.0f, 0.0f),
    glm::vec3(-2.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 2.0f, 0.0f),
    glm::vec3(0.0f, -2.0f, 0.0f),
    glm::vec3(0.0f, 0.0f, 2.0f),
    glm::vec3(0.0f, 0.0f, -2.0f),
    glm::vec3(2.0f, 2.0f, 0.0f),
};

glm::vec3 pointLightPos[4] = {
    glm::vec3(0.0f, 0.0f, 1.0f),
    glm::vec3(2.0f, 0.0f, 2.0f),
    glm::vec3(-2.0f, 0.0f, 2.0f),
    glm::vec3(0.0f, 2.0f, 2.0f)
};

bool firstMouse = true;
// Previous key states to detect single key-press events (edge detection)
bool prevUpPressed = false;
bool prevDownPressed = false;
#pragma endregion

int main() {
    Application app;

    app.Init();

    app.Run();

    return 0;
}

#pragma region CleanUp

void Timer()
{
    float currentFrame = static_cast<float>(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}

void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
    if(glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)     glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Edge-detect UP/DOWN so the angle changes once per key press
    int downState = glfwGetKey(window, GLFW_KEY_DOWN);
    int upState = glfwGetKey(window, GLFW_KEY_UP);

    if (downState == GLFW_PRESS && !prevDownPressed)
        lanternAngle--;
    if (upState == GLFW_PRESS && !prevUpPressed)
        lanternAngle++;

    // update previous-state flags
    prevDownPressed = (downState == GLFW_PRESS);
    prevUpPressed = (upState == GLFW_PRESS);
// 2.5 unidades por segundo
    /*    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) camera.info.MovementSpeed = 10.0f;
    else     camera.info.MovementSpeed = 3.0f;
    
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);*/


    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) glfwSetCursorPosCallback(window, mouse_callback);
    else 
    {
        glfwSetCursorPosCallback(window, NULL);
        firstMouse = true;
    }
    glfwSetScrollCallback(window, scroll_callback);
}

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if(firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
    firstMouse = false;  
    }
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; 

    lastX = xpos;
    lastY = ypos;

    //camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    //camera.ProcessMouseScroll(static_cast<float>(yoffset));
}   
#pragma endregion