

NAME		=	scop

SOURCES		=	srcs/shader_program.c \
				srcs/object.c \
				srcs/object2.c \
				srcs/object3.c \
				srcs/object_load_textures.c \
				srcs/main.c \
				srcs/main_loop.c \
				srcs/eyes.c \
				srcs/window.c \
				srcs/ft_itoa.c \
				srcs/matrices.c \
				srcs/matrices2.c \
				srcs/matrices3.c \
				srcs/matrices4.c \
				srcs/matrices5.c \
				srcs/matrices_invert.c \
				srcs/matrices_invert2.c \
				srcs/matrices_rotation.c \
				srcs/events.c \
				srcs/events2.c \
				srcs/events_obj_movement.c \
				srcs/camera.c \
				srcs/list.c \
				srcs/parse_face.c \
				srcs/parse_vertices.c \
				srcs/parse_vertices2.c \
				srcs/obj_parser.c \
				srcs/objfile_to_vertices.c \
				srcs/objfile_to_vertices2.c \
				srcs/objfile_to_vertices3.c \
				srcs/objfile_to_vertices4.c \
				srcs/objfile_to_vertices5.c \
				srcs/objfile_to_vertices6.c \
				srcs/normals.c \
				srcs/main_utils.c \
				srcs/main_utils2.c \
				srcs/main_utils3.c \
				srcs/draw_objs.c \
				srcs/draw_objs2.c \
				srcs/load_object_file.c \
				srcs/utils.c \
				srcs/utils2.c \
				srcs/environment.c \
				srcs/calc_tangent_bitangent.c \
				srcs/calc_tangent_bitangent2.c \
				srcs/make_std_light.c \
				srcs/make_std_light2.c \
				srcs/show_help.c \
				srcs/read_tga.c

OBJECTS	=	$(subst .c,.o,$(SOURCES))

WFLAGS	=	-Wall -Werror -Wextra -I includes -I ~/libSOIL

OS := $(shell uname)
ifneq ($(OS), Darwin)
FLAGS	=	-lSOIL -lGL -lGLU -lglut -lglfw3 -lX11 -lXxf86vm -lXrandr -pthread -lXi -ldl -lXinerama -lXcursor -lrt -lm -lGLEW
else
FLAGS	=	-framework OpenGL -lglfw -lGLEW -lSOIL
endif

CC		=	gcc

.SILENT:

$(NAME): $(OBJECTS)
	$(CC) $(WFLAGS) $(OBJECTS) -o $(NAME) $(FLAGS)
	printf "\e[32m----------------------------------\e[36m\n"
	printf "\e[32m[✔]\e[36m $@"
	printf "\n\e[32m----------------------------------\e[36m"
	printf "\033[0m\n"

all: $(NAME)

%.o: %.c
	$(CC) $(WFLAGS) -c -o $@ $^
	printf "\e[32m[✔]\e[36m $@ "
	printf "\033[0m\n"

clean:
	rm -Rf $(OBJECTS)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): Objects deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

fclean: clean
	rm -Rf $(NAME)
	printf "\e[31m----------------------------------\n"
	printf "[✔]\e[36m $(NAME): All deleted\n"
	printf "\e[31m----------------------------------\e[36m"
	printf "\033[0m\n"

re: fclean all

PHONY: re fclean clean all
