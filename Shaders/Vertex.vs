#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 ourColor;
uniform float offsetX;
uniform float offsetY;
out vec3 vertexPos;
out vec2 TexCoord;

void main()
{
    gl_Position = vec4(aPos.x,aPos.y,aPos.z, 1.0);
    vertexPos = vec3(aPos.x, aPos.y, aPos.z);
    ourColor = aColor;
    TexCoord = aTexCoord;
}