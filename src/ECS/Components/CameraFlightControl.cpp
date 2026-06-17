#include "ECS/Components/CameraFlightControl.h"

void CameraFlightControl::Update(float deltaTime)
{
        // 1. Extract the active Camera component from the same GameObject
    Camera* camera = parent->GetComponent<Camera>();
    if (camera == nullptr) return;

    float velocity = camera->info.MovementSpeed * deltaTime;
    glm::vec3 movement(0.0f);

    // 2. Calculate spatial translation using the Camera's local vectors
    if (Input::IsKeyPressed(GLFW_KEY_W))
        movement += camera->info.front * velocity;
    if (Input::IsKeyPressed(GLFW_KEY_S))
        movement -= camera->info.front * velocity;
    if (Input::IsKeyPressed(GLFW_KEY_A))
        movement -= camera->info.right * velocity;
    if (Input::IsKeyPressed(GLFW_KEY_D))
        movement += camera->info.right * velocity;
    
    // 3. Vertical translation (Local 'up' for spacecraft, Global 'up' for standard drone)
    if (Input::IsKeyPressed(GLFW_KEY_E)) 
        movement += camera->info.up * velocity;
    if (Input::IsKeyPressed(GLFW_KEY_Q)) 
        movement -= camera->info.up * velocity;

    // 4. Apply translation to the Transform, NOT the Camera
    parent->transform.info.position += movement;
}
