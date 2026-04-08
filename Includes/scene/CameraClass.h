#ifndef CAMERACLASS_H
#define CAMERACLASS_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <ECS/Components/Component.h>


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

struct CameraInfo{
    glm::vec3 position;
    glm::vec3 up {glm::vec3(0.0f, 1.0f, 0.0f)};
    glm::vec3 front;
    glm::vec3 right;

    // euler Angles
    float Yaw {YAW};
    float Pitch {PITCH};
    
    // camera options
    float MovementSpeed {SPEED};
    float MouseSensitivity {SENSITIVITY};
    float Zoom {FOV};

    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);
};
class Camera : public Component
{
    public:
    // camera Attributes

    CameraInfo info;

    Camera();

    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ,float yaw, float pitch);
    
    void Start() override;
    void Update(float deltaTime) override;
    void OnDestroy() override;

    // Functions
    glm::mat4 GetViewMatrix();
    glm::mat4 GetProjectionMatrix();
    glm::mat4 CalculateViewMatrix(glm::vec3 position, glm::vec3 target, glm::vec3 up);
    void ProcessKeyboard(Camera_Movement direction, float deltaTime);
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
    void ProcessMouseScroll(float yoffset);

    private:

        void updateCameraVectors();
};
#endif