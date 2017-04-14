/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:06:34 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 17:06:41 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>

typedef struct	s_mat
{
	float		*elts;
	int			nb_rows;
	int			nb_columns;
}				t_mat;

typedef t_mat	t_vec;

t_mat			*new_mat(int nb_rows, int nb_columns);
t_mat			*new_mat2();
t_mat			*new_mat3();
t_mat			*new_mat4();
t_vec			*new_vec(int n);
t_vec			*new_vec2(float elt1, float elt2);
t_vec			*new_vec3(float elt1, float elt2, float elt3);
t_vec			*new_vec4(float elt1, float elt2, float elt3, float elt4);
t_vec			*vec3_normalize(t_vec *vec);
float			get_norm(float x, float y, float z);
t_vec			*vec3_sub(t_vec *vec1, t_vec *vec2);
t_vec			*vec3_cross(t_vec *vec1, t_vec *vec2);
t_mat			*mat_mult(t_mat *mat1, t_mat *mat2);
t_mat			*translate(t_vec *vec);
t_mat			*scale(t_vec *vec);
t_mat			*rotate(t_vec *rotate);
t_mat			*invert(t_mat *inp);
t_mat			*transpose(t_mat *inp);
t_mat			*perspective(float fov, float ratio, float near, float far);
float			deg_to_rad(float deg);
void			print_mat(t_mat *mat);
t_mat			*invert5(float *m, t_mat *res_inv, float *inv);

#endif
