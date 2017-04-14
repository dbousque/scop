/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:59:07 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 13:59:09 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_mat	*make_rot_x(float rad)
{
	t_mat	*res;
	float	cosv;
	float	sinv;

	res = new_mat4();
	cosv = cosf(rad);
	sinv = sinf(rad);
	res->elts[5] = cosv;
	res->elts[6] = -sinv;
	res->elts[9] = sinv;
	res->elts[10] = cosv;
	return (res);
}

t_mat	*make_rot_y(float rad)
{
	t_mat	*res;
	float	cosv;
	float	sinv;

	res = new_mat4();
	cosv = cosf(rad);
	sinv = sinf(rad);
	res->elts[0] = cosv;
	res->elts[2] = sinv;
	res->elts[8] = -sinv;
	res->elts[10] = cosv;
	return (res);
}

t_mat	*make_rot_z(float rad)
{
	t_mat	*res;
	float	cosv;
	float	sinv;

	res = new_mat4();
	cosv = cosf(rad);
	sinv = sinf(rad);
	res->elts[0] = cosv;
	res->elts[1] = -sinv;
	res->elts[4] = sinv;
	res->elts[5] = cosv;
	return (res);
}

t_mat	*rotate(t_vec *vec)
{
	t_mat	*ret;
	t_mat	*rot_x;
	t_mat	*rot_y;
	t_mat	*rot_z;

	rot_x = make_rot_x(vec->elts[1]);
	rot_y = make_rot_y(vec->elts[2]);
	rot_z = make_rot_z(vec->elts[0]);
	ret = new_mat4();
	ret = mat_mult(ret, rot_x);
	ret = mat_mult(ret, rot_y);
	ret = mat_mult(ret, rot_z);
	return (ret);
}
