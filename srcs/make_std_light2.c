/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_std_light2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:28:13 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 17:28:15 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void	make_std_light_vertices10(GLfloat vertices[], float r, float g,
																	float b)
{
	vertices[194] = 0.05;
	vertices[195] = r;
	vertices[196] = g;
	vertices[197] = b;
	vertices[198] = 0.05;
	vertices[199] = -0.05;
	vertices[200] = -0.05;
	vertices[201] = r;
	vertices[202] = g;
	vertices[203] = b;
	vertices[204] = -0.05;
	vertices[205] = -0.05;
	vertices[206] = 0.05;
	vertices[207] = r;
	vertices[208] = g;
	vertices[209] = b;
	vertices[210] = 0.05;
	vertices[211] = -0.05;
	vertices[212] = 0.05;
	vertices[213] = r;
	vertices[214] = g;
	vertices[215] = b;
}

void	make_std_light_vertices9(GLfloat vertices[], float r, float g,
																	float b)
{
	vertices[169] = 0.05;
	vertices[170] = 0.05;
	vertices[171] = r;
	vertices[172] = g;
	vertices[173] = b;
	vertices[174] = 0.05;
	vertices[175] = 0.05;
	vertices[176] = 0.05;
	vertices[177] = r;
	vertices[178] = g;
	vertices[179] = b;
	vertices[180] = -0.05;
	vertices[181] = -0.05;
	vertices[182] = -0.05;
	vertices[183] = r;
	vertices[184] = g;
	vertices[185] = b;
	vertices[186] = 0.05;
	vertices[187] = -0.05;
	vertices[188] = -0.05;
	vertices[189] = r;
	vertices[190] = g;
	vertices[191] = b;
	vertices[192] = -0.05;
	vertices[193] = -0.05;
}

void	make_std_light_vertices8(GLfloat vertices[], float r, float g,
																	float b)
{
	vertices[144] = -0.05;
	vertices[145] = 0.05;
	vertices[146] = -0.05;
	vertices[147] = r;
	vertices[148] = g;
	vertices[149] = b;
	vertices[150] = 0.05;
	vertices[151] = 0.05;
	vertices[152] = -0.05;
	vertices[153] = r;
	vertices[154] = g;
	vertices[155] = b;
	vertices[156] = -0.05;
	vertices[157] = 0.05;
	vertices[158] = 0.05;
	vertices[159] = r;
	vertices[160] = g;
	vertices[161] = b;
	vertices[162] = 0.05;
	vertices[163] = 0.05;
	vertices[164] = -0.05;
	vertices[165] = r;
	vertices[166] = g;
	vertices[167] = b;
	vertices[168] = -0.05;
}

void	make_std_light_vertices7(GLfloat vertices[], float r, float g,
																	float b)
{
	vertices[120] = -0.05;
	vertices[121] = -0.05;
	vertices[122] = 0.05;
	vertices[123] = r;
	vertices[124] = g;
	vertices[125] = b;
	vertices[126] = -0.05;
	vertices[127] = 0.05;
	vertices[128] = -0.05;
	vertices[129] = r;
	vertices[130] = g;
	vertices[131] = b;
	vertices[132] = -0.05;
	vertices[133] = -0.05;
	vertices[134] = 0.05;
	vertices[135] = r;
	vertices[136] = g;
	vertices[137] = b;
	vertices[138] = -0.05;
	vertices[139] = 0.05;
	vertices[140] = 0.05;
	vertices[141] = r;
	vertices[142] = g;
	vertices[143] = b;
}

void	make_std_light_vertices6(GLfloat vertices[], float r, float g,
																	float b)
{
	vertices[95] = b;
	vertices[96] = 0.05;
	vertices[97] = -0.05;
	vertices[98] = 0.05;
	vertices[99] = r;
	vertices[100] = g;
	vertices[101] = b;
	vertices[102] = 0.05;
	vertices[103] = 0.05;
	vertices[104] = 0.05;
	vertices[105] = r;
	vertices[106] = g;
	vertices[107] = b;
	vertices[108] = -0.05;
	vertices[109] = -0.05;
	vertices[110] = -0.05;
	vertices[111] = r;
	vertices[112] = g;
	vertices[113] = b;
	vertices[114] = -0.05;
	vertices[115] = 0.05;
	vertices[116] = -0.05;
	vertices[117] = r;
	vertices[118] = g;
	vertices[119] = b;
}
