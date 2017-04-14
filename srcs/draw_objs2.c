/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_objs2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:51:18 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 18:51:20 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void	draw_lights(t_list *lights, t_mat *view, t_mat *projection)
{
	size_t				i;
	t_shader_program	*shader;
	GLuint				loc;
	t_light				*light;
	t_mat				*model;

	i = 0;
	while (i < lights->len)
	{
		light = ((t_light**)lights->elts)[i];
		shader = light->obj->shader;
		glUseProgram(shader->program);
		loc = glGetUniformLocation(shader->program, "lightColor");
		glUniform3f(loc, light->r, light->g, light->b);
		model = translate(new_vec3(light->obj->x, light->obj->y,
															light->obj->z));
		loc = glGetUniformLocation(shader->program, "model");
		glUniformMatrix4fv(loc, 1, GL_TRUE, model->elts);
		loc = glGetUniformLocation(shader->program, "view");
		glUniformMatrix4fv(loc, 1, GL_TRUE, view->elts);
		loc = glGetUniformLocation(shader->program, "projection");
		glUniformMatrix4fv(loc, 1, GL_TRUE, projection->elts);
		draw_object(shader, light->obj);
		i++;
	}
}

void	set_obj_color(t_shader_program *shader)
{
	GLuint	loc;

	loc = glGetUniformLocation(shader->program, "redStrength");
	glUniform1f(loc, g_conf.red_strength);
	loc = glGetUniformLocation(shader->program, "greenStrength");
	glUniform1f(loc, g_conf.green_strength);
	loc = glGetUniformLocation(shader->program, "blueStrength");
	glUniform1f(loc, g_conf.blue_strength);
}
