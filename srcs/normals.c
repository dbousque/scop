/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:12:09 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 18:12:11 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void	calculate_raw_normals(GLfloat *v, int nb_vertices)
{
	int			i;
	t_vec		*v1;
	t_vec		*v2;
	float		*v2e;

	i = 0;
	while (i < nb_vertices)
	{
		v1 = vec3_sub(new_vec3(v[i * 17 + 0], v[i * 17 + 1], v[i * 17 + 2]),
	new_vec3(v[(i + 1) * 17 + 0], v[(i + 1) * 17 + 1], v[(i + 1) * 17 + 2]));
		v2 = vec3_sub(new_vec3(v[i * 17 + 0], v[i * 17 + 1], v[i * 17 + 2]),
	new_vec3(v[(i + 2) * 17 + 0], v[(i + 2) * 17 + 1], v[(i + 2) * 17 + 2]));
		v2e = v2->elts;
		v[i * 17 + 5] = v1->elts[1] * v2e[2] - v1->elts[2] * v2e[1];
		v[i * 17 + 6] = v1->elts[2] * v2e[0] - v1->elts[0] * v2e[2];
		v[i * 17 + 7] = v1->elts[0] * v2e[1] - v1->elts[1] * v2e[0];
		v[(i + 1) * 17 + 5] = v1->elts[1] * v2e[2] - v1->elts[2] * v2e[1];
		v[(i + 1) * 17 + 6] = v1->elts[2] * v2e[0] - v1->elts[0] * v2e[2];
		v[(i + 1) * 17 + 7] = v1->elts[0] * v2e[1] - v1->elts[1] * v2e[0];
		v[(i + 2) * 17 + 5] = v1->elts[1] * v2e[2] - v1->elts[2] * v2e[1];
		v[(i + 2) * 17 + 6] = v1->elts[2] * v2e[0] - v1->elts[0] * v2e[2];
		v[(i + 2) * 17 + 7] = v1->elts[0] * v2e[1] - v1->elts[1] * v2e[0];
		i += 3;
	}
}
