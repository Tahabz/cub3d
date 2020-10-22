#include "../cub.h"
#include "../cub1.h"

void init_ray(double rayAngle)
{
	ray.ray_angle = rayAngle;
	ray.distance = 0;
	ray.wall_hit_x = 0;
	ray.wall_hit_y = 0;
	ray.is_ray_facing_down = (rayAngle > 0 && rayAngle < M_PI);
	ray.is_ray_facing_up = !ray.is_ray_facing_down;
	ray.is_ray_facing_right = ((rayAngle < 0.5 * M_PI) || (rayAngle > 1.5 * M_PI));
	ray.is_ray_facing_left = !ray.is_ray_facing_right;
}

void castAllRays()
{
	g_rays = (t_rays *)malloc(/*WINDOW_WIDTH2D*/g_win_width * sizeof(t_rays));
	double rayAngle = g_player.rotationAngle - (g_fov_angle / 2);
	int i = 0;
	while (i < /*WINDOW_WIDTH2D*/g_win_width)
	{
		init_ray(normalize_angle(rayAngle));
		render_ray();
		g_rays[i] = ray;
		rayAngle += (g_fov_angle / (g_win_width));
		i++;
	}
}
