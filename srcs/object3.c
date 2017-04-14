/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:59:39 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/03 13:59:41 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myopengl.h"

int		get_texture_nb2(int nb)
{
	if (nb == 8)
		return (GL_TEXTURE8);
	if (nb == 9)
		return (GL_TEXTURE9);
	if (nb == 10)
		return (GL_TEXTURE10);
	if (nb == 11)
		return (GL_TEXTURE11);
	if (nb == 12)
		return (GL_TEXTURE12);
	if (nb == 13)
		return (GL_TEXTURE13);
	if (nb == 14)
		return (GL_TEXTURE14);
	if (nb == 15)
		return (GL_TEXTURE15);
	return (0);
}

int		get_texture_nb(int nb)
{
	if (nb == 0)
		return (GL_TEXTURE0);
	if (nb == 1)
		return (GL_TEXTURE1);
	if (nb == 2)
		return (GL_TEXTURE2);
	if (nb == 3)
		return (GL_TEXTURE3);
	if (nb == 4)
		return (GL_TEXTURE4);
	if (nb == 5)
		return (GL_TEXTURE5);
	if (nb == 6)
		return (GL_TEXTURE6);
	if (nb == 7)
		return (GL_TEXTURE7);
	return (get_texture_nb2(nb));
}

int		int_arr_sum(int arr[], int nb)
{
	int		i;
	int		sum;

	sum = 0;
	i = 0;
	while (i < nb)
	{
		sum += arr[i];
		i++;
	}
	return (sum);
}

void	init_vertex_attributes(int attribs_struct[], int nb_attribs,
										int nb_vertices, size_t tot_data_len)
{
	int		i;
	int		seen_vars;

	seen_vars = 0;
	i = 0;
	while (i < nb_attribs)
	{
		glVertexAttribPointer(i, attribs_struct[i], GL_FLOAT, GL_FALSE,
		tot_data_len / nb_vertices, (GLvoid*)(seen_vars * sizeof(GLfloat)));
		glEnableVertexAttribArray(i);
		seen_vars += attribs_struct[i];
		i++;
	}
}
