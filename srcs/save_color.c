/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 18:49:03 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/07 14:02:16 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	count_element(char **element)
{
	int el_count;

	el_count = 0;
	while (element[el_count])
		el_count++;
	if (el_count != 3)
		ft_error("Error\nFloor count is incorrect\n");
}

void	check_dup_element(int element)
{
	if (element == 1)
		ft_error("Error\nDuplicate element");
}

void	save_floor_color(char **element)
{
	int		i;
	char	**floor_color_char;

	check_dup_element(g_floor_color[3]);
	i = 0;
	while (element[i])
		i++;
	if (i != 2)
		ft_error("Error\nFloor information are incorrect\n");
	i = 0;
	while (element[1][i])
	{
		if (element[1][i] != ',' && (element[1][i] < '0'
			|| element[1][i] > '9'))
			ft_error("Error\nFloor information are incorrect\n");
		i++;
	}
	floor_color_char = ft_split(element[1], ',');
	count_element(floor_color_char);
	g_floor_color[0] = ft_atoi(floor_color_char[0]);
	g_floor_color[1] = ft_atoi(floor_color_char[1]);
	g_floor_color[2] = ft_atoi(floor_color_char[2]);
	g_floor_color[3] = 1;
	free_double_pointer(floor_color_char);
	free_double_pointer(element);
}

void	save_ceilling_color(char **element)
{
	int		i;
	char	**floor_ceilling_char;

	check_dup_element(g_ceilling_color[3]);
	i = 0;
	while (element[i])
		i++;
	if (i != 2)
		ft_error("Error\nCeiling information are incorrect\n");
	i = 0;
	while (element[1][i])
	{
		if (element[1][i] != ',' && (element[1][i] < '0'
			|| element[1][i] > '9'))
			ft_error("Error\nCeiling information are incorrect\n");
		i++;
	}
	floor_ceilling_char = ft_split(element[1], ',');
	count_element(floor_ceilling_char);
	g_ceilling_color[0] = ft_atoi(floor_ceilling_char[0]);
	g_ceilling_color[1] = ft_atoi(floor_ceilling_char[1]);
	g_ceilling_color[2] = ft_atoi(floor_ceilling_char[2]);
	g_ceilling_color[3] = 1;
	free_double_pointer(floor_ceilling_char);
	free_double_pointer(element);
}
