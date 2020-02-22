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



/**
* normalizeAngle
* @brief Normalizes the angle
* @param angle a float variable takes the angle
* @return returns the normalized angle
*/
float normalizeAngle(float angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return angle;
}

//Distance Between two points
float	distance(float x, float y)
{
	return (sqrt((x - player.x) * (x - player.x) + (y - player.y) * (y - player.y)));
}
//Drawing a rectangle
void	rect(int tileX, int tileY, /*int width*/ int height, unsigned int tilecol)
{
	int a = height;
	//int b = width;
	float tempx = tileX;
	float tempy = tileY;

	while (a >= 0)
	{
	//	b = width;
	//	tempx = tileX;
	//	while (b >= 0)
	//	{
			//mlx_pixel_put(mlx, window, tempx, tempy, tilecol);
			if (tempy >= 0 && tempy < WINDOW_HEIGHT3D && tempx >= 0 && tempx < WINDOW_WIDTH3D)
				data[(int)((tempy)*WINDOW_WIDTH3D + tempx)] = tilecol;
	//		b--;
	//		tempx++;
	//	}
		tempy++;
		a--;
	}
}

//Drawing a line


//------------------------------------------Player functions----------------------------------------

int		keyPressed(int key, void *param)
{
	param = NULL;
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
	param = NULL;
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
	//data[(int)((player.y)*WINDOW_WIDTH2D + player.x)] = 200;
	//line(player.rotationAngle);
}

void	init_player()
{
	player.x = WINDOW_WIDTH2D / 2;
	player.y = WINDOW_HEIGHT2D / 2;
	player.turnDirection = 0;
	player.walkDirection = 0;
	player.rotationAngle = M_PI / 2;
	player.moveSpeed = 5.0;
	player.rotationSpeed = 1 * (M_PI / 180);
}

void	player_update()
{
	player.rotationAngle += player.turnDirection * player.rotationSpeed;
	int movestep = player.walkDirection * player.moveSpeed;
	float x = player.x + cos(player.rotationAngle) * movestep;
	float y = player.y + sin(player.rotationAngle) * movestep;
	if (!grid_hasWallAt(x, player.y))
		player.x = x;
	if (!grid_hasWallAt(player.x, y))
		player.y = y;
	render_walls();
	//render_player();
}


//-------------------------------------grid functions---------------------------------------------

int		grid_hasWallAt(int x, int y)
{
	x = x / TILE_SIZE;
	y = y / TILE_SIZE;
	if (x >= 0 && x < NUM_COLS && y >= 0 && y < NUM_ROWS)
		return (map[y][x] == 1);
	return 1;
}

// void	render_grid()
// {
// 	int j,i = 0;
// 	int tileX;
// 	int tileY;
// 	unsigned int tilecol;

// 	while (i < NUM_ROWS)
// 	{
// 		j = 0;
// 		while (j < NUM_COLS)
// 		{
// 			tileX = j * TILE_SIZE;
// 			tileY = i * TILE_SIZE;
// 			tilecol = map[i][j] == 1 ? 0 : 0xffffff;
// 			rect(tileX, tileY, tilecol, TILE_SIZE);
// 			j++;
// 		}
// 		i++;
// 	}
// }

//----------------------------------------Ray Casting Functions--------------------------------------

void	render_ray()
{
	float yintersection, xintersection;
	float xstep, ystep;
	float horWallHitX, horWallHitY, horDistance = 1000000000;

	//---------------CLOSEST HORIZONTAL GRID INTERSECTION------------------------
	yintersection = floorf(player.y / TILE_SIZE) * TILE_SIZE;
	yintersection += (ray.isRayFacingDown ? TILE_SIZE : 0);
	xintersection = player.x + (yintersection - player.y) / tan(ray.rayAngle);
	ystep = TILE_SIZE;
	ystep *= (ray.isRayFacingUp ? -1 : 1);
	xstep = TILE_SIZE / tan(ray.rayAngle);
	xstep *= (ray.isRayFacingLeft && xstep > 0) ? -1 : 1;
	xstep *= (ray.isRayFacingRight && xstep < 0) ? -1 : 1;

	horWallHitX = xintersection;
	horWallHitY = yintersection;
	 if(ray.isRayFacingUp)
	 	horWallHitY--;
	while (horWallHitY >= 0 && horWallHitY < WINDOW_HEIGHT2D && horWallHitX >= 0 && horWallHitX < WINDOW_WIDTH2D)
	{
		if (grid_hasWallAt(horWallHitX, horWallHitY))
		{
			horDistance = distance(horWallHitX, horWallHitY);
			break;
		}
		horWallHitX += xstep;
		horWallHitY += ystep;
	}
	//---------------CLOSEST ------------------------

	float verWallHitX, verWallHitY, verDistance = 1000000000;

	xintersection = floorf(player.x / TILE_SIZE) * TILE_SIZE;
	xintersection += (ray.isRayFacingRight ? TILE_SIZE : 0);
	yintersection = player.y + (xintersection - player.x) * tan(ray.rayAngle);
	xstep = TILE_SIZE;
	xstep *= (ray.isRayFacingLeft ? -1 : 1);
	ystep = TILE_SIZE * tan(ray.rayAngle);
	ystep *= (ray.isRayFacingUp && ystep > 0) ? -1 : 1;
	ystep *= (ray.isRayFacingDown && ystep < 0) ? -1 : 1;

	verWallHitX = xintersection;
	verWallHitY = yintersection;
	 if(ray.isRayFacingLeft)
	 	verWallHitX--;
	while (verWallHitY >= 0 && verWallHitY < WINDOW_HEIGHT2D && verWallHitX >= 0 && verWallHitX < WINDOW_WIDTH2D)
	{
		if (grid_hasWallAt(verWallHitX, verWallHitY))
		{
			verDistance = distance(verWallHitX, verWallHitY);
			break;
		}
		verWallHitX += xstep;
		verWallHitY += ystep;
	}
	if (verDistance > horDistance)
	{
		//line(ray.rayAngle, horWallHitX, horWallHitY);
		ray.distance = horDistance;
	}
	else
		ray.distance = verDistance;
		//line(ray.rayAngle, verWallHitX, verWallHitY);
	
}

void	init_ray(float rayAngle)
{
	ray.rayAngle = rayAngle;
	ray.distance = 0;
	ray.wallHitX = 0;
	ray.wallHitY = 0;
	ray.isRayFacingDown = (rayAngle > 0 && rayAngle < M_PI);
	ray.isRayFacingUp = !ray.isRayFacingDown;
	ray.isRayFacingRight = ((rayAngle < 0.5 * M_PI) || (rayAngle > 1.5 * M_PI));
	ray.isRayFacingLeft = !ray.isRayFacingRight;
}

void	castAllRays()
{
	float rayAngle = player.rotationAngle - (FOV_ANGLE / 2);
	int i = 0;
	while (i < WINDOW_WIDTH3D)
	{
		init_ray(normalizeAngle(rayAngle));
		render_ray();
		rays[i] = ray;
		rayAngle += (FOV_ANGLE / (WINDOW_WIDTH3D));
		i++;
	}
}
//----------------------------------------rendering the Walls----------------------------------------
void	render_walls()
{
	int i;
	t_rays ray;
	float ray_distance;
	float distance_proj_plane;
	float wallStripHeight;
	i = 0;
	//int y;
	
	// rect( 
	// 		0,
	// 		0,
	// 		WINDOW_WIDTH3D,
	// 		WINDOW_HEIGHT3D,
	// 		0
	// 		);
	distance_proj_plane = (WINDOW_WIDTH3D / 2) / tan(FOV_ANGLE / 2);
	while (i < WINDOW_WIDTH3D)
	{
		ray = rays[i];
		ray_distance = ray.distance * cos(ray.rayAngle - player.rotationAngle);
		wallStripHeight = (TILE_SIZE / ray_distance) * distance_proj_plane;
		//printf("%f\n", wallStripHeight);
		
		if (wallStripHeight > WINDOW_HEIGHT3D)
			wallStripHeight = WINDOW_HEIGHT3D;
		rect
		(
			i,
			0,
			//WALL_STRIP_WIDTH,
			(WINDOW_HEIGHT3D - wallStripHeight) / 2,
			0
		);
		rect
		(
			i,
			(WINDOW_HEIGHT3D - wallStripHeight) / 2,
			//WALL_STRIP_WIDTH,
			wallStripHeight,
			0xffffff
		);
		// y = (WINDOW_HEIGHT3D - wallStripHeight ) / 2);
		// while (y < (WINDOW_HEIGHT3D / 2 ) + (wallStripHeight / 2))
		// {
		// 	data[y * WINDOW_WIDTH3D + i] = 0xFFFFFF;
		// 	y++;			
		// }
		rect
		(
			i,
			(WINDOW_HEIGHT3D  + wallStripHeight) / 2,
			//WALL_STRIP_WIDTH,
			(WINDOW_HEIGHT3D - wallStripHeight) / 2,
			200
		);
		i++;
	}
}


//----------------------------------------rendering and updating-------------------------------------

int	update()
{
	mlx_put_image_to_window(mlx,window,image,0,0);
	castAllRays();
	player_update();
	return (0);	
}

void	render()
{
	init_player();
	//render_grid();
	castAllRays();
	render_walls();
	render_player();
}

int main(void)
{	
	int a,b,c;

	mlx = mlx_init();
	window = mlx_new_window(mlx, WINDOW_WIDTH3D, WINDOW_HEIGHT3D, "Title");	
	mlx_hook(window, 2, 0, keyPressed, NULL);
	mlx_hook(window, 3, 0, keyReleased, NULL);
	image = mlx_new_image(mlx, WINDOW_WIDTH3D, WINDOW_HEIGHT3D);
	data = (int *)mlx_get_data_addr(image, &a,&b,&c);
	render();
	mlx_loop_hook(mlx, update, (void *)0);
	mlx_loop(mlx);
	return (0);
}
