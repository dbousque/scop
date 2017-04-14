/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objfile_to_vertices3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:40:22 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 16:40:24 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

char	find_top_left_cond2(float *v, int *f, size_t i, float tl[4])
{
	return (v[f[i] * 3 + 1] < tl[1]
				|| (v[f[i] * 3 + 1] == tl[1] && v[f[i] * 3] > tl[0]));
}

void	find_top_left_expr_cond1(float *v, int *f, size_t i, float tl[4])
{
	tl[0] = v[f[i] * 3];
	tl[1] = v[f[i] * 3 + 1];
}

void	find_top_left_expr_cond2(float *v, int *f, size_t i, float tl[4])
{
	tl[2] = v[f[i] * 3];
	tl[3] = v[f[i] * 3 + 1];
}

void	find_top_set_vars(float **v, int **f, size_t *i, t_objfile *objfile)
{
	*f = (int*)objfile->faces->elts;
	*v = (float*)objfile->vertices->elts;
	*i = 0;
}

char	find_top_left(t_objfile *objfile, int *top_left_vertex, float *scale,
												char *vertex_text_already_set)
{
	int		*f;
	size_t	i;
	float	tl[4];
	float	*v;
	char	set_once;

	set_once = 0;
	find_top_set_vars(&v, &f, &i, objfile);
	while (i < objfile->faces->len)
	{
		if (!vertex_text_already_set[f[i]])
		{
			if (!set_once || find_top_left_cond1(v, f, i, tl))
			{
				find_top_left_expr_cond1(v, f, i, tl);
				*top_left_vertex = f[i];
			}
			if (!set_once || find_top_left_cond2(v, f, i, tl))
				find_top_left_expr_cond2(v, f, i, tl);
			set_once = 1;
		}
		i = (f[i + 3] == 0 ? i + 4 : i + 3);
	}
	*scale = fmaxf(fabs(tl[0] - tl[2]), fabs(tl[1] - tl[3]));
	return (set_once);
}
