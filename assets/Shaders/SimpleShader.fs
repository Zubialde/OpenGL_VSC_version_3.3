#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec2 uv;

uniform vec3 objectColor;
uniform vec3 ambient;
uniform vec3 lightPos;
uniform vec3 cameraPosition;

void main()
{
    FragColor = vec4(objectColor, 1.0);
}