/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:12:01 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 18:12:03 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrices.h"

t_mat	*new_mat(int nb_rows, int nb_columns)
{
	t_mat	*mat;
	int		i;

	if (!(mat = (t_mat*)malloc(sizeof(t_mat))))
		return (NULL);
	if (!(mat->elts = (float*)malloc(sizeof(float) * (nb_rows * nb_columns))))
		return (NULL);
	mat->nb_rows = nb_rows;
	mat->nb_columns = nb_columns;
	i = 0;
	while (i < nb_rows * nb_columns)
	{
		mat->elts[i] = 0.0;
		i++;
	}
	return (mat);
}

t_mat	*new_square_mat(int n)
{
	t_mat	*mat;
	int		i;

	mat = new_mat(n, n);
	if (!mat)
		return (NULL);
	i = 0;
	while (i < n)
	{
		mat->elts[(n * i) + i] = 1.0;
		i++;
	}
	return (mat);
}

t_mat	*new_mat2(void)
{
	return (new_square_mat(2));
}

t_mat	*new_mat3(void)
{
	return (new_square_mat(3));
}

t_mat	*new_mat4(void)
{
	return (new_square_mat(4));
}
