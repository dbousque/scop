/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:58:45 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 13:58:46 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_vec	*new_vec2(float elt1, float elt2)
{
	t_vec	*vec;

	vec = new_vec(2);
	if (!vec)
		return (NULL);
	vec->elts[0] = elt1;
	vec->elts[1] = elt2;
	return (vec);
}

t_vec	*new_vec3(float elt1, float elt2, float elt3)
{
	t_vec	*vec;

	vec = new_vec(3);
	if (!vec)
		return (NULL);
	vec->elts[0] = elt1;
	vec->elts[1] = elt2;
	vec->elts[2] = elt3;
	return (vec);
}

t_vec	*new_vec4(float elt1, float elt2, float elt3, float elt4)
{
	t_vec	*vec;

	vec = new_vec(4);
	if (!vec)
		return (NULL);
	vec->elts[0] = elt1;
	vec->elts[1] = elt2;
	vec->elts[2] = elt3;
	vec->elts[3] = elt4;
	return (vec);
}

t_vec	*vec3_normalize(t_vec *vec)
{
	t_vec	*res;
	float	total;

	total = 0.0;
	total += powf(vec->elts[0], 2.0);
	total += powf(vec->elts[1], 2.0);
	total += powf(vec->elts[2], 2.0);
	total = sqrt(total);
	res = new_vec3(vec->elts[0] / total, vec->elts[1] / total,
														vec->elts[2] / total);
	return (res);
}

float	get_norm(float x, float y, float z)
{
	float	total;

	total = 0.0;
	total += powf(x, 2.0);
	total += powf(y, 2.0);
	total += powf(z, 2.0);
	return (sqrt(total));
}
