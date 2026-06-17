#ifndef INPUT_H
#define INPUT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <utils/Singleton.h>

enum CursorMode
{
    ACTIVE = GLFW_CURSOR_NORMAL,
    HIDDEN = GLFW_CURSOR_HIDDEN,
    DISABLED = GLFW_CURSOR_DISABLED
};

class Input : public Singleton<Input>
{
    friend class Singleton<Input>;

    public:
    static bool GetKey(int key);

    static bool IsKeyPressed(int key);

    static bool IsKeyReleased(int key);

    static glm::vec2 MousePos();

    static void setCursorMode(CursorMode mode);

    static bool IsMouseButtonPressed(int button);


    private:

    Input() = default;
};

#endif