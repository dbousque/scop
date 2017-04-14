/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:58:26 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 13:58:28 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_mat	*translate(t_vec *vec)
{
	t_mat	*mat;

	mat = new_mat4();
	mat->elts[3] = vec->elts[0];
	mat->elts[7] = vec->elts[1];
	mat->elts[11] = vec->elts[2];
	return (mat);
}

float	deg_to_rad(float deg)
{
	return ((deg * 3.14159) / 180);
}

t_mat	*transpose(t_mat *mat)
{
	t_mat	*res;
	int		i;
	int		j;

	res = new_mat4();
	i = 0;
	while (i < mat->nb_rows)
	{
		j = 0;
		while (j < mat->nb_columns)
		{
			res->elts[j * mat->nb_rows + i] =
											mat->elts[i * mat->nb_columns + j];
			j++;
		}
		i++;
	}
	return (res);
}

t_mat	*perspective(float fov, float ratio, float near, float far)
{
	t_mat	*ret;
	float	fov_norm;

	far /= (far - near);
	fov_norm = 1.0 - tanf(fov / 2.0);
	ret = new_mat4();
	ret->elts[0] = fov_norm;
	ret->elts[5] = fov_norm / ratio;
	ret->elts[10] = far;
	ret->elts[11] = near * far;
	ret->elts[14] = -1.0;
	ret->elts[15] = 0.0;
	return (ret);
}

void	print_mat(t_mat *mat)
{
	int		i;
	int		j;

	i = 0;
	while (i < mat->nb_rows)
	{
		j = 0;
		while (j < mat->nb_columns)
		{
			printf("%.2f ", mat->elts[(i * mat->nb_columns) + j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
