/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <marvin@41.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 10,,10,/0,1/0,4 1,5:41:0,6 by mobaz             #+#    #+#      */
/*   Updated: 2020/02/05 15:56:10 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "../cub1.h"


const int WINDOW_WIDTH3D = 2000;
const int WINDOW_HEIGHT3D  = 1200;
double FOV_ANGLE = 60 * (M_PI / 180);
double distance_proj_plane = 0;

double normalizeAngle(double angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return angle;
}

//Distance Between two points
double distance(double x, double y)
{
	return (sqrt((x - player.x) * (x - player.x) + (y - player.y) * (y - player.y)));
}
//Drawing a rectangle
// void rect(int tileX, int tileY, unsigned int tilecol, int size)
// {
// 	int a = size;
// 	int b = size;
// 	double tempx = tileX;
// 	double tempy = tileY;

// 	while (a)
// 	{
// 		b = size;
// 		tempx = tileX;
// 		while (b)
// 		{
// 			data[(int)((tempy)*WINDOW_WIDTH2D + tempx)] = tilecol;
// 			b--;
// 			tempx++;
// 		}
// 		tempy++;
// 		a--;
// 	}
// }

// void line3d(int tileX, int tileY, int height, unsigned int tilecol)
// {
// 	while (height >= 0)
// 	{
// 		if (tileY >= 0 && tileY < win_height && tileX >= 0 && tileX < win_width)
// 			data[(int)((tileY)*win_width + tileX)] = tilecol;
// 		tileY++;
// 		height--;
// 	}
// }


// void line(double angle, int x, int y)
// {
// 	int i = (int)sqrt((x - player.x) * (x - player.x) + (y - player.y) * (y - player.y));
// 	int x1, y1;
// 	while (i)
// 	{
// 		x1 = (int)(player.x + cosf(angle) * i);
// 		y1 = (int)(player.y + sinf(angle) * i);
// 		if (y1 >= 0 && y1 < WINDOW_HEIGHT2D && x1 >= 0 && x1 < WINDOW_WIDTH2D)
// 			data[(y1)*WINDOW_WIDTH2D + x1] = 200;
// 		i--;
// 	}
// }

//Drawing a line

//------------------------------------------Player functions----------------------------------------



// void render_grid()
// {
// 	int j, i = 0;
// 	int tileX;
// 	int tileY;
// 	unsigned int tilecol;

// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			tileX = j * TILE_SIZE;
// 			tileY = i * TILE_SIZE;
// 			tilecol = map[i][j] == '1' ? 0 : 0xffffff;
// 			rect(tileX, tileY, tilecol, TILE_SIZE);
// 			j++;
// 		}
// 		i++;
// 	}
// }

//----------------------------------------Ray Casting Functions--------------------------------------



void init_ray(double rayAngle)
{
	ray.rayAngle = rayAngle;
	ray.distance = 0;
	ray.wall_hit_x = 0;
	ray.wall_hit_y = 0;
	ray.isRayFacingDown = (rayAngle > 0 && rayAngle < M_PI);
	ray.isRayFacingUp = !ray.isRayFacingDown;
	ray.isRayFacingRight = ((rayAngle < 0.5 * M_PI) || (rayAngle > 1.5 * M_PI));
	ray.isRayFacingLeft = !ray.isRayFacingRight;
}

void castAllRays()
{
	rays = (t_rays *)malloc(/*WINDOW_WIDTH2D*/win_width * sizeof(t_rays));
	double rayAngle = player.rotationAngle - (FOV_ANGLE / 2);
	int i = 0;
	while (i < /*WINDOW_WIDTH2D*/win_width)
	{
		init_ray(normalizeAngle(rayAngle));
		render_ray();
		rays[i] = ray;
		rayAngle += (FOV_ANGLE / (win_width));
		i++;
	}
}

//----------------------------------------rendering and updating-------------------------------------


int update()
{
	
	castAllRays();
	player_update();
	return (0);
}

void render()
{
	init_player();
	//render_grid();
	//render_player();
	castAllRays();
	render_walls();
}

int main(void)
{
	int a, b, c;
	parse_file();
	check_map_errors();
	add_sprite();
	mlx = mlx_init();
	window = mlx_new_window(mlx, win_width, win_height, "Cub3D");
	mlx_hook(window, 2, 0, keyPressed, NULL);
	mlx_hook(window, 3, 0, keyReleased, NULL);
	image = mlx_new_image(mlx, win_width, win_height);
	data = (int *)mlx_get_data_addr(image, &a, &b, &c);
	get_image();
	render();
	mlx_loop_hook(mlx, update, (void *)0);
	mlx_loop(mlx);
	return (0);
}
