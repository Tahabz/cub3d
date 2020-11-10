/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <mobaz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 11:22:26 by mobaz             #+#    #+#             */
/*   Updated: 2020/11/07 13:44:21 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

const int	g_win_width3d = 2000;
const int	g_win_height3d = 1200;
double		g_fov_angle = 60 * (M_PI / 180);
double		g_distance_proj_plane = 0;

double		normalize_angle(double angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

double		distance(double x, double y)
{
	return (sqrt((x - g_player.x) * (x - g_player.x) +
			(y - g_player.y) * (y - g_player.y)));
}

int			update(void)
{
	cast_rays();
	player_update();
	return (0);
}

void		render(void)
{
	init_player();
	cast_rays();
	render_walls();
	init_textures();
}

int			main(int c, char **v)
{
	g_att = 2;
	get_args(c, v);
	parse_file();
	check_missing_element();
	check_map_errors();
	g_win_height2d = TILE_SIZE * g_num_rows;
	add_sprite();
	g_mlx = mlx_init();
	g_window = mlx_new_window(g_mlx, g_win_width, g_win_height, "Cub3D");
	mlx_hook(g_window, 2, 0, key_pressed, NULL);
	mlx_hook(g_window, 3, 0, key_released, NULL);
	mlx_hook(g_window, 17, 0, free_memory, NULL);
	g_image = mlx_new_image(g_mlx, g_win_width, g_win_height);
	g_data = (int *)mlx_get_data_addr(g_image, &g_bits_per_pixel,
										&g_size_line, &g_endian);
	get_image();
	render();
	mlx_loop_hook(g_mlx, update, (void *)0);
	mlx_loop(g_mlx);
	return (0);
}
