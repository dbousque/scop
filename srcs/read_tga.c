/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tga.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 17:12:04 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/08 17:12:06 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

char	*read_tga(char *path, int *width, int *height)
{
	char	*contents;

	contents = read_file(path, 20 * 1024 * 1024);
	if (!contents)
		return (NULL);
	*width = *((short*)(contents + 12));
	*height = *((short*)(contents + 14));
	return (contents + 18);
}
