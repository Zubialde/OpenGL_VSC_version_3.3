#pragma region Preprocessor directives
#include <glad/glad.h>  
#include <GLFW/glfw3.h>
#include <assimp/importer.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <renderer/ShaderClass.h>
#include <ECS/Components/CameraClass.h>
#include <renderer/TextureClass.h>
#include <renderer/Geometry.h>
#include <renderer/Buffers/VBO.h>
#include <renderer/Buffers/VAO.h>
#include <iostream>

#include <Stb_Image/stb_image.h>
#include <core/Application.h>

int main() {
    Application app;

    app.Init();

    return app.Run();
}