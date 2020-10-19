/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:58:03 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/19 19:58:46 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "../cub1.h"

void	save_resolution(char **resolution)
{
	int i;
	int j;

	i = 1;
	while (resolution[i])
	{
		if (i > 2)
			printf("Resolution number of information is invalid)\n");
		j = 0;
		while (resolution[i][j])
		{
			if (resolution[i][j] < '0' || resolution[i][j] > '9')
				printf("The resolution should be a number\n");
			j++;
		}
		if (i == 1)
			win_width = atoi(resolution[i]);
		else if (i == 2)
			win_height = atoi(resolution[i]);
		i++;
	}
	printf("%d %d\n", win_height, win_width);
}
