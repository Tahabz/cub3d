/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:40:37 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/21 19:11:26 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "../cub1.h"

void				horizental_grid_intersection(void)
{
	ray_vars.yintersection = floorf(g_player.y / TILE_SIZE) * TILE_SIZE;
	ray_vars.yintersection += (ray.is_ray_facing_down ? TILE_SIZE : 0);
	ray_vars.xintersection = g_player.x + (ray_vars.yintersection - g_player.y)
							/ tanf(ray.ray_angle);
	ray_vars.ystep = TILE_SIZE;
	ray_vars.ystep *= (ray.is_ray_facing_up ? -1 : 1);
	ray_vars.xstep = TILE_SIZE / tanf(ray.ray_angle);
	ray_vars.xstep *= (ray.is_ray_facing_left && ray_vars.xstep > 0) ? -1 : 1;
	ray_vars.xstep *= (ray.is_ray_facing_right && ray_vars.xstep < 0) ? -1 : 1;
	ray_vars.hor_wall_hit_x = ray_vars.xintersection;
	ray_vars.hor_wall_hit_y = ray_vars.yintersection;
	while (ray_vars.hor_wall_hit_y >= 0 &&
		ray_vars.hor_wall_hit_y < WIN_HEIGHT2D && ray_vars.hor_wall_hit_x
		>= 0 && ray_vars.hor_wall_hit_x < WIN_WIDTH2D)
	{
		if (grid_has_wall_at(ray_vars.hor_wall_hit_x, ray.is_ray_facing_up ?
			ray_vars.hor_wall_hit_y - 1 : ray_vars.hor_wall_hit_y))
		{
			ray_vars.horDistance = distance(ray_vars.hor_wall_hit_x,
											ray_vars.hor_wall_hit_y);
			break ;
		}
		ray_vars.hor_wall_hit_x += ray_vars.xstep;
		ray_vars.hor_wall_hit_y += ray_vars.ystep;
	}
}

void				vertical_grid_intersection(void)
{
	ray_vars.verDistance = 1000000000;
	ray_vars.xintersection = floorf(g_player.x / TILE_SIZE) * TILE_SIZE;
	ray_vars.xintersection += (ray.is_ray_facing_right ? TILE_SIZE : 0);
	ray_vars.yintersection = g_player.y + (ray_vars.xintersection - g_player.x)
							* tanf(ray.ray_angle);
	ray_vars.xstep = TILE_SIZE;
	ray_vars.xstep *= (ray.is_ray_facing_left ? -1 : 1);
	ray_vars.ystep = TILE_SIZE * tanf(ray.ray_angle);
	ray_vars.ystep *= (ray.is_ray_facing_up && ray_vars.ystep > 0) ? -1 : 1;
	ray_vars.ystep *= (ray.is_ray_facing_down && ray_vars.ystep < 0) ? -1 : 1;
	ray_vars.ver_wall_hit_x = ray_vars.xintersection;
	ray_vars.verwall_hit_y = ray_vars.yintersection;
	while (ray_vars.verwall_hit_y >= 0 && ray_vars.verwall_hit_y < WIN_HEIGHT2D
	&& ray_vars.ver_wall_hit_x >= 0 && ray_vars.ver_wall_hit_x < WIN_WIDTH2D)
	{
		if (grid_has_wall_at(ray.is_ray_facing_left ? ray_vars.ver_wall_hit_x
		- 1 : ray_vars.ver_wall_hit_x, ray_vars.verwall_hit_y))
		{
			ray_vars.verDistance = distance(ray_vars.ver_wall_hit_x,
											ray_vars.verwall_hit_y);
			break ;
		}
		ray_vars.ver_wall_hit_x += ray_vars.xstep;
		ray_vars.verwall_hit_y += ray_vars.ystep;
	}
}

void				render_ray(void)
{
	ray_vars.horDistance = 10000000000;
	horizental_grid_intersection();
	vertical_grid_intersection();
	if (ray_vars.verDistance < ray_vars.horDistance)
	{
	//	line(ray.rayAngle, ray_vars.hor_wall_hit_x, ray_vars.hor_wall_hit_y);
		ray.hit_vert = 1;
		ray.wall_hit_x = ray_vars.ver_wall_hit_x;
		ray.wall_hit_y = ray_vars.verwall_hit_y;
		ray.distance = ray_vars.verDistance;
	}
	else
	{
		ray.hit_vert = 0;
		ray.wall_hit_x = ray_vars.hor_wall_hit_x;
		ray.wall_hit_y = ray_vars.hor_wall_hit_y;
		ray.distance = ray_vars.horDistance;
	//	line(ray.rayAngle, ray_vars.ver_wall_hit_x, ray_vars.verwall_hit_y);
	}
}
