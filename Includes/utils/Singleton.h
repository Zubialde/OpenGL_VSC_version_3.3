#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <memory>

template <typename T>
class Singleton
{
    public:
    
    /// @brief GetInstance returns the only instance of the class
    static T& GetInstance()
    {
        static T instance;
        return instance;
    }

    // Prevent copying or moving
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    protected:
    Singleton() = default;
};

#endif