/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:14:30 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 18:14:43 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

char	*append_buf_to_res(char *res, size_t size, char *buffer, int ret)
{
	char	*new_res;
	size_t	i;
	size_t	start;

	if (!(new_res = (char*)malloc(sizeof(char) * (size + ret + 1))))
	{
		ft_putstr("malloc error\n");
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		new_res[i] = res[i];
		i++;
	}
	start = 0;
	while (start < (size_t)ret)
	{
		new_res[i + start] = buffer[start];
		start++;
	}
	new_res[i + start] = '\0';
	return (new_res);
}

char	*read_file_error(char *msg, char *filename)
{
	printf("%s %s\n", msg, filename);
	return (NULL);
}

char	*read_file(char *filename, size_t max_size)
{
	char	*res;
	size_t	size;
	int		fd;
	int		ret;
	char	buffer[READ_BUFFER_LEN];

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (read_file_error("could not open file", filename));
	size = 0;
	while ((ret = read(fd, buffer, READ_BUFFER_LEN - 1)) > 0
			&& size + ret < max_size)
	{
		res = append_buf_to_res(res, size, buffer, ret);
		if (!res)
			return (NULL);
		size += ret;
	}
	if (ret == -1 || size + ret > max_size)
		return (read_file_error("read error : ", filename));
	close(fd);
	return (res);
}

void	front_up_cross(float *x, float *y, float *z)
{
	*x = (g_cam.front_y * g_cam.up_z) - (g_cam.front_z * g_cam.up_y);
	*y = (g_cam.front_z * g_cam.up_x) - (g_cam.front_x * g_cam.up_z);
	*z = (g_cam.front_x * g_cam.up_y) - (g_cam.front_y * g_cam.up_x);
}

char	return_face_error(char *msg, char *line, size_t line_nb)
{
	printf("line %ld ; %s : \"%s\"\n", line_nb, msg, line);
	return (0);
}
