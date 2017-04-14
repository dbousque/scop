/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:59:29 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 13:59:31 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void	attach_indices_to_obj(t_globj *obj, GLuint indices[], int nb_indices)
{
	glBindVertexArray(obj->vao1);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glGenBuffers(1, &(obj->ebo1));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, obj->ebo1);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * nb_indices, indices,
															GL_STATIC_DRAW);
	glBindVertexArray(0);
	glBindVertexArray(obj->vao2);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glGenBuffers(1, &(obj->ebo2));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, obj->ebo2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * nb_indices, indices,
															GL_STATIC_DRAW);
	glBindVertexArray(0);
	obj->has_indices = 1;
	obj->nb_indices = nb_indices;
}

void	attach_shader_program_to_obj(t_globj *obj, t_shader_program *shader)
{
	obj->shader = shader;
}

void	activate_textures2(t_shader_program *shader_program, t_globj *obj)
{
	if (obj->has_specular_map)
	{
		glUniform1i(glGetUniformLocation(shader_program->program,
								"hasSpecularMap"), 1);
		glActiveTexture(get_texture_nb(obj->nb_textures));
		glBindTexture(GL_TEXTURE_2D, obj->specular_map);
		glUniform1i(glGetUniformLocation(shader_program->program,
											"ourSpecular1"), obj->nb_textures);
	}
	if (obj->has_normal_map)
	{
		glUniform1i(glGetUniformLocation(shader_program->program,
								"hasNormalMap"), 1);
		glActiveTexture(
			get_texture_nb(obj->nb_textures + obj->has_specular_map));
		glBindTexture(GL_TEXTURE_2D, obj->normal_map);
		glUniform1i(glGetUniformLocation(shader_program->program,
					"ourNormal1"), obj->nb_textures + obj->has_specular_map);
	}
	glUniform1f(glGetUniformLocation(shader_program->program,
								"specularStrength"), obj->specular_strength);
}

void	activate_textures(t_shader_program *shader_program, t_globj *obj)
{
	int		i;
	char	*tmp_text_name;
	char	*i_str;

	glUniform1i(glGetUniformLocation(shader_program->program,
								"hasSpecularMap"), 0);
	glUniform1i(glGetUniformLocation(shader_program->program,
								"hasNormalMap"), 0);
	i = 0;
	while (i < obj->nb_textures)
	{
		i_str = ft_itoa(i);
		tmp_text_name = ft_strconcat("ourTexture", i_str);
		glActiveTexture(get_texture_nb(i));
		glBindTexture(GL_TEXTURE_2D, obj->textures[i]);
		glUniform1i(glGetUniformLocation(shader_program->program,
														tmp_text_name), i);
		free(i_str);
		free(tmp_text_name);
		i++;
	}
	activate_textures2(shader_program, obj);
}

void	draw_object(t_shader_program *shader_program, t_globj *obj)
{
	if (obj->has_textures)
		activate_textures(shader_program, obj);
	glUseProgram(shader_program->program);
	if (obj->normal_mode == 0)
		glBindVertexArray(obj->vao1);
	else
		glBindVertexArray(obj->vao2);
	if (obj->has_indices)
		glDrawElements(GL_TRIANGLES, obj->nb_indices, GL_UNSIGNED_INT, 0);
	else
		glDrawArrays(GL_TRIANGLES, 0, obj->nb_vertices);
	glBindVertexArray(0);
}
