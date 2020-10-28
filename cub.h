/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:43:34 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/28 17:41:22 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include "get_next_line.h"
# include "cub1.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# define NUM_ROWS (19)
# define NUM_COLS (80)
# define TILE_SIZE 200
# define WIN_WIDTH2D TILE_SIZE * NUM_COLS
# define WIN_HEIGHT2D TILE_SIZE * NUM_ROWS
# define UP_ARROW 126
# define RIGHT_ARROW 124
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# define WALL_STRIP_WIDTH 1
# define MINIMAP_SCALE 0.2
# define ESCAPE 53
char			**ft_split(char const *str, char c);
double			normalize_angle(double angle);
void			render_walls();
void			ft_putchar(char c);
void			cast_rays();
void			ft_putnbr(int n);
void			rect(int tilex, int tiley, unsigned int tilecol, int size);
void			render_grid();
int				grid_has_wall_at(int x, int y);
void			line3d(int tilex, int tiley, int height, unsigned int tilecol);
void			check_map_errors();
double			distance(double x, double y);
void			render_sprite();
int				grid_has_sprite_at(int x, int y);
void			add_sprite();
void			parse_file();
void			parse_map(int fd, char *line);
void			save_floor_color(char **element);
void			save_ceilling_color(char **element);
void			check_element(char **element);
void			save_sprite_texture(char **texture);
void			save_south_texture(char **texture);
void			save_east_texture(char **texture);
void			save_west_texture(char **texture);
void			save_north_texture(char **texture);
void			save_resolution(char **resolution);
void			get_image();
void			line3d_walls(int w_top, int w_bottom, int wall_height, int index);
int				key_pressed(int key, void *param);
int				key_released(int key, void *param);
void			render_player();
void			init_player();
void			player_update();
int				grid_has_sprite_at(int x, int y);
int				grid_has_wall_at(int x, int y);
void			render_ray();
void			save_sprite_texture(char **texture);
void			draw_one_pixel(int y, int x, double color);
void			free_memory();
void			ft_error();
void			free_double_pointer(char **ptr);
void			ft_map_error(int i, int j);
void 			generate_bitmap_image();
unsigned char*	create_bitmap_file_header(int stride);
unsigned char*	create_bitmap_info_header();
void			screenshot();
#endif
