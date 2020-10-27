/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:58:46 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/27 14:07:07 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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
			((double)g_we_image.height / (double)wall_height);
		offset_y = offset_y < 0 ? 0 : offset_y;
		if (g_rays[index].hit_vert && g_rays[index].facing_left)
			color = g_we_image.data[(offset_y * g_we_image.height) + offset_x];
		else if (g_rays[index].hit_vert && g_rays[index].facing_right)
			color = g_ea_image.data[(offset_y * g_ea_image.height) + offset_x];
		else if (!g_rays[index].hit_vert && g_rays[index].facing_up)
			color = g_no_image.data[(offset_y * g_no_image.height) + offset_x];
		else if (!g_rays[index].hit_vert && g_rays[index].facing_down)
			color = g_so_image.data[(offset_y * g_so_image.height) + offset_x];
		g_data[(j++ * g_win_width) + index] = color;
	}
}
