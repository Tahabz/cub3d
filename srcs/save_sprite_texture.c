/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_sprite_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:14:38 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/07 13:41:05 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	save_sprite_texture(char **texture)
{
	int i;

	if (g_sp_image.status == 1)
		ft_error("Error\nDuplicate sprite element");
	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		ft_error("Error\nSprite number of information is incorrect\n");
	g_sp_image.texture = strdup(texture[1]);
	g_sp_image.status = 1;
	free_double_pointer(texture);
}
