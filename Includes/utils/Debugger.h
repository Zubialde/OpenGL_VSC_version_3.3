#ifndef DEBBUGER_H
#define DEBBUGER_H


#include <utils/Singleton.h>

#include <iostream>

class Debugger : public Singleton<Debugger>
{
    friend class Singleton<Debugger>;
    public:

    static void Log(const char* message){
        std::cout << message << std::endl;
    }

    static void Error(const char* message){
        std::cout << "ERROR: " << message << std::endl;
    };

    private:
    Debugger() = default;
    ~Debugger() = default;
};

#endif