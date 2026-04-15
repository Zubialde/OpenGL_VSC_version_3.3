#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <memory>

/// @brief When we use the calss we define it has friend class Singleton<T> so we can access the private constructor
/// @tparam T Every class that inherits from Singleton must have a template parameter that is the class type
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