/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:04:54 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/12 10:28:22 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		check_surrounding(int i, int j, char c)
{
	int curr_len;

	curr_len = ft_strlen(g_map[i]);
	if (j > 0 && g_map[i][j - 1] == c)
		ft_map_error(i, j);
	if (j <= curr_len)
		if (g_map[i][j + 1] == c)
			ft_map_error(i, j);
	check_next_row(i, j, c, curr_len);
	check_prev_row(i, j, c, curr_len);
}

void		check_error(int i, int j)
{
	if (g_map[i][j] != '1')
	{
		if (g_map[i][j] != ' ')
			check_surrounding(i, j, ' ');
		else
		{
			check_surrounding(i, j, '0');
			check_surrounding(i, j, '2');
		}
	}
}

void		map_error(void)
{
	int i;
	int j;

	i = 0;
	while (g_map[i])
	{
		j = 0;
		while (g_map[i][j])
		{
			check_if_valid(i, j);
			check_error(i, j);
			j++;
		}
		g_prev_len = j;
		i++;
	}
	if (g_player_count == 0)
		ft_error("Error\nPlayer does not exist");
}
