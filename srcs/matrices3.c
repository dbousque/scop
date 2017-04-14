/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:58:39 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 13:58:41 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_vec	*vec3_sub(t_vec *vec1, t_vec *vec2)
{
	t_vec	*res;

	res = new_vec3(0.0, 0.0, 0.0);
	res->elts[0] = vec1->elts[0] - vec2->elts[0];
	res->elts[1] = vec1->elts[1] - vec2->elts[1];
	res->elts[2] = vec1->elts[2] - vec2->elts[2];
	return (res);
}

t_vec	*vec3_cross(t_vec *vec1, t_vec *vec2)
{
	float	one;
	float	two;
	float	three;

	one = (vec1->elts[1] * vec2->elts[2]) - (vec1->elts[2] * vec2->elts[1]);
	two = (vec1->elts[2] * vec2->elts[0]) - (vec1->elts[0] * vec2->elts[2]);
	three = (vec1->elts[0] * vec2->elts[1]) - (vec1->elts[1] * vec2->elts[0]);
	return (new_vec3(one, two, three));
}

float	mult_row_col(t_mat *mat1, t_mat *mat2, int row1, int column2)
{
	float	val;

	val = mat1->elts[row1 * 4] * mat2->elts[column2];
	val += mat1->elts[row1 * 4 + 1] * mat2->elts[4 + column2];
	val += mat1->elts[row1 * 4 + 2] * mat2->elts[8 + column2];
	val += mat1->elts[row1 * 4 + 3] * mat2->elts[12 + column2];
	return (val);
}

t_mat	*mat_mult(t_mat *mat1, t_mat *mat2)
{
	t_mat	*res;
	int		i;
	int		j;

	res = new_mat4();
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			res->elts[i * 4 + j] = mult_row_col(mat1, mat2, i, j);
			j++;
		}
		i++;
	}
	return (res);
}

t_mat	*scale(t_vec *vec)
{
	t_mat	*mat;

	mat = new_mat4();
	mat->elts[0] = vec->elts[0];
	mat->elts[5] = vec->elts[1];
	mat->elts[10] = vec->elts[2];
	return (mat);
}
