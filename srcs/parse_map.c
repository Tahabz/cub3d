/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:48:09 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/12 10:35:11 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	**ft_reallocate(int i)
{
	char	**new_map;
	int		j;

	j = 0;
	new_map = (char **)malloc((i + 1) * sizeof(char *));
	while (j < i)
	{
		new_map[j] = g_map[j];
		j++;
	}
	new_map[j] = 0;
	free(g_map);
	return (new_map);
}

void	parse_map(int fd, char *line)
{
	int i;
	int j;

	j = 1;
	i = 1;
	g_map = (char **)malloc(2 * sizeof(char *));
	g_map[0] = line;
	while (j)
	{
		j = get_next_line(fd, &line);
		g_map[i] = line;
		i += 1;
		g_map = ft_reallocate(i);
	}
	g_num_rows = i;
	map_error();
}
