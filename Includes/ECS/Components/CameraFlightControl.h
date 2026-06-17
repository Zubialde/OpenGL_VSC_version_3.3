#ifndef CAMERAFLIGHTCONTROL_H
#define CAMERAFLIGHTCONTROL_H

#include <ECS/Components/Component.h>
#include <ECS/Components/CameraClass.h>
#include <utils/Input.h>
#include <ECS/GameObject.h>

#include <glad/glad.h>

enum Camera_Movement{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

/*const float YAW {-90.0f};
const float PITCH {0.0f};
const float FOV {45.0f};
const float SPEED = 25.5f;
const float SENSITIVITY = 0.1f;*/


class CameraFlightControl : public Component
{
    public:

    CameraFlightControl() = default;

    void Start() override{};
    void Update(float deltaTime) override;
    void OnDestroy() override{};

    private:

    void processInput(GLFWwindow* window);

    float Yaw {0};
    float Pitch {0};
    // camera options
    float MovementSpeed {0};
    float MouseSensitivity {0};
    float Zoom {0};
};

#endif