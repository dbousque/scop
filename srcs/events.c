/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:11:26 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 18:11:28 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void	do_movement3(GLfloat delta_time, t_list *objs, t_list *lights)
{
	(void)objs;
	(void)lights;
	if (g_keys[GLFW_KEY_KP_ADD])
	{
		((t_globj**)objs->elts)[0]->scale += delta_time
								* ((t_globj**)objs->elts)[0]->scale * 0.5;
	}
	if (g_keys[GLFW_KEY_KP_SUBTRACT])
	{
		((t_globj**)objs->elts)[0]->scale -= delta_time
								* ((t_globj**)objs->elts)[0]->scale * 0.5;
	}
	if (g_keys[GLFW_KEY_MINUS])
		g_cam.stereo_decal -= delta_time * 1.0;
	if (g_keys[GLFW_KEY_EQUAL])
		g_cam.stereo_decal += delta_time * 1.0;
	if (g_keys[GLFW_KEY_LEFT_BRACKET])
		g_cam.stereo_decal_front -= delta_time * 0.1;
	if (g_keys[GLFW_KEY_RIGHT_BRACKET])
		g_cam.stereo_decal_front += delta_time * 0.1;
	if (g_cam.stereo_decal_front < 0.0)
		g_cam.stereo_decal_front = 0.0;
	if (g_cam.stereo_decal < 0.0)
		g_cam.stereo_decal = 0.0;
	do_movement4(delta_time);
}

void	do_movement6(GLfloat delta_time, t_list *objs, t_list *lights)
{
	t_light		*sel_l;

	if (g_keys[GLFW_KEY_4] && g_conf.obj_ind > (int)objs->len)
	{
		sel_l = ((t_light**)lights->elts)[g_conf.obj_ind - (int)objs->len - 1];
		sel_l->r += 1.0 * delta_time;
		if (sel_l->r > 1.0)
			sel_l->r = 1.0;
	}
	if (g_keys[GLFW_KEY_5] && g_conf.obj_ind > (int)objs->len)
	{
		sel_l = ((t_light**)lights->elts)[g_conf.obj_ind - (int)objs->len - 1];
		sel_l->g += 1.0 * delta_time;
		if (sel_l->g > 1.0)
			sel_l->g = 1.0;
	}
	if (g_keys[GLFW_KEY_6] && g_conf.obj_ind > (int)objs->len)
	{
		sel_l = ((t_light**)lights->elts)[g_conf.obj_ind - (int)objs->len - 1];
		sel_l->b += 1.0 * delta_time;
		if (sel_l->b > 1.0)
			sel_l->b = 1.0;
	}
	do_movement3(delta_time, objs, lights);
}

void	do_movement5(GLfloat delta_time, t_list *objs, t_list *lights)
{
	t_light		*sel_l;

	if (g_keys[GLFW_KEY_1] && g_conf.obj_ind > (int)objs->len)
	{
		sel_l = ((t_light**)lights->elts)[g_conf.obj_ind - (int)objs->len - 1];
		sel_l->r -= 1.0 * delta_time;
		if (sel_l->r < 0.0)
			sel_l->r = 0.0;
	}
	if (g_keys[GLFW_KEY_2] && g_conf.obj_ind > (int)objs->len)
	{
		sel_l = ((t_light**)lights->elts)[g_conf.obj_ind - (int)objs->len - 1];
		sel_l->g -= 1.0 * delta_time;
		if (sel_l->g < 0.0)
			sel_l->g = 0.0;
	}
	if (g_keys[GLFW_KEY_3] && g_conf.obj_ind > (int)objs->len)
	{
		sel_l = ((t_light**)lights->elts)[g_conf.obj_ind - (int)objs->len - 1];
		sel_l->b -= 1.0 * delta_time;
		if (sel_l->b < 0.0)
			sel_l->b = 0.0;
	}
	do_movement6(delta_time, objs, lights);
}

void	do_movement2(GLfloat delta_time, t_list *objs, t_list *lights)
{
	if (g_conf.generic_textures_ind >= 4)
		g_conf.generic_textures_ind = 0;
	((t_globj**)objs->elts)[objs->len - 1] =
						g_conf.generic_textures[g_conf.generic_textures_ind];
	if (g_keys[GLFW_KEY_Z])
		g_cam.fov += 80.0 * g_cam.speed * delta_time;
	if (g_keys[GLFW_KEY_X])
		g_cam.fov -= 80.0 * g_cam.speed * delta_time;
	if (g_keys[GLFW_KEY_C])
		g_cam.roll -= 20 * g_cam.speed * delta_time;
	if (g_keys[GLFW_KEY_V])
		g_cam.roll += 20 * g_cam.speed * delta_time;
	if (g_keys[GLFW_KEY_UP])
		g_cam.pitch += 20 * g_cam.speed * delta_time;
	if (g_keys[GLFW_KEY_DOWN])
		g_cam.pitch -= 20 * g_cam.speed * delta_time;
	if (g_keys[GLFW_KEY_RIGHT])
		g_cam.yaw += 20 * g_cam.speed * delta_time;
	if (g_keys[GLFW_KEY_LEFT])
		g_cam.yaw -= 20 * g_cam.speed * delta_time;
	do_movement5(delta_time, objs, lights);
}

void	do_movement(GLfloat delta_time, t_list *objs, t_list *lights)
{
	t_globj		*sel_obj;
	t_light		*light;

	if (g_conf.obj_ind > (int)(objs->len + lights->len))
		g_conf.obj_ind = 0;
	obj_movement(delta_time, objs, lights);
	if (g_keys[GLFW_KEY_M])
	{
		if (g_conf.obj_ind > 0 && (size_t)g_conf.obj_ind <= objs->len)
		{
			sel_obj = ((t_globj**)objs->elts)[g_conf.obj_ind - 1];
			sel_obj->normal_mode = sel_obj->normal_mode == 0 ? 1 : 0;
		}
		g_keys[GLFW_KEY_M] = 0;
	}
	if (g_keys[GLFW_KEY_P] && lights->len < 10)
	{
		if ((light = new_std_light(1.0, 1.0, 1.0, 0.2)))
		{
			attach_shader_program_to_obj(light->obj, g_light_program);
			add_to_list(lights, &light);
		}
		g_keys[GLFW_KEY_P] = 0;
	}
	do_movement2(delta_time, objs, lights);
}
