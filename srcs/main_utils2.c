/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:58:05 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 13:58:07 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void	setup_conf(void)
{
	g_conf.lines = 0;
	g_conf.win_width = 1400;
	g_conf.win_height = 900;
	g_conf.obj_ind = 0;
	g_conf.normal_mode = 0;
	g_conf.texture_strength = 0.0;
	g_conf.texture_plus = 0;
	g_conf.colors_strength = 0.0;
	g_conf.colors_plus = 0;
	g_conf.red_strength = 1.0;
	g_conf.green_strength = 0.72;
	g_conf.blue_strength = 1.0;
	g_conf.stereoscopic = 0;
	g_conf.generic_textures_ind = 0;
}

t_mat	*build_view2(t_vec *camera_right, t_vec *camera_up,
								t_vec *camera_direction, t_vec *camera_pos)
{
	t_mat	*tmp1;
	t_mat	*tmp2;

	tmp1 = new_mat4();
	tmp1->elts[0] = camera_right->elts[0];
	tmp1->elts[1] = camera_right->elts[1];
	tmp1->elts[2] = camera_right->elts[2];
	tmp1->elts[4] = camera_up->elts[0];
	tmp1->elts[5] = camera_up->elts[1];
	tmp1->elts[6] = camera_up->elts[2];
	tmp1->elts[8] = camera_direction->elts[0];
	tmp1->elts[9] = camera_direction->elts[1];
	tmp1->elts[10] = camera_direction->elts[2];
	tmp2 = new_mat4();
	tmp2->elts[3] = -(camera_pos->elts[0]);
	tmp2->elts[7] = -(camera_pos->elts[1]);
	tmp2->elts[11] = -(camera_pos->elts[2]);
	return (mat_mult(tmp1, tmp2));
}

t_mat	*build_view(void)
{
	t_vec	*camera_pos;
	t_vec	*camera_target;
	t_vec	*camera_direction;
	t_vec	*up;
	t_vec	*camera_right;

	camera_pos = new_vec3(g_cam.x, g_cam.y, g_cam.z);
	camera_target = new_vec3(g_cam.x + g_cam.front_x, g_cam.y + g_cam.front_y,
													g_cam.z + g_cam.front_z);
	camera_direction = vec3_normalize(vec3_sub(camera_pos, camera_target));
	up = new_vec3(g_cam.up_x, g_cam.up_y, g_cam.up_z);
	camera_right = vec3_normalize(vec3_cross(up, camera_direction));
	return (build_view2(camera_right,
						vec3_cross(camera_direction, camera_right),
						camera_direction,
						camera_pos));
}

void	generate_texture_coords(GLfloat *vertices, int nb_vertices)
{
	int		i;

	i = 0;
	while (i < nb_vertices)
	{
		vertices[i * 17 + 3] = vertices[i * 17 + 0] + vertices[i * 17 + 2];
		vertices[i * 17 + 4] = vertices[i * 17 + 1] + vertices[i * 17 + 2];
		i++;
	}
}

float	max(float f1, float f2)
{
	return (f1 >= f2 ? f1 : f2);
}
