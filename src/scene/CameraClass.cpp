#include "scene/CameraClass.h"
#include "ECS/GameObject.h"

void Camera::Start()
{
    info.position = parent->transform.info.position;
    info.up = glm::vec3(0.0f, 1.0f, 0.0f);
    info.front = glm::vec3(0.0f, 0.0f, -1.0f);
    updateCameraVectors();
}

void Camera::Update(float deltaTime)
{
    info.position = parent->transform.info.position;
    updateCameraVectors();
}

void Camera::OnDestroy()
{

}

Camera::Camera()
{

}

Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
{
    info.position = glm::vec3(posX, posY, posZ);
    info.up = glm::vec3(upX, upY, upZ);
    info.Yaw = yaw;
    info.Pitch = pitch;
    updateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(info.position, info.position + info.front, info.up);
}

glm::mat4 Camera::GetProjectionMatrix()
{
    return glm::perspective(glm::radians(info.Zoom), 1920 / (float)1080 , 0.1f, 100.0f);
}

void Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
    xoffset *= info.MouseSensitivity;
    yoffset *= info.MouseSensitivity;

    info.Yaw += xoffset;
    info.Pitch += yoffset;

    // Make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (info.Pitch > 89.0f)
            info.Pitch = 89.0f;
        if (info.Pitch < -89.0f)
            info.Pitch = -89.0f;
    }

    // Update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}

void Camera::ProcessMouseScroll(float yoffset)
{
    info.Zoom -= yoffset;
    if (info.Zoom < 1.0f)
        info.Zoom = 1.0f;
    if (info.Zoom > 120.0f)
        info.Zoom = 120.0f;
}

void Camera::updateCameraVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(info.Yaw)) * cos(glm::radians(info.Pitch));
    front.y = sin(glm::radians(info.Pitch));
    front.z = sin(glm::radians(info.Yaw)) * cos(glm::radians(info.Pitch));
    info.front = glm::normalize(front);

    info.right = glm::normalize(glm::cross(info.front, info.up));
    info.up = glm::normalize(glm::cross(info.right, info.front));
}
