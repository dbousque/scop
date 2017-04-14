/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objfile_to_vertices.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:12:35 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 18:12:37 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void	objfile_to_vertices_middle1(int *decal, size_t *faces_ind)
{
	*decal += 3;
	*faces_ind -= 6;
}

void	objfile_to_vertices_middle2(int *decal, size_t *faces_ind)
{
	*decal = 0;
	(*faces_ind)++;
}

char	objfile_to_vertices2(t_objfile *objfile, GLfloat **verts,
											size_t faces_ind, size_t res_ind)
{
	size_t	x;
	int		decal;

	decal = 0;
	while (faces_ind < objfile->faces->len)
	{
		x = 0;
		while (x < 3)
		{
			set_vertex(objfile, verts, faces_ind - (x == 0 ? decal : 0),
																	res_ind);
			faces_ind += 3;
			res_ind += 17;
			x++;
		}
		if (objfile->normals->len == 3)
			add_normal2(objfile, faces_ind - 6, decal + 3);
		if (((int*)objfile->faces->elts)[faces_ind] != 0)
			objfile_to_vertices_middle1(&decal, &faces_ind);
		else
			objfile_to_vertices_middle2(&decal, &faces_ind);
	}
	if (objfile->normals->len == 3)
		second_pass_add_normals(objfile, verts);
	return (1);
}

char	objfile_to_vertices(t_objfile *objfile, GLfloat **verts,
															int *nb_vertices)
{
	if (!(valid_faces(objfile, nb_vertices)))
	{
		printf("a face has an invalid index\n");
		return (0);
	}
	if (!(*verts = (GLfloat*)malloc(*nb_vertices * sizeof(GLfloat) * 17)))
		return (0);
	if (objfile->normals->len == 3)
	{
		if (!(create_calc_normals(objfile, nb_vertices)))
			return (0);
	}
	if (objfile->texture->len == 2)
		generate_texture_coords2(objfile);
	return (objfile_to_vertices2(objfile, verts, 0, 0));
}
