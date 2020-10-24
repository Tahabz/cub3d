/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:48:33 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/23 11:47:40 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_player(void)
{
	g_player.turn_direction = 0;
	g_player.walk_direction = 0;
	g_player.move_speed = 30;
	g_player.rotation_speed = 1 * (M_PI / 180);
}

void	player_update(void)
{
	double	x;
	double	y;
	int		movestep;

	g_player.rotation_angle += g_player.turn_direction *
								g_player.rotation_speed;
	movestep = g_player.walk_direction * g_player.move_speed;
	x = g_player.x + cosf(g_player.rotation_angle) * movestep;
	y = g_player.y + sinf(g_player.rotation_angle) * movestep;
	if (!grid_has_wall_at(x, g_player.y) && !grid_has_sprite_at(x, g_player.y))
		g_player.x = x;
	if (!grid_has_wall_at(g_player.x, y) && !grid_has_sprite_at(g_player.x, y))
		g_player.y = y;
	render_walls();
}
