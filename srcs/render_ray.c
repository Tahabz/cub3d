/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 13:40:37 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/30 12:20:24 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	horizental_grid_intersection(void)
{
	g_ray_vars.yintersection = floorf(g_player.y / TILE_SIZE) * TILE_SIZE;
	g_ray_vars.yintersection += (g_ray.facing_down ? TILE_SIZE : 0);
	g_ray_vars.xintersection = g_player.x +
			(g_ray_vars.yintersection - g_player.y) / tanf(g_ray.ray_angle);
	g_ray_vars.ystep = TILE_SIZE;
	g_ray_vars.ystep *= (g_ray.facing_up ? -1 : 1);
	g_ray_vars.xstep = TILE_SIZE / tanf(g_ray.ray_angle);
	g_ray_vars.xstep *= (g_ray.facing_left && g_ray_vars.xstep > 0) ? -1 : 1;
	g_ray_vars.xstep *= (g_ray.facing_right && g_ray_vars.xstep < 0) ? -1 : 1;
	g_ray_vars.hor_hit_x = g_ray_vars.xintersection;
	g_ray_vars.hor_hit_y = g_ray_vars.yintersection;
	while (g_ray_vars.hor_hit_y >= 0 &&
		g_ray_vars.hor_hit_y < g_win_height2d && g_ray_vars.hor_hit_x
		>= 0)
	{
		if (grid_has_wall_at(g_ray_vars.hor_hit_x, g_ray.facing_up ?
			g_ray_vars.hor_hit_y - 1 : g_ray_vars.hor_hit_y))
		{
			g_ray_vars.hor_distance = distance(g_ray_vars.hor_hit_x,
											g_ray_vars.hor_hit_y);
			break ;
		}
		g_ray_vars.hor_hit_x += g_ray_vars.xstep;
		g_ray_vars.hor_hit_y += g_ray_vars.ystep;
	}
}

void	vertical_grid_intersection(void)
{
	g_ray_vars.ver_distance = 1000000000;
	g_ray_vars.xintersection = floorf(g_player.x / TILE_SIZE) * TILE_SIZE;
	g_ray_vars.xintersection += (g_ray.facing_right ? TILE_SIZE : 0);
	g_ray_vars.yintersection = g_player.y +
			(g_ray_vars.xintersection - g_player.x) * tanf(g_ray.ray_angle);
	g_ray_vars.xstep = TILE_SIZE;
	g_ray_vars.xstep *= (g_ray.facing_left ? -1 : 1);
	g_ray_vars.ystep = TILE_SIZE * tanf(g_ray.ray_angle);
	g_ray_vars.ystep *= (g_ray.facing_up && g_ray_vars.ystep > 0) ? -1 : 1;
	g_ray_vars.ystep *= (g_ray.facing_down && g_ray_vars.ystep < 0) ? -1 : 1;
	g_ray_vars.ver_hit_x = g_ray_vars.xintersection;
	g_ray_vars.ver_hit_y = g_ray_vars.yintersection;
	while (g_ray_vars.ver_hit_y >= 0 && g_ray_vars.ver_hit_y < g_win_height2d
	&& g_ray_vars.ver_hit_x >= 0)
	{
		if (grid_has_wall_at(g_ray.facing_left ? g_ray_vars.ver_hit_x
		- 1 : g_ray_vars.ver_hit_x, g_ray_vars.ver_hit_y))
		{
			g_ray_vars.ver_distance = distance(g_ray_vars.ver_hit_x,
											g_ray_vars.ver_hit_y);
			break ;
		}
		g_ray_vars.ver_hit_x += g_ray_vars.xstep;
		g_ray_vars.ver_hit_y += g_ray_vars.ystep;
	}
}

void	render_ray(void)
{
	g_ray_vars.hor_distance = 10000000000;
	horizental_grid_intersection();
	vertical_grid_intersection();
	if (g_ray_vars.ver_distance < g_ray_vars.hor_distance)
	{
		g_ray.hit_vert = 1;
		g_ray.wall_hit_x = g_ray_vars.ver_hit_x;
		g_ray.wall_hit_y = g_ray_vars.ver_hit_y;
		g_ray.distance = g_ray_vars.ver_distance;
	}
	else
	{
		g_ray.hit_vert = 0;
		g_ray.wall_hit_x = g_ray_vars.hor_hit_x;
		g_ray.wall_hit_y = g_ray_vars.hor_hit_y;
		g_ray.distance = g_ray_vars.hor_distance;
	}
}
