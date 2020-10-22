/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:48:33 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/21 19:05:11 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "../cub1.h"

// void render_player()
// {
// 	//rect(player.x, player.y, 200, 20);
// 	//data[(int)((player.y)*WINDOW_WIDTH2D + player.x)] = 200;
// 	//line(player.rotationAngle);
// }

void	init_player(void)
{
	g_player.turnDirection = 0;
	g_player.walkDirection = 0;
	g_player.moveSpeed = 30;
	g_player.rotationSpeed = 1 * (M_PI / 180);
}

void	player_update(void)
{
	double	x;
	double	y;
	int		movestep;

	g_player.rotationAngle += g_player.turnDirection * g_player.rotationSpeed;
	movestep = g_player.walkDirection * g_player.moveSpeed;
	x = g_player.x + cosf(g_player.rotationAngle) * movestep;
	y = g_player.y + sinf(g_player.rotationAngle) * movestep;
	if (!grid_has_wall_at(x, g_player.y) && !grid_has_sprite_at(x, g_player.y))
		g_player.x = x;
	if (!grid_has_wall_at(g_player.x, y) && !grid_has_sprite_at(g_player.x, y))
		g_player.y = y;
	render_walls();
	//render_grid();
}
