/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:07:27 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/24 12:35:46 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB1_H
# define CUB1_H

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

t_ray_vars			g_ray_vars;
int					g_sprite_index;
t_sprite			g_sprites[500];
extern const int	g_win_width3d;
extern const int	g_win_height3d;
int					g_win_width;
int					g_win_height;
int					g_floor_color[3];
int					g_ceilling_color[3];
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
#endif
