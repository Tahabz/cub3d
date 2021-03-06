/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:11:31 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/06 18:32:33 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		key_pressed(int key, void *param)
{
	param = NULL;
	if (key == UP_ARROW)
		g_player.walk_direction = +1;
	else if (key == DOWN_ARROW)
		g_player.walk_direction = -1;
	else if (key == 123)
		g_player.turn_direction = -1;
	else if (key == 124)
		g_player.turn_direction = +1;
	else if (key == LEFT_ARROW)
		g_player.side = +1;
	else if (key == RIGHT_ARROW)
		g_player.side = -1;
	else if (key == ESCAPE)
		free_memory(EXIT_SUCCESS);
	return (1);
}

int		key_released(int key, void *param)
{
	param = NULL;
	if (key == UP_ARROW)
		g_player.walk_direction = 0;
	else if (key == DOWN_ARROW)
		g_player.walk_direction = 0;
	if (key == 123)
		g_player.turn_direction = 0;
	else if (key == 124)
		g_player.turn_direction = 0;
	else if (key == LEFT_ARROW)
		g_player.side = 0;
	else if (key == RIGHT_ARROW)
		g_player.side = 0;
	else if (key == ESCAPE)
		free_memory(EXIT_SUCCESS);
	return (0);
}
