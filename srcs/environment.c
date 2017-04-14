/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:56:27 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 13:56:28 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void		add_environment3(void)
{
	g_conf.generic_textures[3] = new_obj_from_path(
								"environment/plate/plate.obj", 0);
	if (!g_conf.generic_textures[3])
		return ;
	load_texture_to_obj(g_conf.generic_textures[3],
											"environment/plate/diff.jpg");
	load_specular_map_to_obj(g_conf.generic_textures[3],
											"environment/plate/spec.jpg");
	load_normal_map_to_obj(g_conf.generic_textures[3],
											"environment/plate/normal.jpg");
	attach_shader_program_to_obj(g_conf.generic_textures[3], g_obj_program);
	g_conf.generic_textures[3]->specular_strength = 10.5;
	g_conf.generic_textures[3]->y = -2.0;
	g_conf.generic_textures[3]->scale = 7.0;
}

void		add_environment2(void)
{
	g_conf.generic_textures[2] = new_obj_from_path(
								"environment/parquet2/parquet2.obj", 0);
	if (!g_conf.generic_textures[2])
		return ;
	load_texture_to_obj(g_conf.generic_textures[2],
											"environment/parquet2/diff.jpg");
	load_specular_map_to_obj(g_conf.generic_textures[2],
											"environment/parquet2/spec.jpg");
	load_normal_map_to_obj(g_conf.generic_textures[2],
											"environment/parquet2/normal.jpg");
	attach_shader_program_to_obj(g_conf.generic_textures[2], g_obj_program);
	g_conf.generic_textures[2]->specular_strength = 5.5;
	g_conf.generic_textures[2]->y = -2.0;
	g_conf.generic_textures[2]->scale = 7.0;
	add_environment3();
}

void		add_environment1(void)
{
	g_conf.generic_textures[1] = new_obj_from_path(
								"environment/wall2/wall2.obj", 0);
	if (!g_conf.generic_textures[1])
		return ;
	load_texture_to_obj(g_conf.generic_textures[1],
											"environment/wall2/diff.png");
	load_specular_map_to_obj(g_conf.generic_textures[1],
											"environment/wall2/spec.png");
	load_normal_map_to_obj(g_conf.generic_textures[1],
											"environment/wall2/normal.png");
	attach_shader_program_to_obj(g_conf.generic_textures[1], g_obj_program);
	g_conf.generic_textures[1]->specular_strength = 1.5;
	g_conf.generic_textures[1]->y = -2.0;
	g_conf.generic_textures[1]->scale = 7.0;
	add_environment2();
}

void		add_environment(t_list *objs)
{
	g_conf.generic_textures[0] = new_obj_from_path(
								"environment/parquet/parquet.obj", 0);
	if (!g_conf.generic_textures[0])
		return ;
	load_texture_to_obj(g_conf.generic_textures[0],
											"environment/parquet/diff.png");
	load_specular_map_to_obj(g_conf.generic_textures[0],
											"environment/parquet/spec.png");
	load_normal_map_to_obj(g_conf.generic_textures[0],
											"environment/parquet/normal.png");
	attach_shader_program_to_obj(g_conf.generic_textures[0], g_obj_program);
	g_conf.generic_textures[0]->specular_strength = 3.5;
	g_conf.generic_textures[0]->y = -2.0;
	g_conf.generic_textures[0]->scale = 7.0;
	add_to_list(objs, &(g_conf.generic_textures[0]));
	add_environment1();
}
