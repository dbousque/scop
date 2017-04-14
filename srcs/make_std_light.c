/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_std_light.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:26:44 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 17:26:46 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void	make_std_light_vertices5(GLfloat vertices[], float r, float g,
																	float b)
{
	vertices[70] = g;
	vertices[71] = b;
	vertices[72] = 0.05;
	vertices[73] = -0.05;
	vertices[74] = -0.05;
	vertices[75] = r;
	vertices[76] = g;
	vertices[77] = b;
	vertices[78] = 0.05;
	vertices[79] = 0.05;
	vertices[80] = -0.05;
	vertices[81] = r;
	vertices[82] = g;
	vertices[83] = b;
	vertices[84] = 0.05;
	vertices[85] = -0.05;
	vertices[86] = 0.05;
	vertices[87] = r;
	vertices[88] = g;
	vertices[89] = b;
	vertices[90] = 0.05;
	vertices[91] = 0.05;
	vertices[92] = -0.05;
	vertices[93] = r;
	vertices[94] = g;
}

void	make_std_light_vertices4(GLfloat vertices[], float r, float g,
																	float b)
{
	vertices[48] = 0.05;
	vertices[49] = -0.05;
	vertices[50] = -0.05;
	vertices[51] = r;
	vertices[52] = g;
	vertices[53] = b;
	vertices[54] = -0.05;
	vertices[55] = 0.05;
	vertices[56] = -0.05;
	vertices[57] = r;
	vertices[58] = g;
	vertices[59] = b;
	vertices[60] = 0.05;
	vertices[61] = -0.05;
	vertices[62] = -0.05;
	vertices[63] = r;
	vertices[64] = g;
	vertices[65] = b;
	vertices[66] = 0.05;
	vertices[67] = 0.05;
	vertices[68] = -0.05;
	vertices[69] = r;
}

void	make_std_light_vertices3(GLfloat vertices[], float r, float g,
																	float b)
{
	vertices[25] = -0.05;
	vertices[26] = 0.05;
	vertices[27] = r;
	vertices[28] = g;
	vertices[29] = b;
	vertices[30] = 0.05;
	vertices[31] = 0.05;
	vertices[32] = 0.05;
	vertices[33] = r;
	vertices[34] = g;
	vertices[35] = b;
	vertices[36] = -0.05;
	vertices[37] = -0.05;
	vertices[38] = -0.05;
	vertices[39] = r;
	vertices[40] = g;
	vertices[41] = b;
	vertices[42] = -0.05;
	vertices[43] = 0.05;
	vertices[44] = -0.05;
	vertices[45] = r;
	vertices[46] = g;
	vertices[47] = b;
}

void	make_std_light_vertices2(GLfloat vertices[], float r, float g,
																	float b)
{
	vertices[0] = -0.05;
	vertices[1] = -0.05;
	vertices[2] = 0.05;
	vertices[3] = r;
	vertices[4] = g;
	vertices[5] = b;
	vertices[6] = -0.05;
	vertices[7] = 0.05;
	vertices[8] = 0.05;
	vertices[9] = r;
	vertices[10] = g;
	vertices[11] = b;
	vertices[12] = 0.05;
	vertices[13] = -0.05;
	vertices[14] = 0.05;
	vertices[15] = r;
	vertices[16] = g;
	vertices[17] = b;
	vertices[18] = -0.05;
	vertices[19] = 0.05;
	vertices[20] = 0.05;
	vertices[21] = r;
	vertices[22] = g;
	vertices[23] = b;
	vertices[24] = 0.05;
}

void	make_std_light_vertices(GLfloat vertices[], float r, float g,
																	float b)
{
	make_std_light_vertices2(vertices, r, g, b);
	make_std_light_vertices3(vertices, r, g, b);
	make_std_light_vertices4(vertices, r, g, b);
	make_std_light_vertices5(vertices, r, g, b);
	make_std_light_vertices6(vertices, r, g, b);
	make_std_light_vertices7(vertices, r, g, b);
	make_std_light_vertices8(vertices, r, g, b);
	make_std_light_vertices9(vertices, r, g, b);
	make_std_light_vertices10(vertices, r, g, b);
}
