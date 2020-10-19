#include "../cub.h"
#include "../cub1.h"

void render_ray()
{
	double yintersection, xintersection;
	double xstep, ystep;
	double hor_wall_hit_x, hor_wall_hit_y, horDistance = 10000000000;

	//---------------CLOSEST HORIZONTAL GRID INTERSECTION------------------------
	yintersection = floorf(player.y / TILE_SIZE) * TILE_SIZE;
	yintersection += (ray.isRayFacingDown ? TILE_SIZE : 0);
	xintersection = player.x + (yintersection - player.y) / tanf(ray.rayAngle);
	ystep = TILE_SIZE;
	ystep *= (ray.isRayFacingUp ? - 1 : 1);
	xstep = TILE_SIZE / tanf(ray.rayAngle);
	xstep *= (ray.isRayFacingLeft && xstep > 0) ? -1 : 1;
	xstep *= (ray.isRayFacingRight && xstep < 0) ? -1 : 1;

	hor_wall_hit_x = xintersection;
	hor_wall_hit_y = yintersection;
	while (hor_wall_hit_y >= 0 && hor_wall_hit_y < WINDOW_HEIGHT2D && hor_wall_hit_x >= 0 && hor_wall_hit_x < WINDOW_WIDTH2D)
	{
		if (grid_has_wall_at(hor_wall_hit_x, ray.isRayFacingUp ? hor_wall_hit_y - 1: hor_wall_hit_y))
		{
			horDistance = distance(hor_wall_hit_x, hor_wall_hit_y);
			break;
		}
		hor_wall_hit_x += xstep;
		hor_wall_hit_y += ystep;
	}
	//---------------CLOSEST ------------------------

	double ver_wall_hit_x, verwall_hit_y, verDistance = 1000000000;

	xintersection = floorf(player.x / TILE_SIZE) * TILE_SIZE;
	xintersection += (ray.isRayFacingRight ? TILE_SIZE : 0);
	yintersection = player.y + (xintersection - player.x) * tanf(ray.rayAngle);
	xstep = TILE_SIZE;
	xstep *= (ray.isRayFacingLeft ? -1 : 1);
	ystep = TILE_SIZE * tanf(ray.rayAngle);
	ystep *= (ray.isRayFacingUp && ystep > 0) ? -1 : 1;
	ystep *= (ray.isRayFacingDown && ystep < 0) ? -1 : 1;

	ver_wall_hit_x = xintersection;
	verwall_hit_y = yintersection;
	while (verwall_hit_y >= 0 && verwall_hit_y < WINDOW_HEIGHT2D && ver_wall_hit_x >= 0 && ver_wall_hit_x < WINDOW_WIDTH2D)
	{
		if (grid_has_wall_at(ray.isRayFacingLeft ? ver_wall_hit_x -1 : ver_wall_hit_x , verwall_hit_y))
		{
			verDistance = distance(ver_wall_hit_x, verwall_hit_y);
			break;
		}		
		ver_wall_hit_x += xstep;
		verwall_hit_y += ystep;
	}
	if (verDistance < horDistance)
	{
	//	line(ray.rayAngle, hor_wall_hit_x, hor_wall_hit_y);
		ray.hit_vert = 1;
		ray.wall_hit_x = ver_wall_hit_x;
		ray.wall_hit_y = verwall_hit_y;
		ray.distance = verDistance;
	}
	else
	{
		ray.hit_vert = 0;
		ray.wall_hit_x = hor_wall_hit_x;
		ray.wall_hit_y = hor_wall_hit_y;
		ray.distance = horDistance;
	//	line(ray.rayAngle, ver_wall_hit_x, verwall_hit_y);
	}
}
