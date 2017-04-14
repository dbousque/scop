/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vertices2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 16:46:06 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 16:46:08 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

char	return_vertex_error(char *msg, char *line, size_t line_nb)
{
	printf("line %ld ; %s : %s", line_nb, msg, line);
	return (0);
}

char	valid_float(char *line, char **end)
{
	size_t	i;
	char	seen_point;

	seen_point = 0;
	if (line[0] == '-' || line[0] == '+')
		line++;
	i = 0;
	while (line[i] && ((line[i] <= '9' && line[i] >= '0')
			|| line[i] == '.' || (line[i] == 'e' && line[i + 1] == '-')
			|| (line[i] == '-' && line[i - 1] == 'e')
			|| (line[i] == 'e' && line[i + 1] == '+')
			|| (line[i] == '+' && line[i - 1] == 'e')))
	{
		if (line[i] == '.')
		{
			if (seen_point)
				return (0);
			seen_point = 1;
		}
		i++;
	}
	if (i < 1 || !seen_point || line[i - 1] == '.')
		return (0);
	*end = line + i;
	return (1);
}
