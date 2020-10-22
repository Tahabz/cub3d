/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 12:09:21 by mobaz             #+#    #+#             */
/*   Updated: 2020/10/21 19:03:17 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "../cub1.h"

void	get_image(void)
{
	no_image.image = mlx_xpm_file_to_image(mlx, no_image.texture,
									&(no_image.width), &(no_image.height));
	no_image.data = (int *)mlx_get_data_addr(no_image.image,
									&no_image.bpp, &no_image.sl, &no_image.end);
	g_sp_image.image = mlx_xpm_file_to_image(mlx, g_sp_image.texture,
									&(g_sp_image.width), &(g_sp_image.height));
	g_sp_image.data = (int *)mlx_get_data_addr(g_sp_image.image,
									&g_sp_image.bpp, &g_sp_image.sl, &g_sp_image.end);
	ea_image.image = mlx_xpm_file_to_image(mlx, ea_image.texture,
									&(ea_image.width), &(ea_image.height));
	ea_image.data = (int *)mlx_get_data_addr(ea_image.image,
									&ea_image.bpp, &ea_image.sl, &ea_image.end);
	so_image.image = mlx_xpm_file_to_image(mlx, so_image.texture,
									&(so_image.width), &(so_image.height));
	so_image.data = (int *)mlx_get_data_addr(so_image.image,
									&so_image.bpp, &so_image.sl, &so_image.end);
	we_image.image = mlx_xpm_file_to_image(mlx, we_image.texture,
									&(we_image.width), &(we_image.height));
	we_image.data = (int *)mlx_get_data_addr(we_image.image,
									&we_image.bpp, &we_image.sl, &we_image.end);
}
