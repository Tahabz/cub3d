/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:07:27 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/12 10:28:31 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBALS_H
# define GLOBALS_H

char				**g_map;
void				*g_image;
int					*g_data;
void				*g_window;
void				*g_mlx;
typedef struct		s_player {
	double	x;
	double	y;
	int		turn_direction;
	int		walk_direction;
	double	rotation_angle;
	double	rotation_speed;
	int		move_speed;
	int		side;
}					t_player;
typedef struct		s_rays {
	double	ray_angle;
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
	int		facing_down;
	int		facing_up;
	int		facing_left;
	int		facing_right;
	int		hit_vert;
}					t_rays;
typedef struct		s_image {
	int		*data;
	void	*image;
	int		width;
	int		height;
	int		bpp;
	int		sl;
	int		end;
	char	*texture;
	int		status;
}					t_image;
typedef struct		s_sprite {
	int		x;
	int		y;
	float	distance;
}					t_sprite;
typedef struct		s_ray_vars
{
	double	yintersection;
	double	xintersection;
	double	xstep;
	double	ystep;
	double	hor_distance;
	double	ver_distance;
	double	ver_hit_x;
	double	ver_hit_y;
	double	hor_hit_x;
	double	hor_hit_y;
}					t_ray_vars;

typedef struct		s_screenshot
{
	int				width_bytes;
	int				padding_size;
	int				stride;
	unsigned char	*file_header;
	unsigned char	*info_header;
}					t_screenshot;
int					g_player_count;
typedef struct		s_bitmapheader{
	uint32_t	file_size;
	uint32_t	off_bits;
	uint32_t	size;
	uint32_t	info_size;
	int32_t		width;
	int32_t		height;
	uint16_t	planes;
	uint16_t	bit_count;
	uint32_t	image_size;
	int			width_in_bytes;
	int			fd;
}					t_bitmapheader;

t_ray_vars			g_ray_vars;
int					g_sprite_index;
t_sprite			g_sprites[500];
int					g_win_width2d;
int					g_win_height2d;
int					g_win_width;
int					g_win_height;
int					g_floor_color[4];
int					g_ceilling_color[4];
extern double		g_fov_angle;
extern double		g_distance_proj_plane;
t_image				g_no_image;
t_image				g_we_image;
t_image				g_ea_image;
t_image				g_so_image;
t_image				g_sp_image;
t_rays				*g_rays;
t_rays				g_ray;
t_player			g_player;
int					g_num_rows;
int					g_att;
int					g_bits_per_pixel;
int					g_size_line;
int					g_endian;
char				*g_file;
int					g_prev_len;
#endif
