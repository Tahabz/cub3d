/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 11:59:40 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/13 13:40:59 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_element(char **element)
{
	if (ft_strcmp(element[0], "R") == 0)
		save_resolution(element);
	else if (ft_strcmp(element[0], "NO") == 0)
		save_north_texture(element);
	else if (ft_strcmp(element[0], "SO") == 0)
		save_south_texture(element);
	else if (ft_strcmp(element[0], "EA") == 0)
		save_east_texture(element);
	else if (ft_strcmp(element[0], "WE") == 0)
		save_west_texture(element);
	else if (ft_strcmp(element[0], "S") == 0)
		save_sprite_texture(element);
	else if (ft_strcmp(element[0], "F") == 0)
		save_floor_color(element);
	else if (ft_strcmp(element[0], "C") == 0)
		save_ceilling_color(element);
	else
		ft_error("Error\nInvalid elements");
}
