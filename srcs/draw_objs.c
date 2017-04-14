/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_objs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:11:16 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 18:11:18 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void	set_obj_light(t_globj *obj, t_light *light, size_t x)
{
	char		*x_str;
	char		*tmp;
	GLint		loc;

	x_str = ft_itoa(x + 1);
	tmp = ft_strconcat("lightColor", x_str);
	loc = glGetUniformLocation(obj->shader->program, tmp);
	glUniform3f(loc, light->r, light->g, light->b);
	free(tmp);
	tmp = ft_strconcat("lightPos", x_str);
	loc = glGetUniformLocation(obj->shader->program, tmp);
	glUniform3f(loc, light->obj->x, light->obj->y, light->obj->z);
	free(tmp);
	tmp = ft_strconcat("ambientColor", x_str);
	loc = glGetUniformLocation(obj->shader->program, tmp);
	glUniform3f(loc, light->r * light->ambient_strength,
			light->g * light->ambient_strength,
			light->b * light->ambient_strength);
	free(tmp);
	free(x_str);
}

void	set_obj(t_list *lights, t_globj *obj, float texture_strength,
														float colors_strength)
{
	GLint		loc;

	glUseProgram(obj->shader->program);
	loc = glGetUniformLocation(obj->shader->program, "cameraPos");
	glUniform3f(loc, g_cam.x, g_cam.y, g_cam.z);
	loc = glGetUniformLocation(obj->shader->program, "nbLights");
	glUniform1i(loc, (int)lights->len);
	loc = glGetUniformLocation(obj->shader->program, "textureStrength");
	glUniform1f(loc, texture_strength);
	loc = glGetUniformLocation(obj->shader->program, "colorsStrength");
	glUniform1f(loc, colors_strength);
	loc = glGetUniformLocation(obj->shader->program, "redStrength");
	glUniform1f(loc, g_conf.red_strength);
	loc = glGetUniformLocation(obj->shader->program, "greenStrength");
	glUniform1f(loc, g_conf.green_strength);
	loc = glGetUniformLocation(obj->shader->program, "blueStrength");
	glUniform1f(loc, g_conf.blue_strength);
}

void	set_lights(t_list *objs, t_list *lights, float texture_strength,
														float colors_strength)
{
	size_t		i;
	size_t		x;
	t_globj		*obj;

	i = 0;
	while (i < objs->len)
	{
		obj = ((t_globj**)objs->elts)[i];
		set_obj(lights, obj, texture_strength, colors_strength);
		x = 0;
		while (x < lights->len)
		{
			set_obj_light(obj, ((t_light**)lights->elts)[x], x);
			x++;
		}
		i++;
	}
}

void	prepare_object(t_globj *obj, t_shader_program *shader, size_t i,
																GLuint loc)
{
	t_mat				*model;
	t_mat				*scal;
	t_mat				*rot;
	t_mat				*trans;

	set_obj_color(shader);
	if (i == 0)
	{
		trans = translate(new_vec3(obj->x, obj->y, obj->z));
		scal = scale(new_vec3(obj->scale, obj->scale, obj->scale));
		rot = rotate(new_vec3(0.0, 0.0,
								deg_to_rad((GLfloat)glfwGetTime() * 15.0f)));
		model = mat_mult(scal, trans);
		model = mat_mult(model, rot);
	}
	else
	{
		scal = scale(new_vec3(obj->scale, obj->scale, obj->scale));
		model = translate(new_vec3(obj->x, obj->y, obj->z));
		model = mat_mult(model, scal);
	}
	loc = glGetUniformLocation(shader->program, "transpInv");
	glUniformMatrix4fv(loc, 1, GL_TRUE, (transpose(invert(model)))->elts);
	loc = glGetUniformLocation(shader->program, "model");
	glUniformMatrix4fv(loc, 1, GL_TRUE, model->elts);
}

void	draw_objects(t_list *objs, t_mat *view, t_mat *projection)
{
	size_t				i;
	t_shader_program	*shader;
	t_globj				*obj;
	GLuint				loc;

	i = 0;
	while (i < objs->len)
	{
		obj = ((t_globj**)objs->elts)[i];
		shader = obj->shader;
		glUseProgram(shader->program);
		prepare_object(obj, shader, i, loc);
		loc = glGetUniformLocation(shader->program, "view");
		glUniformMatrix4fv(loc, 1, GL_TRUE, view->elts);
		loc = glGetUniformLocation(shader->program, "projection");
		glUniformMatrix4fv(loc, 1, GL_TRUE, projection->elts);
		draw_object(shader, obj);
		i++;
	}
}
