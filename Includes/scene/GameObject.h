#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <utils/Component.h>

#include <iostream>
#include <vector>

#include <type_traits>

class GameObject{
    public:
    std::string name;

    std::vector<std::unique_ptr<Component>> components;

    GameObject();

    void Instantiate(std::string name);

    //Calls for the Update inside of every component passes the deltaTime
    void Update(float deltaTime);

    // This function is used to add a component to the gameObject
    template<typename T, typename... Args>
    requires std::is_base_of_v<Component, T>
    inline T* AddComponent(Args&&... args)
    {
        std::unique_ptr<T> component = std::make_unique<T>(std::forward<Args>(args)...);
                
        T* newComponent = component.get();
        
        components.push_back(std::move(component));
        
        return newComponent;
    }
    private:
};  

#endif