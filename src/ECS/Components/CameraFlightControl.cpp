#include "ECS/Components/CameraFlightControl.h"

void CameraFlightControl::Update(float deltaTime)
{
    Camera* camera = parent->GetComponent<Camera>();
    if (camera != nullptr) 
    {
        cameraMovement(deltaTime, camera);
        cameraRotation(deltaTime, camera);
    }
}


void CameraFlightControl::cameraMovement(float deltaTime, Camera* camera)
{
    float velocity = camera->info.MovementSpeed * deltaTime;
    glm::vec3 movement(0.0f);

    if (Input::IsKeyPressed(GLFW_KEY_W))
        movement += camera->info.front * velocity;
    if (Input::IsKeyPressed(GLFW_KEY_S))
        movement -= camera->info.front * velocity;
    if (Input::IsKeyPressed(GLFW_KEY_A))
        movement -= camera->info.right * velocity;
    if (Input::IsKeyPressed(GLFW_KEY_D))
        movement += camera->info.right * velocity;
    
    if (Input::IsKeyPressed(GLFW_KEY_E)) 
        movement += camera->info.up * velocity;
    if (Input::IsKeyPressed(GLFW_KEY_Q)) 
        movement -= camera->info.up * velocity;

    parent->transform.info.position += movement;
}

void CameraFlightControl::cameraRotation(float deltaTime, Camera* camera)
{
    if (!Input::IsMouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT))
    {
        firstMouse = true; // reset so there's no snap when re-pressing
        return;
    }

    glm::vec2 mousePos = Input::MousePos();

    if (firstMouse)
    {
        lastX = mousePos.x;
        lastY = mousePos.y;
        firstMouse = false;
        return;
    }

    float xOffset = mousePos.x - lastX;
    float yOffset = lastY - mousePos.y; // inverted Y

    lastX = mousePos.x;
    lastY = mousePos.y;

    camera->ProcessMouseMovement(xOffset, yOffset);
}