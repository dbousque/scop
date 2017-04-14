/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 19:23:29 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 19:23:30 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void	setup_keys(void)
{
	int		i;

	i = 0;
	while (i < 1024)
	{
		g_keys[i] = 0;
		i++;
	}
}

void	key_callback2(GLFWwindow *window, int key, int action)
{
	if (key == GLFW_KEY_N && action == GLFW_PRESS)
		g_conf.obj_ind++;
	if (key == GLFW_KEY_M && action == GLFW_PRESS)
		g_conf.normal_mode = g_conf.normal_mode == 0 ? 1 : 0;
	if (key == GLFW_KEY_T && action == GLFW_PRESS)
	{
		if (!g_conf.texture_plus && !g_conf.colors_plus)
			g_conf.colors_plus = 1;
		else if (g_conf.colors_plus)
		{
			g_conf.colors_plus = 0;
			g_conf.texture_plus = 1;
		}
		else if (g_conf.texture_plus)
			g_conf.texture_plus = 0;
	}
	if (key == GLFW_KEY_G && action == GLFW_PRESS)
		g_conf.generic_textures_ind++;
	if (key == GLFW_KEY_J && action == GLFW_PRESS)
		g_conf.stereoscopic = g_conf.stereoscopic ? 0 : 1;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

void	key_callback(GLFWwindow *window, int key, int scancode, int action,
																	int mode)
{
	(void)scancode;
	(void)mode;
	if (action == GLFW_PRESS)
		g_keys[key] = 1;
	if (action == GLFW_RELEASE)
		g_keys[key] = 0;
	if (key == GLFW_KEY_L && action == GLFW_PRESS)
	{
		if (g_conf.lines)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			g_conf.lines = 0;
		}
		else
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			g_conf.lines = 1;
		}
	}
	key_callback2(window, key, action);
}

void	do_movement4(GLfloat delta_time)
{
	if (g_conf.texture_plus)
	{
		g_conf.texture_strength += 1.0 * delta_time;
		if (g_conf.texture_strength > 1.0)
			g_conf.texture_strength = 1.0;
	}
	else
	{
		g_conf.texture_strength -= 1.0 * delta_time;
		if (g_conf.texture_strength < 0.0)
			g_conf.texture_strength = 0.0;
	}
	if (g_conf.colors_plus)
	{
		g_conf.colors_strength += 1.0 * delta_time;
		if (g_conf.colors_strength > 1.0)
			g_conf.colors_strength = 1.0;
	}
	else
	{
		g_conf.colors_strength -= 1.0 * delta_time;
		if (g_conf.colors_strength < 0.0)
			g_conf.colors_strength = 0.0;
	}
}
