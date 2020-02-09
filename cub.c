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

#include "cub.h"
#include "cub1.h"



// //Normalize Angle
// float normalizeAngle(float angle)
// {
// 	angle = angle / (2 * M_PI);
// 	if (angle < 0)
// 		angle = (2 * M_PI) + angle;
// 	return angle;
// }

//Drawing a rectangle
void	rect(int tileX, int tileY, unsigned int tilecol, int size)
{
	int a = size;
	int b = size;
	float tempx = tileX;
	float tempy = tileY;

	while (a)
	{
		b = size;
		tempx = tileX;
		while (b)
		{
			//mlx_pixel_put(mlx, window, tempx, tempy, tilecol);
			data[(int)((tempy)*WINDOW_WIDTH + tempx)] = tilecol;
			b--;
			tempx++;
		}
		tempy++;
		a--;
	}
}

//Drawing a line
void	line(float angle)
{
	int i = 90;
	int x1, y1;
	while (i)
	{
		x1 = player.x + cos(angle) * i;
		y1 = player.y + sin(angle) * i;
		data[(y1)*WINDOW_WIDTH + x1] = 200;
		i--;
	}
}

//------------------------------------------Player functions----------------------------------------

int		keyPressed(int key, void *param)
{
	if (key == UP_ARROW)
		player.walkDirection = +1;
	else if (key == DOWN_ARROW)
		player.walkDirection = -1;
	else if (key == LEFT_ARROW)
		player.turnDirection = -1;
	else if (key == RIGHT_ARROW)
		player.turnDirection = +1;
	return 1;
}

int		keyReleased(int key, void *param)
{
	if (key == UP_ARROW)
		player.walkDirection = 0;
	else if (key == DOWN_ARROW)
		player.walkDirection = 0;
	if (key == LEFT_ARROW)
		player.turnDirection = 0;
	else if (key == RIGHT_ARROW)
		player.turnDirection = 0;
	return 0;
}

void render_player()
{
	//rect(player.x, player.y, 200, 20);
	data[(int)((player.y)*WINDOW_WIDTH + player.x)] = 200;
	line(player.rotationAngle);
}

void	init_player()
{
	player.x = WINDOW_WIDTH / 2;
	player.y = WINDOW_HEIGHT / 2;
	player.turnDirection = 0;
	player.walkDirection = 0;
	player.rotationAngle = M_PI / 2;
	player.moveSpeed = 1.0;
	player.rotationSpeed = 2 * (M_PI / 180);
}

void	player_update()
{
	player.rotationAngle += player.turnDirection * player.rotationSpeed;
	int movestep = player.walkDirection * player.moveSpeed;
	float x = player.x + cos(player.rotationAngle) * movestep;
	float y = player.y + sin(player.rotationAngle) * movestep;
	if (!grid_hasWallAt(x, y))
	{
		player.x = x;
		player.y = y;
	}
	render_grid();
	render_player();
}


//-------------------------------------grid functions---------------------------------------------

int		grid_hasWallAt(int x, int y)
{
	x = (x / TILE_SIZE);
	y = (y / TILE_SIZE);
	return (map[y][x] == 1);
}

void	render_grid()
{
	int j,i = 0;
	int tileX;
	int tileY;
	unsigned int tilecol;

	while (i < NUM_ROWS)
	{
		j = 0;
		while (j < NUM_COLS)
		{
			tileX = j * TILE_SIZE;
			tileY = i * TILE_SIZE;
			tilecol = map[i][j] == 1 ? 0 : 0xffffff;
			rect(tileX, tileY, tilecol, TILE_SIZE);
			j++;
		}
		i++;
	}
}

//----------------------------------------Ray Casting Functions--------------------------------------

void	render_ray(float rayAngle)
{
	line(rayAngle);
}

void	init_ray(float rayAngle)
{
	ray.rayAngle = rayAngle;
}

void	castAllRays()
{
	float FOV_ANGLE = 60 * (M_PI / 180);
	float WALL_STRIP_WIDTH = 1 ;
	int i = 0;
	float rayAngle = player.rotationAngle - (FOV_ANGLE / 2);
	while (i < NUM_RAYS)
	{
		init_ray(rayAngle);
		rays[i] = ray;
		render_ray(rayAngle);
		rayAngle += FOV_ANGLE / (NUM_RAYS);
		i++;
	}
}

//----------------------------------------rendering and updating-------------------------------------

int	update()
{
	mlx_hook(window, 2, 0, keyPressed, (void *)0);
	mlx_hook(window, 3, 0, keyReleased, (void *)0);
	mlx_put_image_to_window(mlx,window,image,0,0);
	player_update();
	castAllRays();
	return (0);	
}

void	render()
{
	int i;

	init_player();
	render_grid();
	render_player();
	castAllRays();
}

int main(void)
{	
	int a;

	mlx = mlx_init();
	window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Title");	
	image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data = (int *)mlx_get_data_addr(image, &a,&a,&a);
	render();
	mlx_loop_hook(mlx, update, (void *)0);
	mlx_loop(mlx);
	return (0);
}
