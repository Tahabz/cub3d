/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:11:31 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/21 19:05:11 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "../cub1.h"

int		key_pressed(int key, void *param)
{
	param = NULL;
	if (key == UP_ARROW)
		g_player.walkDirection = +1;
	else if (key == DOWN_ARROW)
		g_player.walkDirection = -1;
	else if (key == LEFT_ARROW)
		g_player.turnDirection = -1;
	else if (key == RIGHT_ARROW)
		g_player.turnDirection = +1;
	return (1);
}

int		key_released(int key, void *param)
{
	param = NULL;
	if (key == UP_ARROW)
		g_player.walkDirection = 0;
	else if (key == DOWN_ARROW)
		g_player.walkDirection = 0;
	if (key == LEFT_ARROW)
		g_player.turnDirection = 0;
	else if (key == RIGHT_ARROW)
		g_player.turnDirection = 0;
	return (0);
}
