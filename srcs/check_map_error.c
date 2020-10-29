/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:59:37 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/29 14:34:53 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	get_player_pos_map(int *r)
{
	int j;

	while (g_map[*r])
	{
		j = 0;
		while (g_map[*r][j])
		{
			if (g_map[*r][j] == 'N' || g_map[*r][j] == 'W'
				|| g_map[*r][j] == 'E' || g_map[*r][j] == 'S')
			{
				g_player.x = j * 200 + 100;
				g_player.y = *r * 200 + 100;
				if (g_map[*r][j] == 'N')
					g_player.rotation_angle = (3 * M_PI) / 2;
				else if (g_map[*r][j] == 'S')
					g_player.rotation_angle = M_PI / 2;
				else if (g_map[*r][j] == 'E')
					g_player.rotation_angle = 0;
				else if (g_map[*r][j] == 'W')
					g_player.rotation_angle = M_PI;
			}
			j++;
		}
		*r += 1;
	}
}

void	check_map_sides(int r, int i)
{
	if (g_map[0][i] != '1')
	{
		if (g_map[0][i] == ' ')
		{
			if (g_map[1][i] == '0' || g_map[1][i] == '2')
				ft_map_error(0, i);
		}
		else
			ft_map_error(0, i);
	}
	if (g_map[r - 1][i] != '1')
	{
		if (g_map[r - 1][i] == ' ')
		{
			if (g_map[r - 2][i] == '0' || g_map[r - 2][i] == '2')
				ft_map_error(r - 2, i);
		}
		else
			ft_map_error(r - 1, i);
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
				|| g_map[i + 1][j] == '0' || g_map[i - 1][j] == '0')
				ft_map_error(i, j);
			else if (g_map[i][j + 1] == '2' || g_map[i][j - 1] == '2'
				|| g_map[i + 1][j] == '2' || g_map[i - 1][j] == '2')
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
		if (g_map[i][j] != '1')
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
}

void	check_map_errors(void)
{
	int i;
	int j;
	int t;
	int r;

	r = 0;
	t = 0;
	i = 0;
	get_player_pos_map(&r);
	while (g_map[i])
	{
		j = 0;
		check_map_sides(r, i);
		while (g_map[i][j])
		{
			check_map_insides(r, i, j);
			if (
			g_map[i][j] != 'N' && g_map[i][j] != 'S' && g_map[i][j] != 'E' &&
			g_map[i][j] != 'W' && g_map[i][j] != '1' && g_map[i][j] != '0' &&
			g_map[i][j] != '0' && g_map[i][j] != '2' && g_map[i][j] != ' ')
				ft_map_error(i, j);
			j++;
		}
		i++;
	}
}
