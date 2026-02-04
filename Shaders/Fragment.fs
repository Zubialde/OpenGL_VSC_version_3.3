#version 330 core
out vec4 FragColor;

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

uniform Material material;

struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Light light;


in vec3 Normal;
in vec3 lpos;
in vec3 baseColor;
in vec3 ambientColor;
in vec3 cameraPos;
in vec3 fragmentPos;

float specularStrength = 0.5;

uniform sampler2D ourTexture;
uniform sampler2D ourTexture2;

void main()
{
    //Ambient Light
    vec3 amb = material.ambient;
    vec3 lightDir = normalize(light.position - fragmentPos);
    vec3 cameraDir = normalize(cameraPos - fragmentPos);

    //Diffuse Light
    float NDir = max(dot(lightDir, normalize(Normal)), 0.0);
    vec3 diff = NDir * material.diffuse;

    //Specular Light
    vec3  halfwayDir = normalize(lightDir + cameraDir);
    float NdotH = max(dot(halfwayDir, Normal), 0.0);
    
    vec3 spec = pow(NdotH, material.shininess) * material.specular;

    vec3 diffuse = diff * light.diffuse;
    vec3 ambient = amb * light.ambient;
    vec3 specular = spec * light.specular;
   
    vec3 result = ambient + diffuse + specular; 

    FragColor = vec4 (result ,1.0);
}