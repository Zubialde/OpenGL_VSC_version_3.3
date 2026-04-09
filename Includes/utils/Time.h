#ifndef TIME_H
#define TIME_H

#include <utils/Singleton.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

class Time : Singleton<Time>
{    
    friend class Singleton<Time>;

    public:
    static float deltaTime;
    static float currentTime;
    static double timeAsDouble;

    private:

    Time() = default;

    float lastframe;
    float currentframe;
};

#endif