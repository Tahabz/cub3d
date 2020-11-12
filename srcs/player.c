/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:48:33 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/12 10:36:01 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	get_player_pos_map(int i, int j)
{
	g_player.x = j * 200 + 100;
	g_player.y = i * 200 + 100;
	if (g_map[i][j] == 'N')
		g_player.rotation_angle = (3 * M_PI) / 2;
	else if (g_map[i][j] == 'S')
		g_player.rotation_angle = M_PI / 2;
	else if (g_map[i][j] == 'E')
		g_player.rotation_angle = 0;
	else if (g_map[i][j] == 'W')
		g_player.rotation_angle = M_PI;
}

int		is_player(int i, int j)
{
	if (g_player_count > 1)
		ft_map_error(i, j);
	if (g_map[i][j] == 'N' || g_map[i][j] == 'S' || g_map[i][j] == 'E' ||
		g_map[i][j] == 'W')
	{
		get_player_pos_map(i, j);
		g_player_count++;
		return (1);
	}
	return (0);
}

void	init_player(void)
{
	g_player.turn_direction = 0;
	g_player.walk_direction = 0;
	g_player.move_speed = 10;
	g_player.rotation_speed = 1 * (M_PI / 180);
	g_player.side = 0;
}

void	player_update(void)
{
	double	x;
	double	y;
	int		movestep;
	double	angle;

	if (g_player.side != 0)
	{
		angle = g_player.rotation_angle - M_PI / 2;
		movestep = g_player.side * g_player.move_speed;
		x = g_player.x + cosf(angle) * movestep;
		y = g_player.y + sinf(angle) * movestep;
	}
	else
	{
		g_player.rotation_angle += g_player.turn_direction *
									g_player.rotation_speed;
		movestep = g_player.walk_direction * g_player.move_speed;
		x = g_player.x + cosf(g_player.rotation_angle) * movestep;
		y = g_player.y + sinf(g_player.rotation_angle) * movestep;
	}
	if (!grid_has_wall_at(x, g_player.y) && !grid_has_sprite_at(x, g_player.y))
		g_player.x = x;
	if (!grid_has_wall_at(g_player.x, y) && !grid_has_sprite_at(g_player.x, y))
		g_player.y = y;
	render_walls();
}
