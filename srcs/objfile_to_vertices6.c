/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objfile_to_vertices6.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:40:38 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 16:40:39 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

char	test_valid_inds(int *faces, size_t ind, t_objfile *objfile)
{
	if (faces[ind] <= 0 || faces[ind] >= (int)objfile->vertices->len)
		return (0);
	if (faces[ind + 1] >= (int)objfile->texture->len)
		return (0);
	if (faces[ind + 2] >= (int)objfile->normals->len)
		return (0);
	if (faces[ind + 3] <= 0 || faces[ind + 3] >= (int)objfile->vertices->len)
		return (0);
	if (faces[ind + 4] >= (int)objfile->texture->len)
		return (0);
	if (faces[ind + 5] >= (int)objfile->normals->len)
		return (0);
	if (faces[ind + 6] <= 0 || faces[ind + 6] >= (int)objfile->vertices->len)
		return (0);
	if (faces[ind + 7] >= (int)objfile->texture->len)
		return (0);
	if (faces[ind + 8] >= (int)objfile->normals->len)
		return (0);
	return (1);
}

char	valid_faces(t_objfile *objfile, int *nb_vertices)
{
	size_t	ind;
	int		*faces;

	faces = (int*)objfile->faces->elts;
	ind = 0;
	*nb_vertices = 0;
	while (ind < objfile->faces->len)
	{
		if (!(test_valid_inds(faces, ind, objfile)))
			return (0);
		ind += 9;
		if (faces[ind] != 0)
			ind -= 6;
		else
			ind++;
		(*nb_vertices) += 3;
	}
	return (1);
}

void	set_new_params(t_solve_text_coords_params *params,
					t_solve_text_coords_params *new_params, int new_top_left)
{
	new_params->vertex_in_faces = params->vertex_in_faces;
	new_params->vertex_text_already_set = params->vertex_text_already_set;
	new_params->scale = params->scale;
	new_params->top_left_vertex = new_top_left;
}
