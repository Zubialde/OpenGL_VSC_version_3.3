#include "ECS/Components/CameraFlightControl.h"

CameraFlightControl::CameraFlightControl()
{

}

void CameraFlightControl::Start()
{

}

void CameraFlightControl::Update(float deltaTime)
{
    if(Input::IsKeyPressed(W))
    Debugger::Log("W is pressed");
    //processInput(FORWARD, deltaTime);
}

void CameraFlightControl::OnDestroy()
{

}

/*void CameraFlightControl::processInput(Camera_Movement direction, float deltaTime)
{
    float velocity = MovementSpeed * deltaTime;

    if (direction == FORWARD)
        info.position += info.front * velocity;
    if (direction == BACKWARD)
        info.position -= info.front * velocity;
    if (direction == LEFT)
        info.position -= info.right * velocity;
    if (direction == RIGHT)
        info.position += info.right * velocity;
}*/
