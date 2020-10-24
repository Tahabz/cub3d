/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:48:09 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/23 11:06:49 by mobaz            ###   ########.fr       */
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
		new_map[j] = ft_strdup(g_map[j]);
		j++;
	}
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
	g_map[0] = ft_strdup(line);
	free(line);
	while (j)
	{
		j = get_next_line(fd, &line);
		g_map[i] = ft_strdup(line);
		i += 1;
		g_map = ft_reallocate(i);
		free(line);
	}
	g_num_rows = i;
	g_map[i] = 0;
	i = 0;
	while (g_map[i])
		printf("%s\n", g_map[i++]);
	check_map_errors();
}
