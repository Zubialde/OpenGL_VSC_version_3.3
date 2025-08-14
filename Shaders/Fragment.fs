#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec3 vertexPos;
in vec2 TexCoord;

uniform sampler2D ourTexture;
uniform sampler2D ourTexture2;
uniform float alphaTexture;
void main()
{
    FragColor = mix(texture(ourTexture, TexCoord), texture(ourTexture2, vec2 (1.0 - TexCoord.x, TexCoord.y)), 0.1 * alphaTexture);
}