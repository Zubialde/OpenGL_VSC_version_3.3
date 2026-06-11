#ifndef RENDERINGSYSTEM_H
#define RENDERINGSYSTEM_H

#include <utils/Singleton.h>
#include <utils/Debugger.h>

#include <ECS/GameObject.h>
#include <core/ResourceManager.h>

#include <ECS/Components/DirectionalLight.h>
#include <ECS/Components/PointLight.h>
#include <ECS/Components/SpotLight.h>
#include <scene/CameraClass.h>

#include <scene/CameraClass.h>

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>

class Scene;

class RenderingSystem : public Singleton<RenderingSystem>
{    


};
#endif