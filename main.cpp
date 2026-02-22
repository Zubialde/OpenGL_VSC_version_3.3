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

#pragma region Global variables
void Init();
void Timer();
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    
float i {0};
float z {45};

glm::vec3 lightPos = glm::vec3(4.0f, 2.0f,4.0f);

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

glm::vec3 cubePositions[10] = {
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(2.0f, 0.0f, 0.0f),
    glm::vec3(-2.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 2.0f, 0.0f),
    glm::vec3(0.0f, -2.0f, 0.0f),
    glm::vec3(0.0f, 0.0f, 2.0f),
    glm::vec3(0.0f, 0.0f, -2.0f),
    glm::vec3(2.0f, 2.0f, 0.0f),
};

bool firstMouse = true;
#pragma endregion

int main() {
    Init();

    ShaderClass::SetShaderPath(SHADER_DIR);

    //Crea la ventana (ventana != OpenGl)*
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Hola ventana :)"  , NULL, NULL);

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
    ShaderClass lightingShader("LightCubeVertex.vs", "LightCubeFragment.fs");

    #pragma region VBO, VAO, EBO //TODO: Create Mesh class to handle Binding and Updating

    //Genera un VBO(Vertex Buffer Objecy), lo bincula al tipo de Buffer GL_ARRAY_BUFFER y le asigna los datos de los vertices
    VBO vbo;
    vbo.create();
    vbo.bind();
    vbo.update(Cube);

    //Genera un VAO(Vertex Array Object), lo vincula y le asigna los atributos de los vertices
    VAO vao;
    vao.create();
    vao.bind();
    vao.update();     

    VAO lightCubeVao;
    lightCubeVao.create();
    lightCubeVao.bind();
    lightCubeVao.update();

    glBindVertexArray(0); 
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    #pragma endregion
    float ambientpower = 0.5f;

    //Load Textures
    TextureClass diffuse_Map(TEXTURE_DIR"/container2.png", GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR);
    TextureClass specular_Map(TEXTURE_DIR"/container2_specular.png", GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR_MIPMAP_LINEAR);
    TextureClass emmision_Map(TEXTURE_DIR"/Emission_Matrix.jpg", GL_REPEAT, GL_REPEAT, GL_LINEAR, GL_LINEAR);

    ourShader.use();
    ourShader.setInt("material.diffuse", 0);
    ourShader.setInt("material.specular", 1);
    ourShader.setInt("material.emission", 2);
    glEnable(GL_DEPTH_TEST);

    #pragma region Render loop 
    while(!glfwWindowShouldClose(window))
    {
        //Perframe variables
        Timer();
        float currentTime = glfwGetTime();

        //std::cout << 1/deltaTime << std::endl;

        glm::vec3 lightPos2 = lightPos  /*+ (glm::vec3(sin(currentFrame),sin(-currentFrame),cos(-currentFrame)) * 0.5f) * 5.0f*/;

        glm::vec3 lightColor;
        lightColor.x = static_cast<float>(sin(glfwGetTime() * 2.0f));
        lightColor.y = static_cast<float>(sin(glfwGetTime() * 0.7f));
        lightColor.z = static_cast<float>(sin(glfwGetTime() * 1.3f));

        glm::vec3 diffuse =  glm::vec3(0.5f);
        glm::vec3 ambient =  glm::vec3(0.1f);

        glm::vec3 lightDir = glm::normalize(glm::vec3(-0.2f, -1.0f, -0.3f));

        //RenderComands 
        processInput(window);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        //Camera and World Matrixes
        //View Matrix ||Model -> View|| 1. Camera Position, 2. Camera Orientation
        glm::mat4 view = glm::mat4(1.0f);
        view = camera.GetViewMatrix();
        
        //Perspective Matrix ||View -> Projection|| 1. FOV, 2. Aspect Ratio, 3. Near, 4. Far
        glm::mat4 projection = glm::mat4(1.0f);
        projection = glm::perspective(glm::radians(camera.Zoom), SCR_WIDTH / (float)SCR_HEIGHT , 0.1f, 100.0f);

        ourShader.use();
        
        //Light affected objects
        ourShader.setMat4("projection", projection);
        ourShader.setMat4("view", view);

        for(unsigned int i = 0; i < 10; i++)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cubePositions[i]);
            //model = glm::rotate(model, static_cast<float>(glfwGetTime()), glm::vec3(0.0f, 1.0f, 1.0f));
            ourShader.setFloat("time", currentTime);

            ourShader.setMat4("model", model);               
            ourShader.setVec3("cameraPosition", camera.Position);     
            
            ourShader.setVec3("objectColor", glm::vec3(0.8f,0.8f,0.8f));
            ourShader.setFloat("material.shininess", 64.0f);

            ourShader.setVec3("light.direction", camera.Front);
            ourShader.setVec3("light.position", camera.Position);
            ourShader.setVec3("light.ambient", ambient);
            ourShader.setVec3("light.diffuse", diffuse);
            ourShader.setVec3("light.specular", diffuse);

            ourShader.setFloat("light.constant", 1.0f);
            ourShader.setFloat("light.linear", 0.12f);
            ourShader.setFloat("light.quadratic", 0.032f);

            ourShader.setFloat("light.cutOff", glm::cos(glm::radians(12.5f)));
            ourShader.setFloat("light.outerCutOff", glm::cos(glm::radians(17.5f)));

            diffuse_Map.use(GL_TEXTURE0);
            specular_Map.use(GL_TEXTURE1);
            emmision_Map.use(GL_TEXTURE2);

            vao.draw();
        }

        //Lighting Object
        lightingShader.use();
        lightingShader.setMat4("view", view);
        lightingShader.setMat4("projection", projection);
        lightingShader.setVec3("lightMaterial.ambient", lightColor);
        glm::mat4 lightModel = glm::mat4(1.0f);
        lightModel = glm::translate(lightModel, lightPos2);
        lightModel = glm::rotate(lightModel, 360.0f, lightDir);
        lightModel = glm::scale(lightModel, glm::vec3(0.2f));
        lightingShader.setMat4("model", lightModel);
        lightCubeVao.bind();
        vao.draw();

        //Comprueban eventos y cambian el Back por el Front buffer
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    #pragma endregion

    vbo.clear();
    vao.clean();
    
    //Cierra la ventan
    glfwTerminate();
    return 0;
}

void Timer()
{
    float currentFrame = static_cast<float>(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
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
      
    
    float cameraSpeed = 1.25f * deltaTime;         


// 2.5 unidades por segundo
    
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) camera.MovementSpeed = 10.0f;
    else     camera.MovementSpeed = 3.0f;
    
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.ProcessKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.ProcessKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.ProcessKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.ProcessKeyboard(RIGHT, deltaTime);

    if(glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) glfwSetCursorPosCallback(window, mouse_callback);
    else 
    {
        glfwSetCursorPosCallback(window, NULL);
        firstMouse = true;
    }
    glfwSetScrollCallback(window, scroll_callback);

}

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
    float xpos = static_cast<float>(xposIn);
    float ypos = static_cast<float>(yposIn);

    if(firstMouse)
    {
        lastX = xpos;
        lastY = ypos;
    firstMouse = false;  
    }
    float xoffset = xpos - lastX;
    float yoffset = lastY - ypos; 

    lastX = xpos;
    lastY = ypos;

    camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    camera.ProcessMouseScroll(static_cast<float>(yoffset));
}   