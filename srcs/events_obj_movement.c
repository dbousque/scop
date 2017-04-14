/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_obj_movement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 19:21:40 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 19:21:42 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void		obj_movement4(GLfloat delta_time, t_globj *obj)
{
	if (g_keys[GLFW_KEY_E])
	{
		if (g_conf.obj_ind == 0)
			g_cam.y += 2.0 * g_cam.speed * delta_time;
		else
			obj->y += 2.0 * g_cam.speed * delta_time;
	}
	if (g_keys[GLFW_KEY_Q])
	{
		if (g_conf.obj_ind == 0)
			g_cam.y -= 2.0 * g_cam.speed * delta_time;
		else
			obj->y -= 2.0 * g_cam.speed * delta_time;
	}
}

void		obj_movement3(GLfloat delta_time, t_globj *obj)
{
	if (g_keys[GLFW_KEY_W])
	{
		if (g_conf.obj_ind == 0)
		{
			g_cam.x += g_cam.speed * g_cam.front_x * delta_time;
			g_cam.y += g_cam.speed * g_cam.front_y * delta_time;
			g_cam.z += g_cam.speed * g_cam.front_z * delta_time;
		}
		else
			obj->z -= 2.0 * g_cam.speed * delta_time;
	}
	if (g_keys[GLFW_KEY_S])
	{
		if (g_conf.obj_ind == 0)
		{
			g_cam.x -= g_cam.speed * g_cam.front_x * delta_time;
			g_cam.y -= g_cam.speed * g_cam.front_y * delta_time;
			g_cam.z -= g_cam.speed * g_cam.front_z * delta_time;
		}
		else
			obj->z += 2.0 * g_cam.speed * delta_time;
	}
	obj_movement4(delta_time, obj);
}

void		obj_movement2(GLfloat delta_time, t_globj *obj)
{
	float		norm;
	float		tmp_x;
	float		tmp_y;
	float		tmp_z;

	if (g_keys[GLFW_KEY_D])
	{
		if (g_conf.obj_ind == 0)
		{
			front_up_cross(&tmp_x, &tmp_y, &tmp_z);
			norm = get_norm(tmp_x, tmp_y, tmp_z);
			g_cam.x += tmp_x / norm * g_cam.speed * delta_time;
			g_cam.y += tmp_y / norm * g_cam.speed * delta_time;
			g_cam.z += tmp_z / norm * g_cam.speed * delta_time;
		}
		else
			obj->x += 2.0 * g_cam.speed * delta_time;
	}
	obj_movement3(delta_time, obj);
}

t_globj		*get_right_obj(t_list *objs, t_list *lights)
{
	if (g_conf.obj_ind <= (int)objs->len)
		return (((t_globj**)objs->elts)[g_conf.obj_ind - 1]);
	return (((t_light**)lights->elts)[g_conf.obj_ind - 1 - objs->len]->obj);
}

void		obj_movement(GLfloat delta_time, t_list *objs, t_list *lights)
{
	float		norm;
	float		tmp_x;
	float		tmp_y;
	float		tmp_z;
	t_globj		*obj;

	obj = NULL;
	if (g_conf.obj_ind > 0)
		obj = get_right_obj(objs, lights);
	if (g_keys[GLFW_KEY_A])
	{
		if (g_conf.obj_ind == 0)
		{
			front_up_cross(&tmp_x, &tmp_y, &tmp_z);
			norm = get_norm(tmp_x, tmp_y, tmp_z);
			g_cam.x -= tmp_x / norm * g_cam.speed * delta_time;
			g_cam.y -= tmp_y / norm * g_cam.speed * delta_time;
			g_cam.z -= tmp_z / norm * g_cam.speed * delta_time;
		}
		else
			obj->x -= 2.0 * g_cam.speed * delta_time;
	}
	obj_movement2(delta_time, obj);
}
