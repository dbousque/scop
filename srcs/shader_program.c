/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader_program.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:12:59 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 18:13:01 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

char				create_shader(GLchar const *shader_source, int mode,
																GLuint *shader)
{
	GLint	success;
	GLchar	info_log[512];

	*shader = glCreateShader(mode);
	glShaderSource(*shader, 1, &shader_source, NULL);
	glCompileShader(*shader);
	glGetShaderiv(*shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(*shader, 512, NULL, info_log);
		ft_putstr("SHADER COMPILATION ERROR:\n");
		ft_putstr(info_log);
		ft_putstr("\n");
		return (0);
	}
	return (1);
}

char				create_shaders(GLchar const *vs_content,
					GLchar const *fs_content, t_shader_program *shader_program)
{
	if (!(create_shader(vs_content, GL_VERTEX_SHADER,
											&(shader_program->vertex_shader))))
	{
		ft_putstr("could not compile vertex shader\n");
		return (0);
	}
	if (!(create_shader(fs_content, GL_FRAGMENT_SHADER,
										&(shader_program->fragment_shader))))
	{
		ft_putstr("could not compile fragment shader\n");
		return (0);
	}
	return (1);
}

t_shader_program	*create_shaders_and_program(GLchar const *vs_content,
					GLchar const *fs_content, t_shader_program *shader_program)
{
	GLint	success;
	GLchar	info_log[512];

	if (!(create_shaders(vs_content, fs_content, shader_program)))
		return (NULL);
	shader_program->program = glCreateProgram();
	glAttachShader(shader_program->program, shader_program->vertex_shader);
	glAttachShader(shader_program->program, shader_program->fragment_shader);
	glLinkProgram(shader_program->program);
	glGetProgramiv(shader_program->program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shader_program->program, 512, NULL, info_log);
		printf("PROGRAM LINKING ERROR:\n");
		ft_putstr(info_log);
		ft_putstr("\n");
		return (NULL);
	}
	glDeleteShader(shader_program->vertex_shader);
	glDeleteShader(shader_program->fragment_shader);
	return (shader_program);
}

t_shader_program	*new_shader_program(char *vertex_shader_path,
												char *fragment_shader_path)
{
	GLchar const		*vs_cont;
	GLchar const		*fs_content;
	t_shader_program	*shader_program;

	shader_program = (t_shader_program*)malloc(sizeof(t_shader_program));
	if (!shader_program)
	{
		ft_putstr("malloc error\n");
		return (NULL);
	}
	vs_cont = read_file(vertex_shader_path, MAX_SHADER_SIZE);
	if (!vs_cont)
	{
		ft_putstr(vertex_shader_path);
		ft_putstr(" : invalid file\n");
		return (NULL);
	}
	fs_content = read_file(fragment_shader_path, MAX_SHADER_SIZE);
	if (!fs_content)
	{
		ft_putstr(fragment_shader_path);
		ft_putstr(" : invalid file\n");
		return (NULL);
	}
	return (create_shaders_and_program(vs_cont, fs_content, shader_program));
}
