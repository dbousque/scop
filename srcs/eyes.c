/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eyes.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:56:58 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 13:57:00 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void		setup_left_eye(void)
{
	GLenum	draw_buffers[1];

	glGenFramebuffers(1, &(g_conf.left_eye_framebuffer));
	glBindFramebuffer(GL_FRAMEBUFFER, g_conf.left_eye_framebuffer);
	glGenTextures(1, &(g_conf.left_eye_texture));
	glBindTexture(GL_TEXTURE_2D, g_conf.left_eye_texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, g_conf.win_width, g_conf.win_height,
											0, GL_RGB, GL_UNSIGNED_BYTE, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glGenRenderbuffers(1, &(g_conf.left_eye_depthbuffer));
	glBindRenderbuffer(GL_RENDERBUFFER, g_conf.left_eye_depthbuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT,
										g_conf.win_width, g_conf.win_height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
								GL_RENDERBUFFER, g_conf.left_eye_depthbuffer);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
												g_conf.left_eye_texture, 0);
	draw_buffers[0] = GL_COLOR_ATTACHMENT0;
	glDrawBuffers(1, draw_buffers);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		printf("Could not launch stereoscopic 3d.\n");
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void		setup_right_eye(void)
{
	GLenum	draw_buffers[1];

	glGenFramebuffers(1, &(g_conf.right_eye_framebuffer));
	glBindFramebuffer(GL_FRAMEBUFFER, g_conf.right_eye_framebuffer);
	glGenTextures(1, &(g_conf.right_eye_texture));
	glBindTexture(GL_TEXTURE_2D, g_conf.right_eye_texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, g_conf.win_width, g_conf.win_height,
											0, GL_RGB, GL_UNSIGNED_BYTE, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glGenRenderbuffers(1, &(g_conf.right_eye_depthbuffer));
	glBindRenderbuffer(GL_RENDERBUFFER, g_conf.right_eye_depthbuffer);
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT,
										g_conf.win_width, g_conf.win_height);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,
								GL_RENDERBUFFER, g_conf.right_eye_depthbuffer);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0,
												g_conf.right_eye_texture, 0);
	draw_buffers[0] = GL_COLOR_ATTACHMENT0;
	glDrawBuffers(1, draw_buffers);
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		printf("Could not launch stereoscopic 3d.\n");
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void		setup_eyes(void)
{
	g_conf.left_eye_framebuffer = 0;
	setup_left_eye();
	g_conf.right_eye_framebuffer = 0;
	setup_right_eye();
}

void		set_left_eye(void)
{
	float	tmp_x;
	float	tmp_y;
	float	tmp_z;
	float	norm;

	if (g_conf.stereoscopic)
	{
		front_up_cross(&tmp_x, &tmp_y, &tmp_z);
		norm = get_norm(tmp_x, tmp_y, tmp_z);
		g_cam.x -= tmp_x / norm * g_cam.stereo_decal * 0.5;
		g_cam.y -= tmp_y / norm * g_cam.stereo_decal * 0.5;
		g_cam.z -= tmp_z / norm * g_cam.stereo_decal * 0.5;
	}
	glBindFramebuffer(GL_FRAMEBUFFER, g_conf.left_eye_framebuffer);
	glBindTexture(GL_TEXTURE_2D, g_conf.left_eye_texture);
	glBindRenderbuffer(GL_RENDERBUFFER, g_conf.left_eye_depthbuffer);
	glViewport(0, 0, g_conf.win_width, g_conf.win_height);
}

void		set_right_eye(void)
{
	float	tmp_x;
	float	tmp_y;
	float	tmp_z;
	float	norm;

	if (g_conf.stereoscopic)
	{
		front_up_cross(&tmp_x, &tmp_y, &tmp_z);
		norm = get_norm(tmp_x, tmp_y, tmp_z);
		g_cam.x += tmp_x / norm * g_cam.stereo_decal * 0.5;
		g_cam.y += tmp_y / norm * g_cam.stereo_decal * 0.5;
		g_cam.z += tmp_z / norm * g_cam.stereo_decal * 0.5;
	}
	glBindFramebuffer(GL_FRAMEBUFFER, g_conf.right_eye_framebuffer);
	glBindTexture(GL_TEXTURE_2D, g_conf.right_eye_texture);
	glBindRenderbuffer(GL_RENDERBUFFER, g_conf.right_eye_depthbuffer);
	glViewport(0, 0, g_conf.win_width, g_conf.win_height);
}
