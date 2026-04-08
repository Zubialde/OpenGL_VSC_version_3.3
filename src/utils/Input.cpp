#include "utils/Input.h"

bool Input::IsKeyPressed(Key key)
{
    return glfwGetKey(glfwGetCurrentContext(), key) == GLFW_PRESS;
}

bool Input::IsKeyReleased(Key key)
{
    return glfwGetKey(glfwGetCurrentContext(), key) == GLFW_RELEASE;
}

glm::vec2 Input::MousePos()
{
    double xpos, ypos;
    glfwGetCursorPos(glfwGetCurrentContext(), &xpos, &ypos);
    return glm::vec2(static_cast<float>(xpos), static_cast<float>(ypos));
}

void Input::setCursorMode(CursorMode mode)
{
    glfwSetInputMode(glfwGetCurrentContext(), GLFW_CURSOR, mode);
}

static void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    static float lastX = 600.0f, lastY = 400.0f;

    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    static bool firstMouse = true;

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
}