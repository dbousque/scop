/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objfile_to_vertices2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:40:14 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 16:40:16 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void	solve_text_coords_middle2(t_objfile *objfile,
			t_solve_text_coords_params *params, float new_xy[2], size_t i)
{
	int							x;
	int							*face;
	t_solve_text_coords_params	new_params;
	int							known_unkown_ind[2];

	face = (int*)objfile->faces->elts +
		((int*)params->vertex_in_faces[params->top_left_vertex]->elts)[i];
	x = 0;
	while (face[x] != 0)
	{
		if (!params->vertex_text_already_set[face[x]])
		{
			known_unkown_ind[0] = face[0];
			known_unkown_ind[1] = face[x];
			get_text_xy(objfile, known_unkown_ind, new_xy, params->scale);
			set_new_params(params, &new_params, face[x]);
			solve_text_coords(objfile, &new_params, new_xy[0], new_xy[1]);
		}
		x += 3;
	}
}

void	solve_text_coords_middle(t_objfile *objfile,
			t_solve_text_coords_params *params, float new_xy[2], size_t i)
{
	int							*face;
	t_solve_text_coords_params	new_params;
	int							known_unkown_ind[2];

	face = (int*)objfile->faces->elts +
		((int*)params->vertex_in_faces[params->top_left_vertex]->elts)[i];
	if (!params->vertex_text_already_set[face[0]])
	{
		known_unkown_ind[0] = params->top_left_vertex;
		known_unkown_ind[1] = face[0];
		get_text_xy(objfile, known_unkown_ind, new_xy, params->scale);
		set_new_params(params, &new_params, face[0]);
		solve_text_coords(objfile, &new_params, new_xy[0], new_xy[1]);
	}
	else
		solve_text_coords_middle2(objfile, params, new_xy, i);
}

void	solve_text_coords(t_objfile *objfile,
			t_solve_text_coords_params *params, float x_text, float y_text)
{
	size_t		i;
	float		new_xy[2];

	((float*)objfile->texture->elts)[params->top_left_vertex * 2] = x_text;
	((float*)objfile->texture->elts)[params->top_left_vertex * 2 + 1] = y_text;
	params->vertex_text_already_set[params->top_left_vertex] = 1;
	i = 0;
	while (i < params->vertex_in_faces[params->top_left_vertex]->len)
	{
		solve_text_coords_middle(objfile, params, new_xy, i);
		i++;
	}
}

char	generate_texture_coords3(t_objfile *objfile,
											t_solve_text_coords_params *params)
{
	size_t	i;

	free(objfile->texture->elts);
	if (!(objfile->texture->elts =
		(float*)malloc(sizeof(float) * (objfile->vertices->len / 3) * 2)))
	{
		return (0);
	}
	objfile->texture->size = (objfile->vertices->len / 3) * 2;
	objfile->texture->len = (objfile->vertices->len / 3) * 2;
	i = 0;
	while (i < (objfile->vertices->len / 3) * 2)
	{
		((float*)objfile->texture->elts)[i] = 0.0;
		i++;
	}
	i = 0;
	while (i < objfile->vertices->len)
	{
		params->vertex_in_faces[i / 3] = NULL;
		params->vertex_text_already_set[i / 3] = 0;
		i += 3;
	}
	return (1);
}

char	generate_texture_coords2(t_objfile *objfile)
{
	t_solve_text_coords_params	params;

	if (!(params.vertex_in_faces =
			(t_list**)malloc(sizeof(t_list*) * (objfile->vertices->len / 3))))
	{
		return (0);
	}
	if (!(params.vertex_text_already_set =
				(char*)malloc(sizeof(char) * (objfile->vertices->len / 3))))
	{
		return (0);
	}
	if (!(generate_texture_coords3(objfile, &params)))
		return (0);
	while (find_top_left(objfile, &(params.top_left_vertex), &(params.scale),
											params.vertex_text_already_set))
	{
		set_vertex_in_faces(objfile, params.vertex_in_faces);
		solve_text_coords(objfile, &params, 0.0, 1.0);
	}
	return (1);
}
