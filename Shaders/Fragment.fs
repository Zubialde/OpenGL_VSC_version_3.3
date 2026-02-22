#version 330 core
out vec4 FragColor;

//Material Related Data
struct Material {
    sampler2D diffuse;
    sampler2D specular;
    sampler2D emission;
    float shininess;
};


//Light Related Data
struct Light {
    vec3 position;
    vec3 direction;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;

    float cutOff;
    float outerCutOff;
};

//Uniforms
uniform Light light;
uniform Material material;

uniform float time;

//Input Vertex Data
in vec3 Normal;
in vec3 cameraPos;
in vec3 fragmentPos;
in vec2 uv;

void main()
{
    //Light Related Precomputations
    vec3 cameraDir = normalize(cameraPos - fragmentPos);

    //Directional Light
    vec3 lightDir = normalize(light.position - fragmentPos);

    //Point Light
    float lightDist = length(light.position - fragmentPos);
    float attenuation = 1.0 / (light.constant + light.linear * lightDist + light.quadratic * pow(lightDist, 2.0));

    //Spot Light
    float theta = dot(normalize(light.direction), normalize(-lightDir));
    float epsilon = light.cutOff - light.outerCutOff;
    float intensity = clamp((theta - light.outerCutOff)/epsilon, 0.0, 1.0);

    //Diffuse Light
    float NDir = max(dot(lightDir, Normal), 0.0);
    float diff = NDir;

    //Specular Light
    vec3  halfwayDir = normalize(lightDir + cameraDir);
    float NdotH = max(dot(halfwayDir, Normal), 0.0);
    
    float spec = pow(NdotH, material.shininess);

    vec3 ambient =  light.ambient * vec3(texture(material.diffuse, uv));
    vec3 diffuse = diff * light.diffuse * vec3(texture(material.diffuse, uv));
    vec3 specular = light.specular * spec * vec3(texture(material.specular, uv));

    diffuse *= intensity;
    specular *= intensity;

    float clampValue = clamp(vec3(texture(material.specular, uv)), 0.0, 1.0).r < 0.05? 1.0 : 0.0;
    vec3 emission = vec3(texture(material.emission, uv + vec2(0.0, time))) * clampValue;

    vec3 result = ambient + diffuse + specular; 

    FragColor = vec4 (result ,1.0);
}