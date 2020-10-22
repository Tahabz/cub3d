/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:07:27 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/21 19:51:00 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char **map;
void *image;
int *data;
void *window;
void *mlx;


typedef struct s_player {
	double	x;
	double	y;
	int		turnDirection;
	int		walkDirection;
	double	rotationAngle;
	double	rotationSpeed;
	int		moveSpeed;
}				t_player;

typedef struct s_rays {
	double 	ray_angle;
	double	wall_hit_x;
	double	wall_hit_y;
	double	distance;
	int		is_ray_facing_down;
	int		is_ray_facing_up;
	int		is_ray_facing_left;
	int		is_ray_facing_right;
	int		hit_vert;
}				t_rays;

typedef struct s_image {
	int *data;
	void *image;
	int width;
	int height;
	int	bpp;
	int	sl;
	int	end;
	char *texture;
}				t_image;

typedef struct s_sprite {
	int x;
	int y;
	float distance;
}				t_sprite;

typedef struct		s_ray_vars
{
	double yintersection;
	double xintersection;
	double xstep;
	double ystep;
	double horDistance;
	double verDistance;
	double ver_wall_hit_x;
	double verwall_hit_y;
	double hor_wall_hit_x;
	double hor_wall_hit_y;
}					t_ray_vars;



t_ray_vars			ray_vars;
int g_sprite_index;
t_sprite g_sprites[500];

extern const int WINDOW_WIDTH3D;
extern const int WINDOW_HEIGHT3D;

int g_win_width;
int g_win_height;

int floor_color[3];
int ceilling_color[3];
extern double g_fov_angle;
extern double g_distance_proj_plane;

t_image no_image;
t_image we_image;
t_image ea_image;
t_image so_image;
t_image g_sp_image;
t_rays *g_rays;
t_rays ray;
t_player g_player;

int num_rows;