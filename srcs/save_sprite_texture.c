/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_sprite_texture.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:14:38 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/26 13:34:52 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	save_sprite_texture(char **texture)
{
	int i;

	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		printf("Sprite number of information is incorrect\n");
	g_sp_image.texture = strdup(texture[1]);
	free_double_pointer(texture);
	printf("%s\n", g_sp_image.texture);
}
