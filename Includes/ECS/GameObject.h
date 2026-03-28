#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <ECS/Components/Component.h>

#include <iostream>
#include <vector>

#include <type_traits>

class GameObject{
    public:
    std::string name;

    std::vector<std::unique_ptr<Component>> components;
    
    GameObject();

    //Calls for the Update inside of every component passes the deltaTime
    void Update(float deltaTime);

    // This function is used to add a component to the gameObject
    template<typename T, typename... Args>
    requires std::is_base_of_v<Component, T>
    inline T* AddComponent(Args&&... args)
    {
        for (const std::unique_ptr<Component>& i : components)
        {
            if (typeid(T) == typeid(*i))
            {
                std::cout << "Component " << typeid(T).name() << " already exists in the gameObject" << std::endl;
                return nullptr;
            }
        }
        
        std::unique_ptr<T> component = std::make_unique<T>(std::forward<Args>(args)...);
        
        //Makes sure the component has a reference to the gameObject
        component->SetParent(this);

        component->Start();

        T* newComponent = component.get();
        
        components.push_back(std::move(component));
        
        return newComponent;
    }

    template<typename T>
    requires std::is_base_of_v<Component, T>
    inline T* GetComponent()
    {
        for(const std::unique_ptr<Component>& i : components)
        {
            if(typeid(T) == typeid(*i))
            {
                return static_cast<T*>(i.get());
            }
        }
        // If the component is not found, return nullptr
        //std::cout << "Component "  typeid(T).name() " not found" << std::endl;
        return nullptr;
    }
    private:
};  

#endif