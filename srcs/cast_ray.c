#include "../cub.h"
#include "../cub1.h"

void init_ray(double rayAngle)
{
	ray.rayAngle = rayAngle;
	ray.distance = 0;
	ray.wall_hit_x = 0;
	ray.wall_hit_y = 0;
	ray.isRayFacingDown = (rayAngle > 0 && rayAngle < M_PI);
	ray.isRayFacingUp = !ray.isRayFacingDown;
	ray.isRayFacingRight = ((rayAngle < 0.5 * M_PI) || (rayAngle > 1.5 * M_PI));
	ray.isRayFacingLeft = !ray.isRayFacingRight;
}

void castAllRays()
{
	rays = (t_rays *)malloc(/*WINDOW_WIDTH2D*/win_width * sizeof(t_rays));
	double rayAngle = player.rotationAngle - (FOV_ANGLE / 2);
	int i = 0;
	while (i < /*WINDOW_WIDTH2D*/win_width)
	{
		init_ray(normalizeAngle(rayAngle));
		render_ray();
		rays[i] = ray;
		rayAngle += (FOV_ANGLE / (win_width));
		i++;
	}
}
