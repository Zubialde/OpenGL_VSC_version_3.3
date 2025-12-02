#pragma region Preprocessor directives
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Shaders/ShaderClass.h>
#include <Camera/CameraClass.h>
#include <Textures/TextureClass.h>
#include <Buffers/VAO.h>
#include <Buffers/VBO.h>
#include <Buffers/EBO.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <Stb_Image/stb_image.h>


#pragma endregion

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void Init();
void MathCheck();
void processInput(GLFWwindow *window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    
float i {0};
float z {45};

glm::vec3 cubePositions[] = {
    glm::vec3( 0.0f,  0.0f,  0.0f), 
    glm::vec3( 2.0f,  5.0f, -15.0f), 
    glm::vec3(-1.5f, -2.2f, -2.5f),  
    glm::vec3(-3.8f, -2.0f, -12.3f),  
    glm::vec3( 2.4f, -0.4f, -3.5f),  
    glm::vec3(-1.7f,  3.0f, -7.5f),  
    glm::vec3( 1.3f, -2.0f, -2.5f),  
    glm::vec3( 1.5f,  2.0f, -2.5f), 
    glm::vec3( 1.5f,  0.2f, -1.5f), 
    glm::vec3(-1.3f,  1.0f, -1.5f)  
};

unsigned int indices[] = {
    0, 1, 3, // first triangle
    1, 2, 3  // second triangle
};

glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

//Camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = 600.0f, lastY = 400.0f;

float deltaTime {0.0};
float lastFrame {0.0};

const unsigned int SCR_WIDTH = 1920;
const unsigned int SCR_HEIGHT = 1080;
        
double mouseX, mouseY;

float yaw {-90.0f};
float pitch {0.0f};
float fov {45.0f};

int main() {
    Init();

    ShaderClass::SetShaderPath(SHADER_DIR);

    //Crea la ventana (ventana != OpenGl)*
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hello Window :)"  , NULL, NULL);

    //Se asegura de que se han iniciado tanto la ventana como GLAD
    if(window == NULL)
    {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    //Comprueba si ha cambiado el tamaño de la pantalla (especifica) y ejecuta la función
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to load Glad" << std::endl;
        return -1;
    }

    ShaderClass ourShader("Vertex.vs", "Fragment.fs");

    #pragma region VBO, VAO, EBO

    //Genera un VBO(Vertex Buffer Objecy), lo bincula al tipo de Buffer GL_ARRAY_BUFFER y le asigna los datos de los vertices
    VBO vbo;
    vbo.create();
    vbo.bind();
    vbo.update(CubeEBO);

    //Genera un VAO(Vertex Array Object), lo vincula y le asigna los atributos de los vertices
    VAO vao;
    vao.create();
    vao.bind();
    vao.update();

    EBO ebo;
    ebo.create();
    ebo.bind();
    ebo.update();

    
    /*    //Genera un EBO(Element Buffer Object), lo bincula con el VBO y le asgina indices.
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/


    #pragma endregion

    #pragma region Textures

    TextureClass texture1(TEXTURE_DIR"/container.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_LINEAR);
    TextureClass texture2(TEXTURE_DIR"/awesomeface.png", GL_REPEAT, GL_REPEAT, GL_LINEAR_MIPMAP_LINEAR, GL_NEAREST);

    //Assign Units
    
    ourShader.use();
    
    ourShader.setInt("ourTexture", 1);
    ourShader.setInt("ourTexture2", 2);
    #pragma endregion
    
    glEnable(GL_DEPTH_TEST);

    #pragma region Render loop 
    while(!glfwWindowShouldClose(window))
    {
        
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        //Comandos de Renderizado 
        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        texture1.use(GL_TEXTURE1);
        texture2.use(GL_TEXTURE2);

        //View Matrix ||Model -> View|| 1. Camera Position, 2. Camera Orientation
        glm::mat4 view = glm::mat4(1.0f);
        view = camera.GetViewMatrix();
        
        ourShader.setMat4("view", view);

        //Perspective Matrix ||View -> Projection|| 1. FOV, 2. Aspect Ratio, 3. Near, 4. Far
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(camera.Zoom), SCR_WIDTH / (float)SCR_HEIGHT , 0.1f, 100.0f);

        ourShader.setMat4("projection", projection);

        ourShader.use();
        
        for (unsigned int i = 0; i < 10; i++)
        {        
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            if(int(i % 3) == 0)  model = glm::rotate(model,  (float)glfwGetTime() * glm::radians(20.0f), glm::vec3(1.0f, 0.3f, 0.5f));
            ourShader.setMat4("model", model);
            ebo.draw();
        }

        //Comprueban eventos y cambian el Back por el Front buffer
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    #pragma endregion

    vbo.~VBO();
    vao.clean();
    
    //Cierra la ventan
    glfwTerminate();
    return 0;
}

void Init()
{
    // Inicia glfw y lo configura mediante WindowHint
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0,0, width, height);
}

#pragma region Input
void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, true);
        
    if(glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)     glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

      float cameraSpeed = 2.5f * deltaTime; // 2.5 unidades por segundo
    
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) cameraSpeed *= 3.0f;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);

    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) glfwSetCursorPosCallback(window, mouse_callback);
    else glfwSetCursorPosCallback(window, NULL);

    glfwSetScrollCallback(window, scroll_callback);

}

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(yoffset);
}    

//Camera Coordinates (Gram-Schimdt)
    /*    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

    glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
    glm::vec3 cameraRight = glm::cross(cameraDirection, up);
    glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);*/