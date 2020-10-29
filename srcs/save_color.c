/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:49:03 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/29 13:55:09 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	count_element(char **element)
{
	int el_count;

	el_count = 0;
	while (element[el_count])
		el_count++;
	if (el_count > 3)
		printf("Floor count is incorrect\n");
}

void	save_floor_color(char **element)
{
	int		i;
	char	**floor_color_char;

	i = 0;
	while (element[i])
		i++;
	if (i != 2)
		printf("Floor information are incorrect\n");
	i = 0;
	while (element[1][i])
	{
		if (element[1][i] != ',' && (element[1][i] < '0'
			|| element[1][i] > '9'))
			printf("Floor information are incorrect\n");
		i++;
	}
	floor_color_char = ft_split(element[1], ',');
	count_element(floor_color_char);
	g_floor_color[0] = ft_atoi(floor_color_char[0]);
	g_floor_color[1] = ft_atoi(floor_color_char[1]);
	g_floor_color[2] = ft_atoi(floor_color_char[2]);
	free_double_pointer(floor_color_char);
	free_double_pointer(element);
	printf("%d %d %d\n", g_floor_color[0], g_floor_color[1], g_floor_color[2]);
}

void	save_ceilling_color(char **element)
{
	int		i;
	char	**floor_ceilling_char;

	i = 0;
	while (element[i])
		i++;
	if (i != 2)
		printf("Ceiling information are incorrect\n");
	i = 0;
	while (element[1][i])
	{
		if (element[1][i] != ',' && (element[1][i] < '0'
			|| element[1][i] > '9'))
			printf("Ceiling information are incorrect\n");
		i++;
	}
	floor_ceilling_char = ft_split(element[1], ',');
	count_element(floor_ceilling_char);
	g_ceilling_color[0] = ft_atoi(floor_ceilling_char[0]);
	g_ceilling_color[1] = ft_atoi(floor_ceilling_char[1]);
	g_ceilling_color[2] = ft_atoi(floor_ceilling_char[2]);
	free_double_pointer(floor_ceilling_char);
	free_double_pointer(element);
	printf("%d %d %d\n", g_ceilling_color[0],
					g_ceilling_color[1], g_ceilling_color[2]);
}
