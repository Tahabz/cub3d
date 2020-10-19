/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 20:07:27 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/19 20:07:28 by mobaz            ###   ########.fr       */
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
	double 	rayAngle;
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
int sprite_index;
t_sprite sprite[500];

extern const int WINDOW_WIDTH3D;
extern const int WINDOW_HEIGHT3D;

int win_width;
int win_height;

int floor_color[3];
int ceilling_color[3];
extern double FOV_ANGLE;
extern double distance_proj_plane;

t_image no_image;
t_image we_image;
t_image ea_image;
t_image so_image;
t_image sp_image;
t_rays *rays;
t_rays ray;
t_player player;

int num_rows;