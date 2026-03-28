#ifndef MODEL_H
#define MODEL_H

#include <ECS/Components/Component.h>

#include <ECS/Components/Transform.h>

#include <renderer/VBO.h>
#include <renderer/VAO.h>
#include <renderer/EBO.h>
#include <renderer/ShaderClass.h>
#include <scene/CameraClass.h>

class Model : public Component{
  public:

  Model();

  void Start() override;

  void Update(float deltaTime) override;

  void OnDestroy() override;


  private:

  VBO vbo;
  VAO vao;
  EBO ebo;

  ShaderClass ourShader = ShaderClass("SimpleShader.vs", "SimpleShader.fs");

  Camera camera = Camera(glm::vec3(0.0f, 0.0f, 3.0f));
};
#endif