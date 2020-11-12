/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 10:25:15 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/12 10:27:04 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		check_if_valid(int i, int j)
{
	if (!is_player(i, j) && g_map[i][j] != '1' && g_map[i][j] != '0'
		&& g_map[i][j] != '2' && g_map[i][j] != ' ')
		ft_map_error(i, j);
}

void		check_next_row(int i, int j, char c, int curr_len)
{
	int next_len;

	next_len = 0;
	if (g_map[i + 1])
		next_len = ft_strlen(g_map[i + 1]);
	if (next_len >= curr_len)
	{
		if (g_map[i + 1][j] == c)
			ft_map_error(i, j);
	}
	else if (c == ' ' && j > next_len)
		ft_map_error(i, j);
}

void		check_prev_row(int i, int j, char c, int curr_len)
{
	if (g_prev_len >= curr_len)
	{
		if (g_map[i - 1][j] == c)
			ft_map_error(i, j);
	}
	else if (c == ' ' && j > g_prev_len)
		ft_map_error(i, j);
}

void		check_up_down(int i, int j, char c, int curr_len)
{
	check_next_row(i, j, c, curr_len);
	check_prev_row(i, j, c, curr_len);
}
