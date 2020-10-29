FLAGS = -Wall -Wextra -Werror -g
DFLAGS = -D L_C=N
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
		srcs/ft_itoa.c 
all: comp

comp : 
	gcc $(FLAGS) -I /usr/local/include $(SRCS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit 

clean :
	rm -rf a.out*
