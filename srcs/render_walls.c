/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:40:49 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/23 11:08:00 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	put_walls_to_image(double walltop, double wallbottom, int i)
{
	int j;

	j = 0;
	while (j < walltop)
		g_data[(j++ * g_win_width) + i] = 0;
	j = wallbottom;
	while (j < g_win_height)
		g_data[(j++ * g_win_width) + i] = 200;
}

void	render_walls(void)
{
	int		i;
	double	ray_distance;
	double	wall_strip_height;
	double	walltop;
	double	wallbottom;

	i = 0;
	g_distance_proj_plane = (g_win_width / 2) / tanf(g_fov_angle / 2);
	while (i < g_win_width)
	{
		ray_distance = g_rays[i].distance * cosf(
						g_rays[i].ray_angle - g_player.rotation_angle);
		wall_strip_height = ((double)TILE_SIZE / ray_distance)
								* (double)g_distance_proj_plane;
		walltop = ((double)g_win_height / 2) - (wall_strip_height / 2);
		walltop = walltop < 0 ? 0 : walltop;
		wallbottom = ((double)g_win_height / 2) + (wall_strip_height / 2);
		wallbottom = wallbottom > g_win_height ? g_win_height : wallbottom;
		put_walls_to_image(walltop, wallbottom, i);
		line3d_walls(walltop, wallbottom, wall_strip_height, i++);
	}
	render_sprite();
	mlx_put_image_to_window(g_mlx, g_window, g_image, 0, 0);
}
