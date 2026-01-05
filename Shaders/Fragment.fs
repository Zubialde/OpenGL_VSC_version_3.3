#version 330 core
out vec4 FragColor;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

uniform Material material;

in vec3 Normal;
in vec3 lpos;
in vec3 baseColor;
in vec3 ambientColor;
in vec3 cameraPos;
in vec3 fragmentPos;
in vec3 LightColor;

float specularStrength = 0.5;

uniform sampler2D ourTexture;
uniform sampler2D ourTexture2;

void main()
{
    //Ambient Light
    vec3 ambient = material.ambient * LightColor;
    vec3 lightDir = normalize(lpos - fragmentPos);
    vec3 cameraDir = normalize(cameraPos - fragmentPos);

    //Diffuse Light
    float NDir = max(dot(lightDir, normalize(Normal)), 0.0);
    vec3 diffuse = NDir * LightColor * material.diffuse;


    //Specular Light
    vec3  halfwayDir = normalize(lightDir + cameraDir);
    float NdotH = max(dot(halfwayDir, Normal), 0.0);
    
    vec3 specular = pow(NdotH, material.shininess) * material.specular;

    vec3 result = ambient + diffuse + specular; 

    FragColor = vec4 (result ,1.0f);
}