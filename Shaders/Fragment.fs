#version 330 core
out vec4 FragColor;

struct Material {
    sampler2D diffuse;
    sampler2D specular;
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
in vec3 cameraPos;
in vec3 fragmentPos;
in vec2 uv;

void main()
{
    //Ambient Light
    vec3 lightDir = normalize(light.position - fragmentPos);
    vec3 cameraDir = normalize(cameraPos - fragmentPos);

    //Diffuse Light
    float NDir = max(dot(lightDir, normalize(Normal)), 0.0);
    float diff = NDir;

    //Specular Light
    vec3  halfwayDir = normalize(lightDir + cameraDir);
    float NdotH = max(dot(halfwayDir, Normal), 0.0);
    
    float spec = pow(NdotH, material.shininess);

    vec3 ambient =  light.ambient * vec3(texture(material.diffuse, uv));
    vec3 diffuse = diff * light.diffuse * vec3(texture(material.diffuse, uv));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, uv));
   
    vec3 result = ambient + diffuse + specular; 

    FragColor = vec4 (result ,1.0);
}