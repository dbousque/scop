#version 330 core

layout(location = 0) out vec3 color;

uniform vec3 lightColor;
uniform float redStrength;
uniform float greenStrength;
uniform float blueStrength;

void	main()
{
	color = lightColor;
}