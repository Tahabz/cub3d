FLAGS = -Wall -Wextra -Werror
DFLAGS = -g -g3 -fsanitize=address
CC = gcc
SRCS =	srcs/ft_putchar.c \
		srcs/ft_putnbr.c \
		srcs/cub.c \
		srcs/get_next_line.c \
		srcs/get_next_line_utils.c \
		srcs/ft_split.c \
		srcs/sprite.c \
		srcs/parse_map.c \
		srcs/save_color.c \
		srcs/check_element.c \
		srcs/save_resolution.c \
		srcs/parse_file.c \
		srcs/check_map_error.c \
		srcs/get_image.c \
		srcs/save_direction_textures.c \
		srcs/render_walls.c \
		srcs/draw_walls.c \
		srcs/keys.c \
		srcs/player.c \
		srcs/grid.c \
		srcs/render_ray.c \
		srcs/save_sprite_texture.c \
		srcs/cast_ray.c \
		srcs/draw_one_pixel.c \
		srcs/free_memory.c \
		srcs/ft_error.c \
		srcs/screenshot.c \
		srcs/create_rgb.c \
		srcs/ft_atoi.c \
		srcs/ft_putstr.c \
		srcs/ft_itoa.c \
		srcs/get_args.c \
		srcs/init_textures.c \
		srcs/ft_calloc.c \
		srcs/ft_memcpy.c \
		srcs/ft_strrchr.c \
		srcs/map_error.c

all: comp

lib :
	cd libft; make

comp : lib
	gcc $(FLAGS) -o cub3D -I /usr/local/include $(SRCS) libft/libft.a -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit 

clean :
	rm -rf cub3D

fclean: clean
	rm *.bmp; cd libft; make fclean

re : fclean comp
