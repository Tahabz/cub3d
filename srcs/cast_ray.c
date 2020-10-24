/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:13:18 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/23 13:16:53 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_ray(double ray_angle)
{
	g_ray.ray_angle = ray_angle;
	g_ray.distance = 0;
	g_ray.wall_hit_x = 0;
	g_ray.wall_hit_y = 0;
	g_ray.facing_down = (ray_angle > 0 && ray_angle < M_PI);
	g_ray.facing_up = !g_ray.facing_down;
	g_ray.facing_right = ((ray_angle < 0.5 * M_PI) || (ray_angle > 1.5 * M_PI));
	g_ray.facing_left = !g_ray.facing_right;
}

void	cast_rays(void)
{
	double	ray_angle;
	int		i;

	g_rays = (t_rays *)malloc(sizeof(t_rays) * g_win_width);
	ray_angle = g_player.rotation_angle - (g_fov_angle / 2);
	i = 0;
	while (i < g_win_width)
	{
		init_ray(normalize_angle(ray_angle));
		render_ray();
		g_rays[i] = g_ray;
		ray_angle += (g_fov_angle / g_win_width);
		i++;
	}
}
