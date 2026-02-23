#version 330 core
out vec4 FragColor;

//Material Related Data
struct Material {
    sampler2D diffuse;
    sampler2D specular;
    sampler2D emission;
    float shininess;
};

//Light Types
struct DirLight{
    vec3 position;
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
uniform DirLight dirLight;

struct PointLight{
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};
#define n_point_lights 3
uniform PointLight pointLight[n_point_lights];

struct SpotLight{
    vec3 position;
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float cutOff;
    float outerCutOff;
};
uniform SpotLight spotLight;

//Uniforms
uniform Material material;

uniform float time;

//Input Vertex Data
in vec3 Normal;
in vec3 cameraPos;
in vec3 fragmentPos;
in vec2 uv;

//Functions
vec3 DirLightCalc(DirLight light, vec3 Normal, vec3 viewDir);
vec3 PointLightCalc(PointLight light, vec3 normal, vec3 viewDir, vec3 fragPos);
vec3 SpotLightCalc(SpotLight light, vec3 normal, vec3 viewDir, vec3 fragPos);

void main()
{
    vec3 viewDir = normalize(cameraPos - fragmentPos);
    vec3 outputer = vec3(0.0);

    outputer += DirLightCalc(dirLight, Normal, viewDir);
    for(int i = 0; i < n_point_lights; i++) outputer += PointLightCalc(pointLight[i], Normal, viewDir, fragmentPos);

    outputer += SpotLightCalc(spotLight, Normal, viewDir, fragmentPos);

    FragColor = vec4 (outputer ,1.0);
}


vec3 DirLightCalc(DirLight light, vec3 normal, vec3 viewDir)
{
    vec3 lightDir = normalize(-light.direction);

    vec3 NDir = normalize(lightDir + cameraPos);
    float diff = max(dot(lightDir, normal), 0.0);

    vec3 halfwayDir = normalize(lightDir + viewDir);
    float NdotH = max(dot(halfwayDir, normal), 0.0);
    float spec = pow(NdotH, material.shininess);

    vec3 ambient =  light.ambient * vec3(texture(material.diffuse, uv));
    vec3 diffuse = diff * light.diffuse * vec3(texture(material.diffuse, uv));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, uv));

    return ambient + diffuse + specular;
}


vec3 PointLightCalc(PointLight light, vec3 normal, vec3 viewDir, vec3 fragPos)
{
    vec3 lightDir = normalize(light.position - fragPos);
    float dist = length(light.position - fragPos);

    float attenuation = 1.0 / (light.constant + light.linear * dist + light.quadratic * pow(dist, 2.0));

    float diff = max(dot(lightDir, normal), 0.0);

    vec3 halfwayDir = normalize(lightDir + viewDir);
    float NdotH = max(dot(halfwayDir, normal), 0.0);
    float spec = pow(NdotH, material.shininess);

    vec3 ambient =  light.ambient * vec3(texture(material.diffuse, uv));
    vec3 diffuse = diff * light.diffuse * vec3(texture(material.diffuse, uv));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, uv));

    vec3 outer = (ambient + diffuse + specular) * attenuation;

    return outer;
}

vec3 SpotLightCalc(SpotLight light, vec3 normal, vec3 viewDir, vec3 fragPos)
{
    vec3 lightDir = normalize(light.position - fragPos);
    float dist = length(light.position - fragPos);

    float theta = dot(normalize(light.direction), normalize(-lightDir));
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff)/epsilon, 0.0, 1.0);

    float diff = max(dot(lightDir, normal), 0.0);

    vec3 halfwayDir = normalize(lightDir + viewDir);
    float NdotH = max(dot(halfwayDir, normal), 0.0);
    float spec = pow(NdotH, material.shininess);

    vec3 ambient =  light.ambient * vec3(texture(material.diffuse, uv));
    vec3 diffuse = diff * light.diffuse * vec3(texture(material.diffuse, uv));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, uv));

    ambient *= intensity;
    diffuse *= intensity;
    specular *= intensity;
    
    vec3 outer = (ambient + diffuse + specular);

    return outer;
}