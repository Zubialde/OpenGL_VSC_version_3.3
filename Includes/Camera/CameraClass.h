#ifndef CAMERACLASS_H
#define CAMERACLASS_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum Camera_Movement{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

const float YAW {-90.0f};
const float PITCH {0.0f};
const float FOV {45.0f};
const float SPEED = 25.5f;
const float SENSITIVITY = 0.1f;

class Camera
{
    public:
    // camera Attributes
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;

    // euler Angles
    float Yaw {YAW};
    float Pitch {PITCH};
    
    // camera options
    float MovementSpeed {SPEED};
    float MouseSensitivity {SENSITIVITY};
    float Zoom {FOV};

    Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),float yaw = YAW,float pitch = PITCH);

    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ,float yaw, float pitch);

    // Functions
    glm::mat4 GetViewMatrix();
    glm::mat4 CalculateViewMatrix(glm::vec3 position, glm::vec3 target, glm::vec3 up);
    void ProcessKeyboard(Camera_Movement direction, float deltaTime);
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
    void ProcessMouseScroll(float yoffset);

    private:

        void updateCameraVectors();
};
#endif