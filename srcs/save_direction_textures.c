/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_direction_textures.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:56:14 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/19 19:57:47 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "../cub1.h"

void	save_north_texture(char **texture)
{
	int i;

	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		printf("North number of information is incorrect\n");
	no_image.texture = texture[1];
	printf("%s\n", no_image.texture);
}

void	save_west_texture(char **texture)
{
	int i;

	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		printf("West number of information is incorrect)\n");
	we_image.texture = texture[1];
	printf("%s\n", we_image.texture);
}

void	save_east_texture(char **texture)
{
	int i;

	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		printf("East number of information is incorrect)\n");
	ea_image.texture = texture[1];
	printf("%s\n", ea_image.texture);
}

void	save_south_texture(char **texture)
{
	int i;

	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		printf("South number of information is incorrect)\n");
	so_image.texture = texture[1];
	printf("%s\n", so_image.texture);
}
