/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:58:03 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/12 11:23:15 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		check_resolution_error(char **resolution, int i)
{
	int j;

	if (i > 2)
	{
		free_double_pointer(resolution);
		return (1);
	}
	j = 0;
	while (resolution[i][j])
	{
		if (resolution[i][j] < '0' || resolution[i][j] > '9')
		{
			free_double_pointer(resolution);
			return (1);
		}
		j++;
	}
	return (0);
}

void	save_resolution(char **resolution)
{
	int i;

	i = 1;
	while (resolution[i])
	{
		if (check_resolution_error(resolution, i))
			return (ft_error("Error\nResolution is invalid"));
		if (i == 1)
		{
			g_win_width = ft_atoi(resolution[1]);
			g_win_width = g_win_width > 2560 ? 2560 : g_win_width;
			if (g_win_width < 0)
				ft_error("Error\nIncorrect resolution");
		}
		else if (i == 2)
		{
			g_win_height = ft_atoi(resolution[2]);
			g_win_height = g_win_height > 1440 ? 1440 : g_win_height;
			if (g_win_height < 0)
				ft_error("Error\nIncorrect resolution");
		}
		i++;
	}
	free_double_pointer(resolution);
}
