/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_face.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:12:44 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 18:12:46 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

char	valid_int(char *line, char **end)
{
	size_t	i;

	i = 0;
	if (line[0] == '-' || line[0] == '+')
		line++;
	while (line[i] && line[i] >= '0' && line[i] <= '9')
		i++;
	if (i == 0)
		return (0);
	*end = line + i;
	return (1);
}

char	valid_face_point(char *line, char **end, size_t line_nb)
{
	size_t	i;

	i = 0;
	while (valid_int(line, &line))
	{
		if (*line == ' ' || *line == '\n' || !(*line))
		{
			*end = line;
			return (1);
		}
		if (*line != '/' || i >= 2)
			return (return_face_error("separator is not /", line, line_nb));
		line++;
		i++;
	}
	return (return_face_error("invalid int", line, line_nb));
}

char	valid_face_line(char *line, size_t line_nb)
{
	while (valid_face_point(line, &line, line_nb))
	{
		if (*line == '\n' || !(*line))
			return (1);
		line++;
	}
	return (0);
}

char	add_face_point(t_objfile *objfile, char *line, char **end,
																size_t line_nb)
{
	int		tmp;

	if ((tmp = strtol(line, &line, 10)) <= 0)
		return (0);
	add_to_list(objfile->faces, &tmp);
	if (*line == ' ' || *line == '\n' || !(*line))
		tmp = 0;
	else
	{
		tmp = strtol(line + 1, &line, 10);
		if (tmp <= 0)
			return (return_face_error("an index is <= 0", line, line_nb));
	}
	add_to_list(objfile->faces, &tmp);
	if (*line == ' ' || *line == '\n' || !(*line))
		tmp = 0;
	else
	{
		tmp = strtol(line + 1, &line, 10);
		if (tmp <= 0)
			return (return_face_error("an index is <= 0", line, line_nb));
	}
	add_to_list(objfile->faces, &tmp);
	*end = line;
	return (1);
}

char	add_face(t_objfile *objfile, char *line, size_t line_nb)
{
	int		zero;

	zero = 0;
	line += 2;
	while (*line == ' ')
		line++;
	if (!(valid_face_line(line, line_nb)))
		return (0);
	while (1)
	{
		if (!(add_face_point(objfile, line, &line, line_nb)))
			return (0);
		if (*line == '\n' || !(*line))
		{
			add_to_list(objfile->faces, &zero);
			break ;
		}
	}
	return (1);
}
