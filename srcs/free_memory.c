/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 12:19:09 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/26 13:39:25 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	free_double_pointer(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

void	free_images()
{
	free(g_so_image.data);
	free(g_so_image.image);
	free(g_so_image.texture);
	free(g_we_image.data);
	free(g_we_image.image);
	free(g_we_image.texture);
	free(g_ea_image.data);
	free(g_ea_image.image);
	free(g_ea_image.texture);
	free(g_no_image.data);
	free(g_no_image.image);
	free(g_no_image.texture);
	free(g_sp_image.data);
	free(g_sp_image.image);
	free(g_sp_image.texture);
}

void	free_memory()
{
	free_double_pointer(g_map);
	free_images();
	free(g_rays);
	free(g_mlx);
	free(g_image);
	free(g_data);
	free(g_window);
	exit(0);
}
