/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:16:49 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/23 11:47:02 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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
			check_element(element);
		}
	}
	return (0);
}

void	parse_file(void)
{
	int		fd;
	char	*line;

	fd = open("file.cub", O_RDONLY);
	if (fd)
	{
		while (get_next_line(fd, &line))
		{
			if (get_elements(fd, line) == 1)
				return ;
			free(line);
		}
	}
	else
		printf("invalid file\n");
}
