/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:16:58 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/11 12:56:57 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	add_sprite(void)
{
	int i;
	int j;

	i = 0;
	while (g_map[i])
	{
		j = 0;
		while (g_map[i][j])
		{
			if (g_map[i][j] == '2')
			{
				g_sprites[g_sprite_index].x = (j + 0.5) * TILE_SIZE;
				g_sprites[g_sprite_index].y = (i + 0.5) * TILE_SIZE;
				g_sprite_index++;
			}
			j++;
		}
		i++;
	}
}

void	draw_sprites(int x, double distance, double height)
{
	int i;
	int j;
	int y_offset;
	int color;

	i = x;
	while (i <= x + height)
	{
		j = (g_win_height - height) / 2;
		y_offset = 0;
		if (i >= 0 && i < g_win_width && distance < g_rays[i].distance)
		{
			while (j < (g_win_height + height) / 2 - 1)
			{
				color = g_sp_image.data[(int)
				(y_offset / height * g_sp_image.height)
				* g_sp_image.width +
				(int)((i - x) / height * g_sp_image.width)];
				draw_one_pixel(j, i, color);
				j++;
				y_offset++;
			}
		}
		i++;
	}
}

void	swap(int i)
{
	t_sprite tmp;

	if (g_sprites[i].distance < g_sprites[i + 1].distance)
	{
		tmp = g_sprites[i];
		g_sprites[i] = g_sprites[i + 1];
		g_sprites[i + 1] = tmp;
	}
}

void	sort_sprites(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_sprite_index)
	{
		g_sprites[i].distance = distance(g_sprites[i].x, g_sprites[i].y);
		i++;
	}
	i = 0;
	while (i < g_sprite_index - 1)
	{
		j = 0;
		while (j < g_sprite_index - 1 - i)
		{
			swap(j);
			j++;
		}
		i++;
	}
}

void	render_sprite(void)
{
	double		angle;
	double		sprite_height;
	int			column_index;
	int			i;

	sort_sprites();
	i = 0;
	while (i < g_sprite_index)
	{
		g_sprites[i].distance = distance(g_sprites[i].x, g_sprites[i].y);
		angle = atan2(g_sprites[i].y - g_player.y, g_sprites[i].x - g_player.x);
		if (g_rays[0].ray_angle - angle > M_PI)
			angle = angle + 2 * M_PI;
		if (angle - g_rays[0].ray_angle > M_PI)
			angle = angle - 2 * M_PI;
		sprite_height = (TILE_SIZE / g_sprites[i].distance) *
						g_distance_proj_plane;
		column_index = (angle - g_rays[0].ray_angle)
						/ (g_fov_angle / g_win_width) - (sprite_height / 2);
		draw_sprites(column_index, g_sprites[i].distance, sprite_height);
		i++;
	}
}
