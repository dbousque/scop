/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objfile_to_vertices5.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:40:33 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 16:40:34 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

char	create_calc_normals(t_objfile *objfile, int *nb_vertices)
{
	int		i;

	objfile->calc_normals = new_list(sizeof(float));
	free(objfile->calc_normals->elts);
	if (!(objfile->calc_normals->elts =
			(float*)malloc(sizeof(float) * (*nb_vertices * 3))))
	{
		return (0);
	}
	i = 0;
	while (i < *nb_vertices * 3)
	{
		((float*)objfile->calc_normals->elts)[i] = 0.0;
		i++;
	}
	objfile->calc_normals->size = (*nb_vertices * 3);
	objfile->calc_normals->len = (*nb_vertices * 3);
	return (1);
}

char	find_top_left_cond1(float *v, int *f, size_t i, float tl[4])
{
	return (v[f[i] * 3 + 1] > tl[1]
				|| (v[f[i] * 3 + 1] == tl[1] && v[f[i] * 3] < tl[0]));
}

void	set_vertex_in_faces(t_objfile *objfile, t_list **vertex_in_faces)
{
	size_t	i;
	int		*faces;
	int		current_face_start;

	current_face_start = 0;
	faces = (int*)objfile->faces->elts;
	i = 0;
	while (i < objfile->faces->len)
	{
		if (!(vertex_in_faces[faces[i]]))
			vertex_in_faces[faces[i]] = new_list(sizeof(int));
		add_to_list(vertex_in_faces[faces[i]], &current_face_start);
		faces[i + 1] = faces[i];
		i += 3;
		if (faces[i] == 0)
		{
			i++;
			current_face_start = (int)i;
		}
	}
}

void	get_text_xy(t_objfile *objfile, int known_unkown_ind[2],
												float res_xy[2], float scale)
{
	float	*vertices;
	float	*texture;
	float	known_xyz[3];
	float	unknown_xyz[3];
	float	known_text_xy[2];

	vertices = (float*)objfile->vertices->elts;
	texture = (float*)objfile->texture->elts;
	known_xyz[0] = vertices[known_unkown_ind[0] * 3];
	known_xyz[1] = vertices[known_unkown_ind[0] * 3 + 1];
	known_xyz[2] = vertices[known_unkown_ind[0] * 3 + 2];
	unknown_xyz[0] = vertices[known_unkown_ind[1] * 3];
	unknown_xyz[1] = vertices[known_unkown_ind[1] * 3 + 1];
	unknown_xyz[2] = vertices[known_unkown_ind[1] * 3 + 2];
	known_text_xy[0] = texture[known_unkown_ind[0] * 2];
	known_text_xy[1] = texture[known_unkown_ind[0] * 2 + 1];
	known_xyz[0] = unknown_xyz[0] - known_xyz[0];
	known_xyz[1] = unknown_xyz[1] - known_xyz[1];
	known_xyz[2] = unknown_xyz[2] - known_xyz[2];
	res_xy[0] = known_text_xy[0] + ((known_xyz[0] + known_xyz[2]));
	res_xy[1] = known_text_xy[1] + (known_xyz[1]);
	(void)scale;
}
