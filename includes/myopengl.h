/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myopengl.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbousque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:06:46 by dbousque          #+#    #+#             */
/*   Updated: 2017/03/02 17:06:48 by dbousque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYOPENGL_H
# define MYOPENGL_H

# define GLEW_STATIC
# include <GL/glew.h>
# include <GLFW/glfw3.h>
# ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <GLUT/glut.h>
#  include <OpenGL/glu.h>
# endif
# include <SOIL/SOIL.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "matrices.h"

# define MAX_SHADER_SIZE 	32768
# define READ_BUFFER_LEN 	4096

typedef struct			s_shader_program
{
	GLuint				vertex_shader;
	GLuint				fragment_shader;
	GLuint				program;
}						t_shader_program;

typedef struct			s_globj
{
	GLuint				vao1;
	GLuint				vbo1;
	GLuint				ebo1;
	GLuint				vao2;
	GLuint				vbo2;
	GLuint				ebo2;
	char				normal_mode;
	int					nb_vertices;
	int					nb_indices;
	char				has_indices;
	char				has_textures;
	GLuint				*textures;
	int					nb_textures;
	t_shader_program	*shader;
	float				x;
	float				y;
	float				z;
	GLuint				specular_map;
	GLuint				normal_map;
	char				has_specular_map;
	char				has_normal_map;
	float				specular_strength;
	float				scale;
}						t_globj;

typedef struct			s_window
{
	GLFWwindow			*win;
}						t_window;

typedef struct			s_camera
{
	float				x;
	float				y;
	float				z;
	float				front_x;
	float				front_y;
	float				front_z;
	float				up_x;
	float				up_y;
	float				up_z;
	float				speed;
	float				fov;
	float				pitch;
	float				yaw;
	float				roll;
	float				stereo_decal_front;
	float				stereo_decal;
}						t_camera;

typedef struct			s_list
{
	void				*elts;
	size_t				size;
	size_t				len;
	size_t				elt_size;
}						t_list;

typedef struct			s_objfile
{
	char				*objname;
	t_list				*vertices;
	t_list				*texture;
	t_list				*normals;
	t_list				*faces;
	t_list				*calc_normals;
}						t_objfile;

typedef struct			s_config
{
	char				lines;
	int					win_width;
	int					win_height;
	int					obj_ind;
	float				info_updated_at;
	float				time_spent;
	int					frames_seen;
	char				normal_mode;
	float				texture_strength;
	float				colors_strength;
	char				texture_plus;
	char				colors_plus;
	float				red_strength;
	float				green_strength;
	float				blue_strength;
	GLuint				left_eye_framebuffer;
	GLuint				right_eye_framebuffer;
	GLuint				left_eye_texture;
	GLuint				right_eye_texture;
	GLuint				left_eye_depthbuffer;
	GLuint				right_eye_depthbuffer;
	t_globj				*quad;
	char				stereoscopic;
	t_globj				*generic_textures[4];
	int					generic_textures_ind;
}						t_config;

typedef struct			s_light
{
	t_globj				*obj;
	float				r;
	float				g;
	float				b;
	float				ambient_strength;
}						t_light;

typedef struct			s_solve_text_coords_params
{
	t_list				**vertex_in_faces;
	char				*vertex_text_already_set;
	float				scale;
	int					top_left_vertex;
}						t_solve_text_coords_params;

t_camera				g_cam;
char					g_keys[1024];
t_config				g_conf;
t_shader_program		*g_obj_program;
t_shader_program		*g_light_program;
t_shader_program		*g_merge_program;

t_list					*new_list(size_t elt_size);
void					add_to_list(t_list *lst, void *elt);
size_t					ft_strlen(char *str);
char					startswith(char *str, char *begin);
void					ft_putstr(char *str);
char					*ft_itoa(int n);
char					*ft_strconcat(char *st1, char *st2);
char					*read_file(char *filename, size_t max_size);
void					front_up_cross(float *x, float *y, float *z);
void					obj_movement(GLfloat delta_time, t_list *objs,
															t_list *lights);
void					key_callback(GLFWwindow *window, int key, int scancode,
														int action, int mode);

void					calculate_raw_normals(GLfloat *v, int nb_vertices);
t_shader_program		*new_shader_program(char *vertex_shader_path,
												char *fragment_shader_path);
t_window				*setup_window(int width, int height, char *title_name);
void					draw_object(t_shader_program *shader_program,
																t_globj *obj);
t_globj					*new_object(GLfloat *vertices, int nb_vertices,
										int attribs_struct[], int nb_attribs);
void					load_texture_to_obj(t_globj *obj, char *img_path);
void					attach_indices_to_obj(t_globj *obj, GLuint indices[],
															int nb_indices);
void					attach_shader_program_to_obj(t_globj *obj,
													t_shader_program *shader);
t_objfile				*parse_objfile(char *path);
char					add_vertex(t_objfile *objfile, char *line,
															size_t line_nb);
char					add_face(t_objfile *objfile, char *line,
															size_t line_nb);
void					update_camera(void);
void					init_camera(void);
void					do_movement(GLfloat delta_time, t_list *objs,
															t_list *lights);
void					key_callback(GLFWwindow *window, int key, int scancode,
														int action, int mode);
void					setup_keys(void);
char					objfile_to_vertices(t_objfile *objfile,
										GLfloat **vertices, int *nb_vertices);
char					valid_int(char *line, char **end);
char					add_normal(t_objfile *objfile, char *line,
															size_t line_nb);
char					add_texture(t_objfile *objfile, char *line,
															size_t line_nb);
void					set_lights(t_list *objs, t_list *lights,
								float texture_strength, float colors_strength);
void					set_obj_color(t_shader_program *shader);
t_light					*new_std_light(float r, float g, float b,
													float ambient_strength);
float					adjust_obj(GLfloat *vertices, int nb_vertices);
t_mat					*build_view(void);
void					setup_conf(void);
void					draw_lights(t_list *lights, t_mat *view,
															t_mat *projection);
void					draw_objects(t_list *objs, t_mat *view,
															t_mat *projection);
t_globj					*new_obj_from_path(char *path, char main_obj);
void					update_stats(void);
void					load_specular_map_to_obj(t_globj *obj, char *img_path);
void					load_normal_map_to_obj(t_globj *obj, char *img_path);
void					front_up_cross(float *x, float *y, float *z);
char					load_object_file(char *filename, t_list *objs);
void					do_movement4(GLfloat delta_time);
void					main_loop(t_window *window, t_list *objs,
															t_list *lights);
void					setup_eyes(void);
void					set_right_eye(void);
void					set_left_eye(void);
void					add_environment(t_list *objs);
void					calc_tangent_bitangent(GLfloat *vertices,
															int nb_vertices);
void					calc_tangent_bitangent_triangle4(GLfloat *vertices,
											int i, float r, float *deltas[4]);
void					calc_tangent_bitangent_triangle3(GLfloat *vertices,
											int i, float r, float *deltas[4]);
void					calc_tangent_bitangent_triangle2(GLfloat *vertices,
											int i, float r, float *deltas[4]);
void					calc_tangent_bitangent_triangle1(GLfloat *vertices,
											int i, float *deltas[4]);
float					max(float f1, float f2);
int						get_texture_nb(int nb);
void					init_vertex_attributes(int attribs_struct[],
						int nb_attribs, int nb_vertices, size_t tot_data_len);
int						int_arr_sum(int arr[], int nb);
void					solve_text_coords(t_objfile *objfile,
			t_solve_text_coords_params *params, float x_text, float y_text);
char					generate_texture_coords2(t_objfile *objfile);
void					get_text_xy(t_objfile *objfile, int known_unkown_ind[2],
												float res_xy[2], float scale);
void					set_new_params(t_solve_text_coords_params *params,
					t_solve_text_coords_params *new_params, int new_top_left);
void					set_vertex_in_faces(t_objfile *objfile,
													t_list **vertex_in_faces);
char					find_top_left(t_objfile *objfile, int *top_left_vertex,
								float *scale, char *vertex_text_already_set);
char					find_top_left_cond1(float *v, int *f, size_t i,
																float tl[4]);
void					second_pass_add_normals(t_objfile *objfile,
														GLfloat **vertices);
void					set_normal(t_objfile *objfile, GLfloat **vertices,
											size_t faces_ind, size_t res_ind);
void					set_vertex(t_objfile *objfile, GLfloat **vertices,
											size_t faces_ind, size_t res_ind);
void					add_normal2(t_objfile *objfile, size_t f_i, int decal);
char					create_calc_normals(t_objfile *objfile,
															int *nb_vertices);
char					valid_faces(t_objfile *objfile, int *nb_vertices);
char					return_face_error(char *msg, char *line,
															size_t line_nb);
char					valid_float(char *line, char **end);
char					return_vertex_error(char *msg, char *line,
															size_t line_nb);
void					make_std_light_vertices(GLfloat vertices[], float r,
															float g, float b);
void					make_std_light_vertices6(GLfloat vertices[], float r,
															float g, float b);
void					make_std_light_vertices7(GLfloat vertices[], float r,
															float g, float b);
void					make_std_light_vertices8(GLfloat vertices[], float r,
															float g, float b);
void					make_std_light_vertices9(GLfloat vertices[], float r,
															float g, float b);
void					make_std_light_vertices10(GLfloat vertices[], float r,
															float g, float b);
void					show_help(void);
char					endswith(char *str, char *end);
char					*read_tga(char *path, int *width, int *height);

#endif
