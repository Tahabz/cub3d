/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:09:21 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/07 13:47:23 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	check_texture(void)
{
	if (!g_no_image.texture || !g_sp_image.texture || !g_ea_image.texture
		|| !g_so_image.texture || !g_we_image.texture)
		ft_error("Error\nMissing texture");
}

void	init_images(void)
{
	g_no_image.image = NULL;
	g_sp_image.image = NULL;
	g_ea_image.image = NULL;
	g_so_image.image = NULL;
	g_we_image.image = NULL;
}

void	get_data(void)
{
	g_no_image.data = (int *)mlx_get_data_addr(
		g_no_image.image, &g_no_image.bpp, &g_no_image.sl, &g_no_image.end);
	g_sp_image.data = (int *)mlx_get_data_addr(
		g_sp_image.image, &g_sp_image.bpp, &g_sp_image.sl, &g_sp_image.end);
	g_ea_image.data = (int *)mlx_get_data_addr(
		g_ea_image.image, &g_ea_image.bpp, &g_ea_image.sl, &g_ea_image.end);
	g_so_image.data = (int *)mlx_get_data_addr(
		g_so_image.image, &g_so_image.bpp, &g_so_image.sl, &g_so_image.end);
	g_we_image.data = (int *)mlx_get_data_addr(
		g_we_image.image, &g_we_image.bpp, &g_we_image.sl, &g_we_image.end);
}

void	get_image(void)
{
	check_texture();
	init_images();
	g_no_image.image = mlx_xpm_file_to_image(
		g_mlx, g_no_image.texture, &(g_no_image.width), &(g_no_image.height));
	g_sp_image.image = mlx_xpm_file_to_image(
		g_mlx, g_sp_image.texture, &(g_sp_image.width), &(g_sp_image.height));
	g_ea_image.image = mlx_xpm_file_to_image(
		g_mlx, g_ea_image.texture, &(g_ea_image.width), &(g_ea_image.height));
	g_so_image.image = mlx_xpm_file_to_image(
		g_mlx, g_so_image.texture, &(g_so_image.width), &(g_so_image.height));
	g_we_image.image = mlx_xpm_file_to_image(
		g_mlx, g_we_image.texture, &(g_we_image.width), &(g_we_image.height));
	if (!g_no_image.image || !g_sp_image.image || !g_ea_image.image
		|| !g_so_image.image || !g_we_image.image)
		ft_error("Error\nSomething is wrong with the images");
	get_data();
}
