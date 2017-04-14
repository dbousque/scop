/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:11:45 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 18:11:46 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

GLfloat		g_quad_vertices[] = {
	-1.0f, 1.0f, 0.0f, 1.0f,
	-1.0f, -1.0f, 0.0f, 0.0f,
	1.0f, -1.0f, 1.0f, 0.0f,
	-1.0f, 1.0f, 0.0f, 1.0f,
	1.0f, -1.0f, 1.0f, 0.0f,
	1.0f, 1.0f, 1.0f, 1.0f
};

t_globj		*make_screen_quad(void)
{
	t_globj	*quad;
	int		nb_vertices;
	int		attribs_struct[2];
	int		nb_attribs;

	nb_vertices = 6;
	attribs_struct[0] = 2;
	attribs_struct[1] = 2;
	nb_attribs = 2;
	if (!(quad = new_object(g_quad_vertices, nb_vertices,
											attribs_struct, nb_attribs)))
		return (NULL);
	return (quad);
}

char		init_shaders(void)
{
	g_obj_program = new_shader_program("shaders/test1.vs", "shaders/test1.fs");
	if (!g_obj_program)
		return (0);
	g_light_program = new_shader_program("shaders/light.vs",
														"shaders/light.fs");
	if (!g_light_program)
		return (0);
	g_merge_program = new_shader_program("shaders/merge_stereo.vs",
													"shaders/merge_stereo.fs");
	if (!g_merge_program)
		return (0);
	return (1);
}

int			main2(char **argv, t_window *window, t_list *objs, t_list *lights)
{
	t_light				*light;

	if (!load_object_file(argv[1], objs))
	{
		printf("could not load .object file %s\n", argv[1]);
		return (-1);
	}
	add_environment(objs);
	light = new_std_light(1.0, 1.0, 1.0, 0.2);
	if (!light)
		return (-1);
	attach_shader_program_to_obj(light->obj, g_light_program);
	add_to_list(lights, &light);
	g_conf.quad = make_screen_quad();
	if (!g_conf.quad)
		return (-1);
	attach_shader_program_to_obj(g_conf.quad, g_merge_program);
	g_conf.info_updated_at = glfwGetTime();
	g_conf.frames_seen = 0;
	g_conf.time_spent = 0.0;
	setup_eyes();
	main_loop(window, objs, lights);
	return (0);
}

int			main(int argc, char **argv)
{
	t_window			*window;
	t_list				*objs;
	t_list				*lights;

	if (argc != 2)
	{
		show_help();
		return (-1);
	}
	setup_keys();
	setup_conf();
	init_camera();
	window = setup_window(g_conf.win_width, g_conf.win_height,
															"scop - dbousque");
	if (!window)
		return (-1);
	glEnable(GL_DEPTH_TEST);
	if (!init_shaders())
		return (-1);
	objs = new_list(sizeof(t_globj*));
	lights = new_list(sizeof(t_light*));
	return (main2(argv, window, objs, lights));
}
