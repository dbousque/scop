#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void	main()
{
	vec4 tmp = projection * view * model * vec4(position, 1.0);
	gl_Position = vec4(tmp.x, tmp.y, -tmp.z, tmp.w);
}