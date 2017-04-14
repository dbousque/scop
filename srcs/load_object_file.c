/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_object_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 19:25:15 by dbousque          #+#    #+#             */
/*   Updated: 2017/04/11 15:39:36 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"
#include <sys/stat.h>

char	parse_object_line(char *line, t_globj **obj)
{
	if (startswith(line, "obj "))
	{
		if (*obj)
		{
			ft_putstr("obj appears twice\n");
			return (0);
		}
		*obj = new_obj_from_path(line + 4, 1);
	}
	if (!*obj)
	{
		ft_putstr("obj should be defined at the top of the file\n");
		return (0);
	}
	if (startswith(line, "diffuse "))
		load_texture_to_obj(*obj, line + 8);
	if (startswith(line, "specular "))
		load_specular_map_to_obj(*obj, line + 9);
	if (startswith(line, "normal "))
		load_normal_map_to_obj(*obj, line + 7);
	if (startswith(line, "spec_strength "))
		(*obj)->specular_strength = atoi(line + 14);
	return (1);
}

char	read_object_file(FILE *fp, t_globj **obj)
{
	char	*line;
	size_t	len;

	line = NULL;
	len = 0;
	while (getline(&line, &len, fp) != -1)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (!(parse_object_line(line, obj)))
		{
			fclose(fp);
			return (0);
		}
	}
	return (1);
}

char	regular_file(char *path)
{
	struct stat	stats;

	stat(path, &stats);
	return (S_ISREG(stats.st_mode));
}

char	load_object_file(char *filename, t_list *objs)
{
	FILE	*fp;
	t_globj	*obj;

	obj = NULL;
	fp = fopen(filename, "r");
	if (!fp || !(regular_file(filename)))
	{
		printf("file %s could not be opened\n", filename);
		return (0);
	}
	if (!(read_object_file(fp, &obj)))
		return (0);
	fclose(fp);
	attach_shader_program_to_obj(obj, g_obj_program);
	add_to_list(objs, &obj);
	return (1);
}
