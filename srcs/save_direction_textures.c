/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_direction_textures.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:56:14 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/24 13:07:54 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	save_north_texture(char **texture)
{
	int i;

	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		printf("North number of information is incorrect\n");
	g_no_image.texture = texture[1];
	free(texture[0]);
	printf("%s\n", g_no_image.texture);
}

void	save_west_texture(char **texture)
{
	int i;

	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		printf("West number of information is incorrect)\n");
	g_we_image.texture = texture[1];
	free(texture[0]);
	printf("%s\n", g_we_image.texture);
}

void	save_east_texture(char **texture)
{
	int i;

	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		printf("East number of information is incorrect)\n");
	g_ea_image.texture = texture[1];
	free(texture[0]);
	printf("%s\n", g_ea_image.texture);
}

void	save_south_texture(char **texture)
{
	int i;

	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		printf("South number of information is incorrect)\n");
	g_so_image.texture = texture[1];
	free(texture[0]);
	printf("%s\n", g_so_image.texture);
}
