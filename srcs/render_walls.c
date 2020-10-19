/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 14:40:49 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/19 18:46:53 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "../cub1.h"

void	put_walls_to_image(double walltop, double wallbottom, int i)
{
	int j;

	j = 0;
	while (j < walltop)
		data[(j++ * win_width) + i] = 0;
	j = wallbottom;
	while (j < win_height)
		data[(j++ * win_width) + i] = 200;
}

void	render_walls(void)
{
	int		i;
	double	ray_distance;
	double	wall_strip_height;
	double	walltop;
	double	wallbottom;

	i = 0;
	distance_proj_plane = (win_width / 2) / tanf(FOV_ANGLE / 2);
	while (i < win_width)
	{
		ray_distance = rays[i].distance * cosf(
						rays[i].rayAngle - player.rotationAngle);
		wall_strip_height = ((double)TILE_SIZE / ray_distance)
								* (double)distance_proj_plane;
		walltop = ((double)win_height / 2) - (wall_strip_height / 2);
		walltop = walltop < 0 ? 0 : walltop;
		wallbottom = ((double)win_height / 2) + (wall_strip_height / 2);
		wallbottom = wallbottom > win_height ? win_height : wallbottom;
		put_walls_to_image(walltop, wallbottom, i);
		line3d_walls(walltop, wallbottom, wall_strip_height, i++);
	}
	render_sprite();
	mlx_put_image_to_window(mlx, window, image, 0, 0);
}
