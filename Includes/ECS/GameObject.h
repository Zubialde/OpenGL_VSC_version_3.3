#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include <ECS/Components/Component.h>
#include <ECS/Components/Transform.h>

#include <glm/glm.hpp>

#include <iostream>
#include <vector>

#include <type_traits>
#include <memory>
#include <array>

constexpr std::size_t MAX_COMPONENTS = 100;

class GameObject{
    public:
    std::string name;

    Transform transform;

    std::array<std::unique_ptr<Component>, MAX_COMPONENTS> components;
    
    static int n_Components;
    
    GameObject(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f) , glm::vec3 scale = glm::vec3(1.0f), glm::vec3 rotation = glm::vec3(0.0f)) 
    : transform(position, scale, rotation){};

    //Calls for the Update inside of every component passes the deltaTime
    void Update(float deltaTime);

    // This function is used to add a component to the gameObject
    template<typename T, typename... Args>
    requires std::is_base_of_v<Component, T>
    inline T* AddComponent(Args&&... args)
    {

        if(components[GetID<T>()] != nullptr)
            return nullptr;

        std::unique_ptr<T> component = std::make_unique<T>(std::forward<Args>(args)...);
        
        //Makes sure the component has a reference to the gameObject.
        //IMPORTANT: Since the parent is a nullptr by default if you access it before the start, the game will crash
        component->SetParent(this);

        component->Start();

        T* newComponent = component.get();

        components[GetID<T>()] = std::move(component);
        
        return newComponent;
    }

    template<typename T>
    requires std::is_base_of_v<Component, T>
    inline T* GetComponent()
    {
        if(components[GetID<T>()] != nullptr)
            return static_cast<T*>(components[GetID<T>()].get());
        else            
            return nullptr;            
    }

    private:

    template<typename T>
    requires std::is_base_of_v<Component, T>
    inline int GetID()
    {
        static const int typeId = n_Components++;
        return typeId;
    }

};  

#endif