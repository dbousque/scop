/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vertices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:12:52 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 18:12:53 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

char	valid_vertex_line(char *line, size_t line_nb)
{
	if (!(valid_float(line, &line)) && !(valid_int(line, &line)))
		return (return_vertex_error("invalid number on line", line, line_nb));
	if (*line != ' ')
		return (return_vertex_error("separator not a space", line, line_nb));
	line += 1;
	if (!(valid_float(line, &line)) && !(valid_int(line, &line)))
		return (return_vertex_error("invalid number on line", line, line_nb));
	if (*line != ' ')
		return (return_vertex_error("separator not a space", line, line_nb));
	line += 1;
	if (!(valid_float(line, &line)) && !(valid_int(line, &line)))
		return (return_vertex_error("invalid number on line", line, line_nb));
	if (*line != '\n' && *line != '\0')
		return (return_vertex_error("no \\n at end of line", line, line_nb));
	return (1);
}

char	valid_texture_line(char *line, size_t line_nb)
{
	if (!(valid_float(line, &line)) && !(valid_int(line, &line)))
		return (return_vertex_error("invalid number on line", line, line_nb));
	if (*line != ' ')
		return (return_vertex_error("separator not a space", line, line_nb));
	line += 1;
	if (!(valid_float(line, &line)) && !(valid_int(line, &line)))
		return (return_vertex_error("invalid number on line", line, line_nb));
	return (1);
}

char	add_vertex(t_objfile *objfile, char *line, size_t line_nb)
{
	float	tmp;

	line += 2;
	while (*line == ' ')
		line++;
	if (!(valid_vertex_line(line, line_nb)))
		return (0);
	tmp = strtof(line, &line);
	if (tmp == HUGE_VALF || tmp == -HUGE_VALF)
		return (return_vertex_error("float overflow", line, line_nb));
	add_to_list(objfile->vertices, &tmp);
	line++;
	tmp = strtof(line, &line);
	add_to_list(objfile->vertices, &tmp);
	line++;
	tmp = strtof(line, &line);
	add_to_list(objfile->vertices, &tmp);
	return (1);
}

char	add_normal(t_objfile *objfile, char *line, size_t line_nb)
{
	float	tmp;

	line += 3;
	while (*line == ' ')
		line++;
	if (!(valid_vertex_line(line, line_nb)))
		return (0);
	tmp = strtof(line, &line);
	if (tmp == HUGE_VALF || tmp == -HUGE_VALF)
		return (return_vertex_error("float overflow", line, line_nb));
	add_to_list(objfile->normals, &tmp);
	line++;
	tmp = strtof(line, &line);
	add_to_list(objfile->normals, &tmp);
	line++;
	tmp = strtof(line, &line);
	add_to_list(objfile->normals, &tmp);
	return (1);
}

char	add_texture(t_objfile *objfile, char *line, size_t line_nb)
{
	float	tmp;

	line += 3;
	while (*line == ' ')
		line++;
	if (!(valid_texture_line(line, line_nb)))
		return (0);
	tmp = strtof(line, &line);
	if (tmp == HUGE_VALF || tmp == -HUGE_VALF)
		return (return_vertex_error("float overflow", line, line_nb));
	add_to_list(objfile->texture, &tmp);
	line++;
	tmp = strtof(line, &line);
	add_to_list(objfile->texture, &tmp);
	return (1);
}
