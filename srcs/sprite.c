/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 22:24:57 by mel-haya          #+#    #+#             */
/*   Updated: 2020/10/22 14:24:53 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "../cub1.h"

void	save_sprite_texture(char **texture)
{
	int i;

	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		printf("Sprite number of information is incorrect\n");
	g_sp_image.texture = texture[1];
	printf("%s\n", g_sp_image.texture);
}

void	add_sprite(void)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '2')
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

void	draw_sprite(int x, double distance, double height)
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
				color = g_sp_image.data[(int)(y_offset / height * g_sp_image.height)
				* g_sp_image.width + (int)((i - x) / height * g_sp_image.width)];
				if (j < g_win_height && j >= 0 && color != 0x000000)
					data[(j) * g_win_width + (i)] = color;
				j++;
				y_offset++;
			}
		}
		i++;
	}
}

void	sort_sprites(void)
{
	int			i;
	int			j;
	t_sprite	tmp;

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
			if (g_sprites[j].distance < g_sprites[j + 1].distance)
			{
				tmp = g_sprites[j];
				g_sprites[j] = g_sprites[j + 1];
				g_sprites[j + 1] = tmp;
			}
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
		while (angle - g_player.rotationAngle > M_PI)
			angle -= 2 * M_PI;
		while (angle - g_player.rotationAngle < -M_PI)
			angle += 2 * M_PI;
		if (g_rays[0].ray_angle - angle > M_PI) {
			angle = angle + 2 * M_PI;
		}
		if (angle - g_rays[0].ray_angle > M_PI) {
			angle = angle - 2 * M_PI;
		}
		sprite_height = (TILE_SIZE / g_sprites[i].distance) * g_distance_proj_plane;
		//angle = normalize_angle(angle);
		column_index = (angle - g_rays[0].ray_angle)
						/ (g_fov_angle / g_win_width) - (sprite_height / 2);
		printf("-------------------------------\nsprite height = %f\nray angle = %f\nplayer x = %f\nangle = %f\ncolumn index = %d\n", sprite_height, g_rays[0].ray_angle, g_player.y, angle, column_index);
		draw_sprite(column_index, g_sprites[i].distance, sprite_height);
		i++;
	}
}

// void draw(int x, int y, int color)
// {
//     data[y * g_win_width + x] = color;
// }
// void ft_draw_sprits(int index, int offset_x, int offset_y)
// {
//     int i = -1;
//     int j = -1;
//     int indx = 0;
//     double img_ratio = (double)g_sp_image.width / g_sprs[index].scale;
//     int max_window = TILE_SIZE * TILE_SIZE;
//     while (++i < (int)g_sprs[index].scale)
//     {
//         if (offset_x + i < 0 || offset_x + i > g_win_width)
//             continue;
//         if (g_rays[offset_x + i].distance <= g_sprs[index].distance)
//             continue;
//         j = -1;
//         while (++j < (int)g_sprs[index].scale)
//         {
//             if (offset_y + j + g_updown < 0 || offset_y + j + g_updown > g_win_height)
//                 continue;
//             indx = TILE_SIZE * (TILE_SIZE * j / g_sprs[index].scale) + (TILE_SIZE * i / g_sprs[index].scale);
//             indx = index >= max_window ? max_window : indx;
//             if (g_sp_image.data[indx] != 0x980088)
//                 draw(offset_x + i, offset_y + j + g_updown, g_sp.data[indx]);
//         }
//     }
// }
