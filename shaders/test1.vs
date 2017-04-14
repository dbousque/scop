#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 textCoords;
layout (location = 2) in vec3 normalVec;
layout (location = 3) in vec3 faceColor;
layout (location = 4) in vec3 faceTangent;
layout (location = 5) in vec3 faceBitangent;

out vec2 TextCoords;
out vec3 NormalVec;
out vec3 FragPos;
out vec3 Position;
out vec3 FaceTangent;
out vec3 FaceColor;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat4 transpInv;

void main()
{
	vec4 tmp = projection * view * model * vec4(position, 1.0);
	vec4 tmp2 = model * vec4(position, 1.0);
	gl_Position = vec4(tmp.x, tmp.y, -tmp.z, tmp.w);
	FragPos = vec3(tmp2.x, tmp2.y, tmp2.z);
	Position = position;
	TextCoords = vec2(textCoords.x, 1.0 - textCoords.y);
	vec3 tmp3 = mat3(transpInv) * normalVec;
	NormalVec = vec3(tmp3.x, tmp3.y, tmp3.z);
	FaceTangent = (projection * model * vec4(faceTangent, 0.0)).xyz;
	FaceColor = faceColor;
}
