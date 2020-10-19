#include "../cub.h"
#include "../cub1.h"

void render_walls()
{
	int i;
	double ray_distance;
	double wall_strip_height;
	double walltop, wallbottom;
	int j;

	i = 0;
	distance_proj_plane = (win_width / 2) / tanf(FOV_ANGLE / 2);
	while (i < win_width)
	{
		j = 0;
		ray_distance = rays[i].distance * cosf(rays[i].rayAngle - player.rotationAngle);
		wall_strip_height = ((double)TILE_SIZE / ray_distance) * (double)distance_proj_plane;
		walltop = ((double)win_height / 2) - (wall_strip_height / 2);
		walltop = walltop < 0 ? 0 : walltop;
		wallbottom = ((double)win_height / 2) + (wall_strip_height / 2);
		wallbottom = wallbottom > win_height ? win_height : wallbottom;
		while (j < walltop)
			data[(j++ * win_width) + i] = 0;
		j = wallbottom;
		while (j < win_height)
			data[(j++ * win_width) + i] = 200;
		line3d_walls(walltop, wallbottom, wall_strip_height, i);
	//	j = walltop;
		// while (j < wallbottom)
		// 	data[(j++ * win_width) + i] = 20000;
		++i;
	}
	render_sprite();
	mlx_put_image_to_window(mlx, window, image, 0, 0);
}
