#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec3 vertexPos;
in vec2 TexCoord;

struct LightColor {
    vec3 ambient;
};

uniform LightColor lightMaterial;

void main()
{
    FragColor = vec4(lightMaterial.ambient,1.0f);
}