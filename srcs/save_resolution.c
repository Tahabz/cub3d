/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:58:03 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/24 13:33:06 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	save_resolution(char **resolution)
{
	int i;
	int j;

	i = 1;
	while (resolution[i])
	{
		if (i > 2)
		{
			free_double_pointer(resolution);	
			return ft_error("Resolution number of information is invalid)");
		}
		j = 0;
		while (resolution[i][j])
		{
			if (resolution[i][j] < '0' || resolution[i][j] > '9')
			{
				free_double_pointer(resolution);
				return ft_error("The resolution should be a number");
			}
			j++;
		}
		if (i == 1)
			g_win_width = atoi(resolution[1]);
		else if (i == 2)
			g_win_height = atoi(resolution[2]);
		i++;
	}
	printf("%d %d\n", g_win_height, g_win_width);
}
