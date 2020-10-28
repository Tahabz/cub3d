/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:58:03 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/28 18:06:37 by mobaz            ###   ########.fr       */
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
			return (ft_error("Resolution number of information is invalid)"));
		if (i == 1)
			g_win_width = atoi(resolution[1]);
		else if (i == 2)
			g_win_height = atoi(resolution[2]);
		i++;
	}
	free_double_pointer(resolution);
	printf("%d %d\n", g_win_height, g_win_width);
}
