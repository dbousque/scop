/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_tangent_bitangent.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:56:01 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 13:56:06 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void	calc_tangent_bitangent_triangle5(GLfloat *vertices, int i, float r,
															float *deltas[4])
{
	float	*delta_pos1;
	float	*delta_pos2;
	float	*delta_uv1;
	float	*delta_uv2;

	delta_pos1 = deltas[0];
	delta_pos2 = deltas[1];
	delta_uv1 = deltas[2];
	delta_uv2 = deltas[3];
	vertices[(i + 0) * 17 + 14] = delta_pos2[0] * delta_uv1[0];
	vertices[(i + 0) * 17 + 14] -= delta_pos1[0] * delta_uv2[0];
	vertices[(i + 0) * 17 + 14] *= r;
	vertices[(i + 0) * 17 + 15] = delta_pos2[1] * delta_uv1[0];
	vertices[(i + 0) * 17 + 15] -= delta_pos1[1] * delta_uv2[0];
	vertices[(i + 0) * 17 + 15] *= r;
	vertices[(i + 0) * 17 + 16] = delta_pos2[2] * delta_uv1[0];
	vertices[(i + 0) * 17 + 16] -= delta_pos1[2] * delta_uv2[0];
	vertices[(i + 0) * 17 + 16] *= r;
}

void	calc_tangent_bitangent_triangle6(GLfloat *vertices, int i, float r,
															float *deltas[4])
{
	float	*delta_pos1;
	float	*delta_pos2;
	float	*delta_uv1;
	float	*delta_uv2;

	delta_pos1 = deltas[0];
	delta_pos2 = deltas[1];
	delta_uv1 = deltas[2];
	delta_uv2 = deltas[3];
	vertices[(i + 1) * 17 + 14] = delta_pos2[0] * delta_uv1[0];
	vertices[(i + 1) * 17 + 14] -= delta_pos1[0] * delta_uv2[0];
	vertices[(i + 1) * 17 + 14] *= r;
	vertices[(i + 1) * 17 + 15] = delta_pos2[1] * delta_uv1[0];
	vertices[(i + 1) * 17 + 15] -= delta_pos1[1] * delta_uv2[0];
	vertices[(i + 1) * 17 + 15] *= r;
	vertices[(i + 1) * 17 + 16] = delta_pos2[2] * delta_uv1[0];
	vertices[(i + 1) * 17 + 16] -= delta_pos1[2] * delta_uv2[0];
	vertices[(i + 1) * 17 + 16] *= r;
}

void	calc_tangent_bitangent_triangle7(GLfloat *vertices, int i, float r,
															float *deltas[4])
{
	float	*delta_pos1;
	float	*delta_pos2;
	float	*delta_uv1;
	float	*delta_uv2;

	delta_pos1 = deltas[0];
	delta_pos2 = deltas[1];
	delta_uv1 = deltas[2];
	delta_uv2 = deltas[3];
	vertices[(i + 2) * 17 + 14] = delta_pos2[0] * delta_uv1[0];
	vertices[(i + 2) * 17 + 14] -= delta_pos1[0] * delta_uv2[0];
	vertices[(i + 2) * 17 + 14] *= r;
	vertices[(i + 2) * 17 + 15] = delta_pos2[1] * delta_uv1[0];
	vertices[(i + 2) * 17 + 15] -= delta_pos1[1] * delta_uv2[0];
	vertices[(i + 2) * 17 + 15] *= r;
	vertices[(i + 2) * 17 + 16] = delta_pos2[2] * delta_uv1[0];
	vertices[(i + 2) * 17 + 16] -= delta_pos1[2] * delta_uv2[0];
	vertices[(i + 2) * 17 + 16] *= r;
}

void	calc_tangent_bitangent_triangle(GLfloat *vertices, int i, float r)
{
	float	delta_pos1[3];
	float	delta_pos2[3];
	float	delta_uv1[2];
	float	delta_uv2[2];
	float	*deltas[4];

	deltas[0] = delta_pos1;
	deltas[1] = delta_pos2;
	deltas[2] = delta_uv1;
	deltas[3] = delta_uv2;
	calc_tangent_bitangent_triangle1(vertices, i, deltas);
	r = 1.0 / (delta_uv1[0] * delta_uv2[1] - delta_uv1[1] * delta_uv2[0]);
	calc_tangent_bitangent_triangle2(vertices, i, r, deltas);
	calc_tangent_bitangent_triangle3(vertices, i, r, deltas);
	calc_tangent_bitangent_triangle4(vertices, i, r, deltas);
	calc_tangent_bitangent_triangle5(vertices, i, r, deltas);
	calc_tangent_bitangent_triangle6(vertices, i, r, deltas);
	calc_tangent_bitangent_triangle7(vertices, i, r, deltas);
}

void	calc_tangent_bitangent(GLfloat *vertices, int nb_vertices)
{
	int		i;

	i = 0;
	while (i < nb_vertices)
	{
		calc_tangent_bitangent_triangle(vertices, i, 0.0);
		i += 3;
	}
}
