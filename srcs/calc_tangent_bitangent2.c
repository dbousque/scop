/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_tangent_bitangent2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:56:14 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 13:56:21 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void	calc_tangent_bitangent_triangle1(GLfloat *vertices, int i,
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
	delta_pos1[0] = vertices[(i + 1) * 17 + 0] - vertices[i * 17 + 0];
	delta_pos1[1] = vertices[(i + 1) * 17 + 1] - vertices[i * 17 + 1];
	delta_pos1[2] = vertices[(i + 1) * 17 + 2] - vertices[i * 17 + 2];
	delta_pos2[0] = vertices[(i + 2) * 17 + 0] - vertices[i * 17 + 0];
	delta_pos2[1] = vertices[(i + 2) * 17 + 1] - vertices[i * 17 + 1];
	delta_pos2[2] = vertices[(i + 2) * 17 + 2] - vertices[i * 17 + 2];
	delta_uv1[0] = vertices[(i + 1) * 17 + 3] - vertices[i * 17 + 3];
	delta_uv1[1] = vertices[(i + 1) * 17 + 4] - vertices[i * 17 + 4];
	delta_uv2[0] = vertices[(i + 2) * 17 + 3] - vertices[i * 17 + 3];
	delta_uv2[1] = vertices[(i + 2) * 17 + 4] - vertices[i * 17 + 4];
}

void	calc_tangent_bitangent_triangle2(GLfloat *vertices, int i, float r,
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
	vertices[(i + 0) * 17 + 11] = delta_pos1[0] * delta_uv2[1];
	vertices[(i + 0) * 17 + 11] -= delta_pos2[0] * delta_uv1[1];
	vertices[(i + 0) * 17 + 11] *= r;
	vertices[(i + 0) * 17 + 12] = delta_pos1[1] * delta_uv2[1];
	vertices[(i + 0) * 17 + 12] -= delta_pos2[1] * delta_uv1[1];
	vertices[(i + 0) * 17 + 12] *= r;
	vertices[(i + 0) * 17 + 13] = delta_pos1[2] * delta_uv2[1];
	vertices[(i + 0) * 17 + 13] -= delta_pos2[2] * delta_uv1[1];
	vertices[(i + 0) * 17 + 13] *= r;
}

void	calc_tangent_bitangent_triangle3(GLfloat *vertices, int i, float r,
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
	vertices[(i + 1) * 17 + 11] = delta_pos1[0] * delta_uv2[1];
	vertices[(i + 1) * 17 + 11] -= delta_pos2[0] * delta_uv1[1];
	vertices[(i + 1) * 17 + 11] *= r;
	vertices[(i + 1) * 17 + 12] = delta_pos1[1] * delta_uv2[1];
	vertices[(i + 1) * 17 + 12] -= delta_pos2[1] * delta_uv1[1];
	vertices[(i + 1) * 17 + 12] *= r;
	vertices[(i + 1) * 17 + 13] = delta_pos1[2] * delta_uv2[1];
	vertices[(i + 1) * 17 + 13] -= delta_pos2[2] * delta_uv1[1];
	vertices[(i + 1) * 17 + 13] *= r;
}

void	calc_tangent_bitangent_triangle4(GLfloat *vertices, int i, float r,
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
	vertices[(i + 2) * 17 + 11] = delta_pos1[0] * delta_uv2[1];
	vertices[(i + 2) * 17 + 11] -= delta_pos2[0] * delta_uv1[1];
	vertices[(i + 2) * 17 + 11] *= r;
	vertices[(i + 2) * 17 + 12] = delta_pos1[1] * delta_uv2[1];
	vertices[(i + 2) * 17 + 12] -= delta_pos2[1] * delta_uv1[1];
	vertices[(i + 2) * 17 + 12] *= r;
	vertices[(i + 2) * 17 + 13] = delta_pos1[2] * delta_uv2[1];
	vertices[(i + 2) * 17 + 13] -= delta_pos2[2] * delta_uv1[1];
	vertices[(i + 2) * 17 + 13] *= r;
}
