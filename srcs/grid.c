/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:10:25 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/19 12:11:17 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "../cub1.h"

int		grid_has_sprite_at(int x, int y)
{
	int i;

	i = 0;
	x = x / TILE_SIZE;
	y = y / TILE_SIZE;
	if (y >= 0 && y < NUM_ROWS)
	{
		while (map[y][i])
			i++;
		if (x >= 0 && x < i)
		{
			return (map[y][x] == '2');
		}
	}
	return (1);
}

int		grid_has_wall_at(int x, int y)
{
	int i;

	i = 0;
	x = x / TILE_SIZE;
	y = y / TILE_SIZE;
	if (y >= 0 && y < NUM_ROWS)
	{
		while (map[y][i])
			i++;
		if (x >= 0 && x < i)
		{
			return (map[y][x] == '1');
		}
	}
	return (1);
}
