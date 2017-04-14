/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:11:54 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 18:11:55 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

int			g_new_obj_attribs_struct[] = {3, 2, 3, 3, 3, 3};

void		get_next_color(float rgb[3])
{
	rgb[0] = (rand() % 1000) / 1000.0;
	rgb[1] = (rand() % 1000) / 1000.0;
	rgb[2] = (rand() % 1000) / 1000.0;
}

void		add_face_color_to_obj(GLfloat *vertices, int nb_vertices)
{
	int		i;
	float	rgb[3];

	i = 0;
	while (i < nb_vertices)
	{
		get_next_color(rgb);
		vertices[i * 17 + 8] = rgb[0];
		vertices[i * 17 + 9] = rgb[1];
		vertices[i * 17 + 10] = rgb[2];
		vertices[(i + 1) * 17 + 8] = rgb[0];
		vertices[(i + 1) * 17 + 9] = rgb[1];
		vertices[(i + 1) * 17 + 10] = rgb[2];
		vertices[(i + 2) * 17 + 8] = rgb[0];
		vertices[(i + 2) * 17 + 9] = rgb[1];
		vertices[(i + 2) * 17 + 10] = rgb[2];
		i += 3;
	}
}

t_globj		*new_obj_from_path(char *path, char main_obj)
{
	t_objfile	*objfile;
	GLfloat		*vertices;
	int			nb_vertices;
	float		scale;
	t_globj		*obj;

	objfile = parse_objfile(path);
	if (!objfile)
	{
		printf("could not parse .obj\n");
		return (NULL);
	}
	if (!(objfile_to_vertices(objfile, &vertices, &nb_vertices)))
	{
		printf("error in .obj\n");
		return (NULL);
	}
	scale = adjust_obj(vertices, nb_vertices);
	if (!main_obj)
		scale = 1.0;
	add_face_color_to_obj(vertices, nb_vertices);
	calc_tangent_bitangent(vertices, nb_vertices);
	obj = new_object(vertices, nb_vertices, g_new_obj_attribs_struct, 6);
	obj->scale = scale;
	return (obj);
}

void		update_stats(void)
{
	g_conf.frames_seen++;
	if (glfwGetTime() - g_conf.info_updated_at >= 2.0)
	{
		printf("cpu fps : %.1f\n", g_conf.frames_seen / g_conf.time_spent);
		printf("actual fps : %.1f\n",
				g_conf.frames_seen / (glfwGetTime() - g_conf.info_updated_at));
		printf("time per frame : %.1f ms\n\n",
							g_conf.time_spent / g_conf.frames_seen * 1000.0);
		g_conf.frames_seen = 0;
		g_conf.info_updated_at = glfwGetTime();
		g_conf.time_spent = 0.0;
	}
}
