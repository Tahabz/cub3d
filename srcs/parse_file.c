/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:16:49 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/11 12:58:40 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_missing_element(void)
{
	if (!g_win_height || !g_win_width)
		ft_error("Error\nMissing resolution information");
	if (!g_floor_color[3])
		ft_error("Error\nMissing floor information");
	if (!g_ceilling_color[3])
		ft_error("Error\nMissing ceilling information");
}

int		get_elements(int fd, char *line)
{
	char	**element;
	int		i;

	if (*line)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (line[i] == '1' || line[i] == '0')
		{
			parse_map(fd, line);
			return (1);
		}
		else
		{
			element = ft_split(line, ' ');
			if (!*element)
				ft_error("Error\nInvalid file configuration");
			check_element(element);
		}
	}
	return (0);
}

void	parse_file(void)
{
	int		fd;
	char	*line;
	int		status;

	status = 0;
	fd = open(g_file, O_RDONLY);
	if (fd > 0)
	{
		while ((status = get_next_line(fd, &line)))
		{
			if (get_elements(fd, line) == 1)
				return ;
			free(line);
		}
		if (status == 0)
			ft_error("Error\nInvalid file configuration");
	}
	else
		ft_error("Error\ninvalid file\n");
}
