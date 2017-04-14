#version 330 core

in vec2 TextCoords;

out vec4 color;

uniform bool twoText;
uniform sampler2D text1;
uniform sampler2D text2;

void	main()
{
	vec4 tmp1 = texture(text1, TextCoords);
	if (twoText)
	{
		vec4 tmp2 = texture(text2, TextCoords);
		color = vec4(tmp1.r, tmp2.g, (tmp2.r * 0.15 + tmp2.g * 0.15 + tmp2.b * 0.7), 1.0);
		//color = tmp1;
	}
	else
	{
		color = tmp1;
	}
}