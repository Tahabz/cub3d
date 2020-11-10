/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:13:57 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/07 12:43:20 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	get_player_pos_map(int i, int j)
{
	if (g_map[i][j] == 'N' || g_map[i][j] == 'W'
		|| g_map[i][j] == 'E' || g_map[i][j] == 'S')
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
		g_player_count += 1;
	}
}

void	check_map_sides(int r, int i, int j)
{
	if (i == 0)
		if (g_map[0][j] != '1')
		{
			if (g_map[0][j] == ' ')
			{
				if (g_map[1][j] == '0' || g_map[1][j] == '2')
					ft_map_error(0, j);
			}
			else
				ft_map_error(0, j);
		}
	if (i == r - 1)
		if (g_map[r - 1][j] != '1')
		{
			if (g_map[r - 1][j] == ' ')
			{
				if (g_map[r - 2][j] == '0' || g_map[r - 2][j] == '2')
					ft_map_error(r - 2, j);
			}
			else
				ft_map_error(r - 1, j);
		}
	if (g_map[i][0] != '1' && g_map[i][0] != ' ')
		ft_map_error(i, 0);
}

void	check_index_surrounding(int i, int j, int r, int t)
{
	if (j <= t && g_map[i][j + 1])
	{
		if (j > 0 && i > 0 && i < r - 1)
		{
			if (g_map[i][j + 1] == '0' || g_map[i][j - 1] == '0'
				|| g_map[i + 1][j] == '0' || g_map[i - 1][j] == '0'
				|| g_map[i - 1][j - 1] == '0' || g_map[i - 1][j + 1] == '0')
				ft_map_error(i, j);
			else if (g_map[i][j + 1] == '2' || g_map[i][j - 1] == '2'
				|| g_map[i + 1][j] == '2' || g_map[i - 1][j] == '2'
				|| g_map[i - 1][j - 1] == '0' || g_map[i - 1][j + 1] == '0')
				ft_map_error(i, j);
			else if (is_player(i, j))
				ft_map_error(i, j);
		}
	}
}

void	check_map_insides(int r, int i, int j)
{
	int t;

	if (g_map[i][j + 1] == '\0')
	{
		t = j;
		if (g_map[i][j] != '1' && g_map[i][j] != ' ')
			ft_map_error(i, j);
	}
	if (g_map[i][j] == ' ')
		check_index_surrounding(i, j, r, t);
	if (g_map[i][j] == '0')
	{
		if (j > t && t != 0)
			ft_map_error(i, j);
		else if (g_map[i - 1][j] == ' ')
			ft_map_error(i, j);
	}
	if (i < g_num_rows - 1 && g_map[i][j + 1] == '\0')
		if (g_map[i + 1][j] && g_map[i + 1][j] != '1' && g_map[i + 1][j] != ' ')
			ft_map_error(i, j);
}

void	check_map_errors(void)
{
	int i;
	int j;

	g_player_count = 0;
	i = 0;
	while (g_map[i])
	{
		j = 0;
		while (g_map[i][j])
		{
			get_player_pos_map(i, j);
			check_map_sides(g_num_rows, i, j);
			check_map_insides(g_num_rows, i, j);
			if (
			g_map[i][j] != 'N' && g_map[i][j] != 'S' && g_map[i][j] != 'E' &&
			g_map[i][j] != 'W' && g_map[i][j] != '1' && g_map[i][j] != '0' &&
			g_map[i][j] != '0' && g_map[i][j] != '2' && g_map[i][j] != ' ')
				ft_map_error(i, j);
			j++;
		}
		i++;
	}
	if (g_player_count == 0 || g_player_count > 1)
		ft_error("Error\nPlayer count is invalid");
}
