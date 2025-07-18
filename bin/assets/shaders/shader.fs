#version 460 core
out vec4 FragColor;

layout(location = 3) uniform vec3 uColor;

void main()
{
    FragColor = vec4(uColor, 1.0);
}