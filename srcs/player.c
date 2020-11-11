/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:48:33 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/11 19:06:15 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

// int		is_player(int i, int j)
// {
// 	if (g_map[i][j - 1] == 'N' || g_map[i][j - 1] == 'W'
// 		|| g_map[i][j - 1] == 'E' || g_map[i][j - 1] == 'S')
// 		return (1);
// 	else if (g_map[i][j + 1] == 'N' || g_map[i][j + 1] == 'W'
// 		|| g_map[i][j + 1] == 'E' || g_map[i][j + 1] == 'S')
// 		return (1);
// 	else if (g_map[i + 1][j] == 'N' || g_map[i + 1][j] == 'W'
// 		|| g_map[i + 1][j] == 'E' || g_map[i + 1][j] == 'S')
// 		return (1);
// 	else if (g_map[i - 1][j] == 'N' || g_map[i - 1][j] == 'W'
// 		|| g_map[i - 1][j] == 'E' || g_map[i - 1][j] == 'S')
// 		return (1);
// 	else if (g_map[i - 1][j - 1] == 'N' || g_map[i - 1][j - 1] == 'W'
// 		|| g_map[i - 1][j - 1] == 'E' || g_map[i - 1][j - 1] == 'S')
// 		return (1);
// 	else if (g_map[i - 1][j + 1] == 'N' || g_map[i - 1][j + 1] == 'W'
// 		|| g_map[i - 1][j + 1] == 'E' || g_map[i - 1][j + 1] == 'S')
// 		return (1);
// 	else
// 		return (0);
// }

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
