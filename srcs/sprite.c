/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 22:24:57 by mel-haya          #+#    #+#             */
/*   Updated: 2020/10/19 20:15:50 by mobaz            ###   ########.fr       */
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
	sp_image.texture = texture[1];
	printf("%s\n", sp_image.texture);
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
				sprite[sprite_index].x = (j + 0.5) * TILE_SIZE;
				sprite[sprite_index].y = (i + 0.5) * TILE_SIZE;
				sprite_index++;
			}
			j++;
		}
		i++;
	}
}

void	draw_sprite(int x, float distance, float height)
{
	int i;
	int j;
	int y_offset;
	int color;

	i = x;
	while (i <= x + height)
	{
		j = (win_height - height) / 2;
		y_offset = 0;
		if (i >= 0 && i < win_width && distance < rays[i].distance)
		{
			while (j < (win_height + height) / 2 - 1)
			{
				color = sp_image.data[(int)(y_offset / height * sp_image.height)
				* sp_image.width + (int)((i - x) / height * sp_image.width)];
				if (j < win_height && j >= 0 && color != 0x000000)
					data[(j) * win_width + (i)] = color;
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
	while (i < sprite_index)
	{
		sprite[i].distance = distance(sprite[i].x, sprite[i].y);
		i++;
	}
	i = 0;
	while (i < sprite_index - 1)
	{
		j = 0;
		while (j < sprite_index - 1 - i)
		{
			if (sprite[j].distance < sprite[j + 1].distance)
			{
				tmp = sprite[j];
				sprite[j] = sprite[j + 1];
				sprite[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	render_sprite(void)
{
	float		angle;
	float		sprite_height;
	int			column_index;
	int			i;

	sort_sprites();
	i = 0;
	while (i < sprite_index)
	{
		sprite[i].distance = distance(sprite[i].x, sprite[i].y);
		angle = atan2(sprite[i].y - player.y, sprite[i].x - player.x);
		while (angle - player.rotationAngle > M_PI)
			angle -= 2 * M_PI;
		while (angle - player.rotationAngle < -M_PI)
			angle += 2 * M_PI;
		angle = normalize_angle(angle);
		sprite_height = (TILE_SIZE / sprite[i].distance) * distance_proj_plane;
		column_index = (angle - rays[0].rayAngle)
						/ (FOV_ANGLE / win_width) - (sprite_height / 2);
		draw_sprite(column_index, sprite[i].distance, sprite_height);
		i++;
	}
}
