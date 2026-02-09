#version 330 core
// Input vertex data, different for all executions of this shader.
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoord;

uniform float offsetX;
uniform float offsetY;

//Uniforms
uniform vec3 objectColor;
uniform vec3 ambient;
uniform vec3 lightPos;
uniform vec3 cameraPosition;

//Outputs
out vec3 baseColor;
out vec3 ambientColor;
out vec3 fragmentPos;
out vec3 Normal;
out vec3 cameraPos;
out vec2 uv;

//Matrices
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    baseColor = objectColor;
    ambientColor = ambient;
    fragmentPos = vec3(model * vec4(aPos, 1.0));

    Normal = mat3(transpose(inverse(model))) * aNormal;
    cameraPos = cameraPosition;
    uv = aTexCoord;
}