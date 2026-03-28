#include "ECS/Components/Model.h"
#include "ECS/GameObject.h"

Model::Model() : Component(parent)
{

}


void Model::Start()
{
    if(parent->GetComponent<Transform>() == nullptr)
    {
         std::cout << "Transform component in " + parent->name + " is null" << std::endl;
        return;
    }

    vbo.create();
    vbo.bind();
    vbo.update(Cube);

    vao.create();
    vao.bind();
    vao.update();

    glBindVertexArray(0); 
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glEnable(GL_DEPTH_TEST);
}

void Model::Update(float deltaTime)
{
    ourShader.use();
    vao.bind();

    glm::mat4 view = glm::mat4(1.0f);
    view = camera.GetViewMatrix();
    
    //Perspective Matrix ||View -> Projection|| 1. FOV, 2. Aspect Ratio, 3. Near, 4. Far
    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(camera.Zoom), 1920 / (float)1080 , 0.1f, 100.0f);


    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, parent->GetComponent<Transform>()->position);
    model = glm::rotate(model, parent->GetComponent<Transform>()->rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, parent->GetComponent<Transform>()->rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, parent->GetComponent<Transform>()->rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, parent->GetComponent<Transform>()->scale);

    ourShader.setMat4("projection", projection);
    ourShader.setMat4("view", view);
    ourShader.setMat4("model", model);
    
    ourShader.setVec3("objectColor", glm::vec3(0.7f,0.8f,0.9f));

    vao.draw();
}

void Model::OnDestroy()
{
    
}