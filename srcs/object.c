/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:12:27 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 18:12:28 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void		*cpy_array(void *array, size_t size)
{
	char	*to_cpy;
	char	*res;
	size_t	i;

	if (!(res = (char*)malloc(size)))
		return (NULL);
	to_cpy = (char*)array;
	i = 0;
	while (i < size)
	{
		res[i] = to_cpy[i];
		i++;
	}
	return (res);
}

void		set_obj_std(t_globj *obj, int nb_vertices)
{
	obj->nb_vertices = nb_vertices;
	obj->has_textures = 0;
	obj->has_indices = 0;
	obj->nb_textures = 0;
	obj->textures = NULL;
	obj->shader = NULL;
	obj->x = 0.0;
	obj->y = 0.0;
	obj->z = 0.0;
	obj->normal_mode = 0;
	obj->specular_map = 0;
	obj->normal_map = 0;
	obj->has_specular_map = 0;
	obj->has_normal_map = 0;
	obj->specular_strength = 0.0;
	obj->scale = 1.0;
}

t_globj		*new_object_malloc_error(void)
{
	ft_putstr("malloc error\n");
	return (NULL);
}

void		new_object_middle(GLfloat *vertices, size_t tot_data_len,
																t_globj *obj)
{
	glGenVertexArrays(1, &(obj->vao1));
	glBindVertexArray(obj->vao1);
	glGenBuffers(1, &(obj->vbo1));
	glBindBuffer(GL_ARRAY_BUFFER, obj->vbo1);
	glBufferData(GL_ARRAY_BUFFER, tot_data_len,
									(GLfloat const*)vertices, GL_STATIC_DRAW);
}

t_globj		*new_object(GLfloat *vertices, int nb_vertices,
										int attribs_struct[], int nb_attribs)
{
	t_globj		*obj;
	size_t		tot_data_len;
	GLfloat		*vertices_cpy;

	if (!(obj = (t_globj*)malloc(sizeof(t_globj))))
		return (new_object_malloc_error());
	set_obj_std(obj, nb_vertices);
	tot_data_len = sizeof(GLfloat)
					* (nb_vertices * int_arr_sum(attribs_struct, nb_attribs));
	new_object_middle(vertices, tot_data_len, obj);
	init_vertex_attributes(attribs_struct, nb_attribs, nb_vertices,
																tot_data_len);
	glBindVertexArray(0);
	vertices_cpy = cpy_array(vertices, sizeof(GLfloat) * 17 * nb_vertices);
	calculate_raw_normals(vertices_cpy, nb_vertices);
	glGenVertexArrays(1, &(obj->vao2));
	glBindVertexArray(obj->vao2);
	glGenBuffers(1, &(obj->vbo2));
	glBindBuffer(GL_ARRAY_BUFFER, obj->vbo2);
	glBufferData(GL_ARRAY_BUFFER, tot_data_len,
								(GLfloat const*)vertices_cpy, GL_STATIC_DRAW);
	init_vertex_attributes(attribs_struct, nb_attribs, nb_vertices,
																tot_data_len);
	glBindVertexArray(0);
	return (obj);
}
