/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:11:07 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 18:11:09 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void	init_camera(void)
{
	g_cam.x = 0.0;
	g_cam.y = 0.0;
	g_cam.z = 4.5;
	g_cam.front_x = 0.0;
	g_cam.front_y = 0.0;
	g_cam.front_z = -1.0;
	g_cam.up_x = 0.0;
	g_cam.up_y = 1.0;
	g_cam.up_z = 0.0;
	g_cam.speed = 4.0;
	g_cam.fov = -10.0;
	g_cam.pitch = 0.0;
	g_cam.yaw = -90.0;
	g_cam.roll = 0.0;
	g_cam.stereo_decal = 0.16;
	g_cam.stereo_decal_front = 0.030;
}

void	update_camera2(void)
{
	float	norm;

	g_cam.front_x = cosf(deg_to_rad(g_cam.yaw)) * cos(deg_to_rad(g_cam.pitch));
	g_cam.front_y = sinf(deg_to_rad(g_cam.pitch));
	g_cam.front_z = sinf(deg_to_rad(g_cam.yaw)) * cos(deg_to_rad(g_cam.pitch));
	norm = get_norm(g_cam.front_x, g_cam.front_y, g_cam.front_z);
	g_cam.front_x /= norm;
	g_cam.front_y /= norm;
	g_cam.front_z /= norm;
	g_cam.up_x = sinf(deg_to_rad(g_cam.roll));
	g_cam.up_y = cosf(deg_to_rad(g_cam.roll));
	norm = get_norm(g_cam.up_x, g_cam.up_y, g_cam.up_z);
	g_cam.up_x /= norm;
	g_cam.up_y /= norm;
}

void	update_camera(void)
{
	if (g_cam.fov > 50.0)
		g_cam.fov = 50.0;
	if (g_cam.fov < -150.0)
		g_cam.fov = -150.0;
	if (g_cam.pitch > 89.0)
		g_cam.pitch = 89.0;
	if (g_cam.pitch < -89.0)
		g_cam.pitch = -89.0;
	if (g_cam.roll > 89.0)
		g_cam.roll = 89.0;
	if (g_cam.roll < -89.0)
		g_cam.roll = -89.0;
	update_camera2();
}
