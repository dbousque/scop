/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objfile_to_vertices4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:40:28 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 16:40:29 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void	set_vertex(t_objfile *objfile, GLfloat **vertices, size_t faces_ind,
													size_t res_ind)
{
	float	*raw_vertices;
	float	*normals;
	float	*texture;
	int		*faces;

	raw_vertices = (float*)objfile->vertices->elts;
	normals = (float*)objfile->normals->elts;
	texture = (float*)objfile->texture->elts;
	faces = (int*)objfile->faces->elts;
	(*vertices)[res_ind] = raw_vertices[faces[faces_ind] * 3];
	(*vertices)[res_ind + 1] = raw_vertices[faces[faces_ind] * 3 + 1];
	(*vertices)[res_ind + 2] = raw_vertices[faces[faces_ind] * 3 + 2];
	(*vertices)[res_ind + 3] = texture[faces[faces_ind + 1] * 2];
	(*vertices)[res_ind + 4] = texture[faces[faces_ind + 1] * 2 + 1];
	(*vertices)[res_ind + 5] = normals[faces[faces_ind + 2] * 3];
	(*vertices)[res_ind + 6] = normals[faces[faces_ind + 2] * 3 + 1];
	(*vertices)[res_ind + 7] = normals[faces[faces_ind + 2] * 3 + 2];
}

void	add_normal2(t_objfile *objfile, size_t f_i, int decal)
{
	float	v1[3];
	float	v2[3];
	float	*verts;
	int		*faces;
	float	*normals;

	faces = (int*)objfile->faces->elts;
	verts = (float*)objfile->vertices->elts;
	normals = (float*)objfile->calc_normals->elts;
	v1[0] = verts[faces[f_i - decal] * 3] - verts[faces[f_i] * 3];
	v1[1] = verts[faces[f_i - decal] * 3 + 1] - verts[faces[f_i] * 3 + 1];
	v1[2] = verts[faces[f_i - decal] * 3 + 2] - verts[faces[f_i] * 3 + 2];
	v2[0] = verts[faces[f_i - decal] * 3] - verts[faces[f_i + 3] * 3];
	v2[1] = verts[faces[f_i - decal] * 3 + 1] - verts[faces[f_i + 3] * 3 + 1];
	v2[2] = verts[faces[f_i - decal] * 3 + 2] - verts[faces[f_i + 3] * 3 + 2];
	normals[faces[f_i - decal] * 3] += v1[1] * v2[2] - v1[2] * v2[1];
	normals[faces[f_i - decal] * 3 + 1] += v1[2] * v2[0] - v1[0] * v2[2];
	normals[faces[f_i - decal] * 3 + 2] += v1[0] * v2[1] - v1[1] * v2[0];
	normals[faces[f_i] * 3] += v1[1] * v2[2] - v1[2] * v2[1];
	normals[faces[f_i] * 3 + 1] += v1[2] * v2[0] - v1[0] * v2[2];
	normals[faces[f_i] * 3 + 2] += v1[0] * v2[1] - v1[1] * v2[0];
	normals[faces[f_i + 3] * 3] += v1[1] * v2[2] - v1[2] * v2[1];
	normals[faces[f_i + 3] * 3 + 1] += v1[2] * v2[0] - v1[0] * v2[2];
	normals[faces[f_i + 3] * 3 + 2] += v1[0] * v2[1] - v1[1] * v2[0];
}

void	set_normal(t_objfile *objfile, GLfloat **vertices, size_t faces_ind,
													size_t res_ind)
{
	int		*faces;
	float	*normals;

	faces = (int*)objfile->faces->elts;
	normals = (float*)objfile->calc_normals->elts;
	(*vertices)[res_ind + 5] = normals[faces[faces_ind] * 3];
	(*vertices)[res_ind + 6] = normals[faces[faces_ind] * 3 + 1];
	(*vertices)[res_ind + 7] = normals[faces[faces_ind] * 3 + 2];
}

void	second_pass_add_normals_middle(t_objfile *objfile, size_t *faces_ind,
																	int *decal)
{
	if (((int*)objfile->faces->elts)[*faces_ind] != 0)
	{
		*decal += 3;
		*faces_ind -= 6;
	}
	else
	{
		*decal = 0;
		(*faces_ind)++;
	}
}

void	second_pass_add_normals(t_objfile *objfile, GLfloat **vertices)
{
	size_t	x;
	size_t	faces_ind;
	size_t	res_ind;
	int		decal;

	decal = 0;
	res_ind = 0;
	faces_ind = 0;
	while (faces_ind < objfile->faces->len)
	{
		x = 0;
		while (x < 3)
		{
			set_normal(objfile, vertices, faces_ind - (x == 0 ? decal : 0),
											res_ind);
			faces_ind += 3;
			res_ind += 17;
			x++;
		}
		second_pass_add_normals_middle(objfile, &faces_ind, &decal);
	}
}
