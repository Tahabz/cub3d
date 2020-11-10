/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_direction_textures.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:56:14 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/07 13:42:23 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	save_north_texture(char **texture)
{
	int i;

	if (g_no_image.status == 1)
		ft_error("Error\nDuplicate north element");
	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		ft_error("Error\nNorth number of information is incorrect\n");
	g_no_image.texture = strdup(texture[1]);
	g_no_image.status = 1;
	free_double_pointer(texture);
}

void	save_west_texture(char **texture)
{
	int i;

	if (g_we_image.status == 1)
		ft_error("Error\nDuplicate west element");
	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		ft_error("Error\nWest number of information is incorrect)\n");
	g_we_image.texture = strdup(texture[1]);
	g_we_image.status = 1;
	free_double_pointer(texture);
}

void	save_east_texture(char **texture)
{
	int i;

	if (g_ea_image.status == 1)
		ft_error("Error\nDuplicate east element");
	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		ft_error("Error\nEast number of information is incorrect)\n");
	g_ea_image.texture = strdup(texture[1]);
	free_double_pointer(texture);
	g_ea_image.status = 1;
}

void	save_south_texture(char **texture)
{
	int i;

	if (g_so_image.status == 1)
		ft_error("Error\nDuplicate south element");
	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		ft_error("Error\nSouth number of information is incorrect)\n");
	g_so_image.texture = strdup(texture[1]);
	g_so_image.status = 1;
	free_double_pointer(texture);
}
