/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:51:08 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 17:51:10 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

void	show_help(void)
{
	ft_putstr("format : ./scop <object_file>\n\n");
	ft_putstr("move :                            WASD\n");
	ft_putstr("move up/down :                    E/Q\n");
	ft_putstr("move view :                       arrow keys\n");
	ft_putstr("main object change size :         keypad +/-\n");
	ft_putstr("zoom in/out :                     X/Z\n");
	ft_putstr("textures switch :                 T\n");
	ft_putstr("scenery switch :                  G\n");
	ft_putstr("make new light source :           P\n");
	ft_putstr("reduce RGB of current light :     1/2/3\n");
	ft_putstr("increase RGB of current light :   4/5/6\n");
	ft_putstr("change selected object :          N\n");
	ft_putstr("smoothed normals on/off :         M\n");
	ft_putstr("stereoscopic 3D on/off :          J\n");
	ft_putstr("distance between eyes :           -/+\n");
	ft_putstr("move convergence point :          {/}\n");
	ft_putstr("exit :                            ESC\n");
}
