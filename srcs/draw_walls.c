/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:58:46 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/21 19:04:55 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "../cub1.h"

void	line3d_walls(int w_top, int w_bottom, int wall_height, int index)
{
	int j;
	int offset_x;
	int offset_y;
	int	color;

	if (g_rays[index].hit_vert)
		offset_x = (int)g_rays[index].wall_hit_y % TILE_SIZE;
	else
		offset_x = (int)g_rays[index].wall_hit_x % TILE_SIZE;
	j = w_top;
	while (j < w_bottom)
	{
		offset_y = (j + ((wall_height / 2) - (g_win_height / 2))) *
			((double)we_image.height / (double)wall_height);
		offset_y = offset_y < 0 ? 0 : offset_y;
		if (g_rays[index].hit_vert && g_rays[index].is_ray_facing_left)
			color = we_image.data[(offset_y * we_image.height) + offset_x];
		else if (g_rays[index].hit_vert && g_rays[index].is_ray_facing_right)
			color = ea_image.data[(offset_y * ea_image.height) + offset_x];
		else if (!g_rays[index].hit_vert && g_rays[index].is_ray_facing_up)
			color = no_image.data[(offset_y * no_image.height) + offset_x];
		else if (!g_rays[index].hit_vert && g_rays[index].is_ray_facing_down)
			color = so_image.data[(offset_y * so_image.height) + offset_x];
		data[(j++ * g_win_width) + index] = color;
	}
}
