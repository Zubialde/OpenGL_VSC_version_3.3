#ifndef COMPONENT_H
#define COMPONENT_H

#include <utils/Input.h>
#include <utils/Debugger.h>


#include <memory>
#include <iostream>

class GameObject;

class Component
{
    public:   
    
    //Virtual destructor so the function can be overloaded
    virtual ~Component() = default;

    virtual void Start() = 0;    

    //Holds the actual code to be executed
    virtual void Update(float deltaTime) = 0;

    //Holds the function to be called when the object is destroyed
    virtual void OnDestroy() = 0;

    //Gets the Parent Object from the component
    GameObject* GetParent() {return parent;}

    //Sets the Parennt Object pointer
    void SetParent(GameObject* newparent){parent = newparent;}

    protected:
    
    GameObject* parent = nullptr;

};

#endif 