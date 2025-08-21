#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor;
uniform float offsetX;
uniform float offsetY;
out vec3 vertexPos;
out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    gl_Position =projection * view * model * vec4(aPos, 1.0);
    vertexPos = vec3(aPos.x, aPos.y, aPos.z);
    ourColor = aColor;
    TexCoord = aTexCoord;
}