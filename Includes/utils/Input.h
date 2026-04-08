#ifndef INPUT_H
#define INPUT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <utils/Singleton.h>

enum Key
{
    W = GLFW_KEY_W,
    A = GLFW_KEY_A,
    S = GLFW_KEY_S,
    D = GLFW_KEY_D,
    SPACE = GLFW_KEY_SPACE,
    LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT     ,
    RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT   ,
    LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL ,
    RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL,
    ESCAPE = GLFW_KEY_ESCAPE,
    ENTER = GLFW_KEY_ENTER,
    TAB = GLFW_KEY_TAB,
    BACKSPACE = GLFW_KEY_BACKSPACE,
    INSERT = GLFW_KEY_INSERT,
    DELETE = GLFW_KEY_DELETE,
    I_RIGHT = GLFW_KEY_RIGHT,                                                
    I_LEFT = GLFW_KEY_LEFT,                                                 
    I_DOWN = GLFW_KEY_DOWN,                                                 
    I_UP = GLFW_KEY_UP,                                                     
    PAGE_UP = GLFW_KEY_PAGE_UP,                                           
    PAGE_DOWN = GLFW_KEY_PAGE_DOWN,                                       
    HOME = GLFW_KEY_HOME,                                                 
    END = GLFW_KEY_END,                                                   
    CAPS_LOCK = GLFW_KEY_CAPS_LOCK,                                       
    SCROLL_LOCK = GLFW_KEY_SCROLL_LOCK,                                   
    NUM_LOCK = GLFW_KEY_NUM_LOCK,                                         
    PRINT_SCREEN = GLFW_KEY_PRINT_SCREEN,                                 
    PAUSE = GLFW_KEY_PAUSE,                                               
    F1 = GLFW_KEY_F1,                                                     
    F2 = GLFW_KEY_F2,                                                     
    F3 = GLFW_KEY_F3,                                                     
    F4 = GLFW_KEY_F4,                                                     
    F5 = GLFW_KEY_F5,                                                     
    F6 = GLFW_KEY_F6,                                                     
    F7 = GLFW_KEY_F7,                                                     
    F8 = GLFW_KEY_F8,                                                     
    F9 = GLFW_KEY_F9,                                                     
    F10 = GLFW_KEY_F10,                                                   
    F11 = GLFW_KEY_F11,                                                   
    F12 = GLFW_KEY_F12,                                                   
    F13 = GLFW_KEY_F13,                                                   
    F14 = GLFW_KEY_F14,                                                   
    F15 = GLFW_KEY_F15,                                                   
    F16 = GLFW_KEY_F16,                                                   
    F17 = GLFW_KEY_F17,                                                   
    F18 = GLFW_KEY_F18,                                                   
    F19 = GLFW_KEY_F19,                                                   
    F20 = GLFW_KEY_F20,                                                   
    F21 = GLFW_KEY_F21,                                                   
    F22 = GLFW_KEY_F22,                                                   
    F23 = GLFW_KEY_F23,                                                   
    F24 = GLFW_KEY_F24,                                                   
    F25 = GLFW_KEY_F25,                                                   
};

enum CursorMode
{
    NORMAL = GLFW_CURSOR_NORMAL,
    HIDDEN = GLFW_CURSOR_HIDDEN,
    DISABLED = GLFW_CURSOR_DISABLED
};



class Input : public Singleton<Input>
{
    friend class Singleton<Input>;

    public:
    static bool GetKey(Key key);

    static bool IsKeyPressed(Key key);

    static bool IsKeyReleased(Key key);

    static glm::vec2 MousePos();

    static void setCursorMode(CursorMode mode);

    private:

    Input() = default;
};

#endif