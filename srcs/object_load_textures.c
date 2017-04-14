/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_load_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:59:57 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 13:59:59 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

GLuint	make_texture(char *img_path, char *error)
{
	int				width;
	int				ht;
	int				channels;
	unsigned char	*img;
	GLuint			texture;

	*error = 0;
	if (endswith(img_path, ".tga"))
		img = (unsigned char*)read_tga(img_path, &width, &ht);
	else
		img = SOIL_load_image(img_path, &width, &ht, &channels, SOIL_LOAD_RGB);
	if (!img)
	{
		*error = 1;
		return (0);
	}
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, ht, 0, GL_RGB,
													GL_UNSIGNED_BYTE, img);
	glGenerateMipmap(GL_TEXTURE_2D);
	if (!(endswith(img_path, ".tga")))
		SOIL_free_image_data(img);
	glBindTexture(GL_TEXTURE_2D, 0);
	return (texture);
}

void	load_texture_to_obj(t_globj *obj, char *img_path)
{
	GLuint	texture;
	GLuint	*new_textures;
	int		i;
	char	error;

	texture = make_texture(img_path, &error);
	if (error)
		return (ft_putstr("could not load texture\n"));
	if (!(new_textures = (GLuint*)malloc(sizeof(GLuint)
												* (obj->nb_textures + 1))))
	{
		return (ft_putstr("malloc error, could not load texture\n"));
	}
	i = 0;
	while (i < obj->nb_textures)
	{
		new_textures[i] = obj->textures[i];
		i++;
	}
	new_textures[i] = texture;
	if (i > 0)
		free(obj->textures);
	obj->textures = new_textures;
	obj->has_textures = 1;
	obj->nb_textures++;
}

void	load_specular_map_to_obj(t_globj *obj, char *img_path)
{
	char	error;

	obj->specular_map = make_texture(img_path, &error);
	if (error)
		return ;
	obj->has_specular_map = 1;
}

void	load_normal_map_to_obj(t_globj *obj, char *img_path)
{
	char	error;

	obj->normal_map = make_texture(img_path, &error);
	if (error)
		return ;
	obj->has_normal_map = 1;
}
