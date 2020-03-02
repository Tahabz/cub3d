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
#include <fcntl.h>

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
float distance(float x, float y)
{
	return (sqrt((x - player.x) * (x - player.x) + (y - player.y) * (y - player.y)));
}
//Drawing a rectangle
void rect(int tileX, int tileY, unsigned int tilecol, int size)
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
			data[(int)((tempy)*WINDOW_WIDTH2D + tempx)] = tilecol;
			b--;
			tempx++;
		}
		tempy++;
		a--;
	}
}

void line3d(int tileX, int tileY, int height, unsigned int tilecol)
{
	while (height >= 0)
	{
		if (tileY >= 0 && tileY < WINDOW_HEIGHT3D && tileX >= 0 && tileX < WINDOW_WIDTH3D)
			data[(int)((tileY)*WINDOW_WIDTH3D + tileX)] = tilecol;
		tileY++;
		height--;
	}
}

void line(float angle, int x, int y)
{
	int i = (int)sqrt((x - player.x) * (x - player.x) + (y - player.y) * (y - player.y));
	int x1, y1;
	while (i)
	{
		x1 = (int)(player.x + cos(angle) * i);
		y1 = (int)(player.y + sin(angle) * i);
		if (y1 >= 0 && y1 < WINDOW_HEIGHT2D && x1 >= 0 && x1 < WINDOW_WIDTH2D)
			data[(y1)*WINDOW_WIDTH2D + x1] = 200;
		i--;
	}
}

//Drawing a line

//------------------------------------------Player functions----------------------------------------

int keyPressed(int key, void *param)
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

int keyReleased(int key, void *param)
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

void init_player()
{
	player.x = WINDOW_WIDTH2D / 2;
	player.y = WINDOW_HEIGHT2D / 2;
	player.turnDirection = 0;
	player.walkDirection = 0;
	player.rotationAngle = M_PI / 2;
	player.moveSpeed = 5.0;
	player.rotationSpeed = 1 * (M_PI / 180);
}

void player_update()
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
	//	render_grid();
}

//-------------------------------------grid functions---------------------------------------------

int grid_hasWallAt(int x, int y)
{
	x = x / TILE_SIZE;
	y = y / TILE_SIZE;
	if (x >= 0 && x < NUM_COLS && y >= 0 && y < NUM_ROWS)
		return (map[y][x] == '1');
	return 1;
}

void render_grid()
{
	int j, i = 0;
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
			tilecol = map[i][j] == '1' ? 0 : 0xffffff;
			rect(tileX, tileY, tilecol, TILE_SIZE);
			j++;
		}
		i++;
	}
}

//----------------------------------------Ray Casting Functions--------------------------------------

void render_ray()
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
	if (ray.isRayFacingUp)
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
	if (ray.isRayFacingLeft)
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
		//	line(ray.rayAngle, horWallHitX, horWallHitY);
		ray.distance = horDistance;
	}
	else
	{
		ray.distance = verDistance;
		//	line(ray.rayAngle, verWallHitX, verWallHitY);
	}
}

void init_ray(float rayAngle)
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

void castAllRays()
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
void render_walls()
{
	int i;
	t_rays ray;
	float ray_distance;
	float distance_proj_plane;
	float wallStripHeight;
	i = 0;
	distance_proj_plane = (WINDOW_WIDTH3D / 2) / tan(FOV_ANGLE / 2);
	while (i < WINDOW_WIDTH3D)
	{
		ray = rays[i];
		ray_distance = ray.distance * cos(ray.rayAngle - player.rotationAngle);
		wallStripHeight = (TILE_SIZE / ray_distance) * distance_proj_plane;
		if (wallStripHeight > WINDOW_HEIGHT3D)
			wallStripHeight = WINDOW_HEIGHT3D;
		line3d(i, 0, (WINDOW_HEIGHT3D - wallStripHeight) / 2, 0);
		line3d(i, (WINDOW_HEIGHT3D - wallStripHeight) / 2, wallStripHeight, 0xffffff);
		line3d(i, (WINDOW_HEIGHT3D + wallStripHeight) / 2, (WINDOW_HEIGHT3D - wallStripHeight) / 2, 200);
		i++;
	}
}

//----------------------------------------rendering and updating-------------------------------------

int update()
{
	mlx_put_image_to_window(mlx, window, image, 0, 0);
	player_update();
	castAllRays();
	return (0);
}

void render()
{
	init_player();
	//	render_grid();
	render_player();
	castAllRays();
	render_walls();
}



void	save_north_texture(char **texture)
{
	int i;

	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		printf("There is a problem in the north texture element (number of informations is incorrect)\n");
	no_texture = texture[1];
	printf("%s\n", no_texture);
}

void	save_west_texture(char **texture)
{
	int i;

	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		printf("There is a problem in the north texture element (number of informations is incorrect)\n");
	we_texture = texture[1];
	printf("%s\n", we_texture);
}

void	save_east_texture(char **texture)
{
	int i;

	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		printf("There is a problem in the north texture element (number of informations is incorrect)\n");
	ea_texture = texture[1];
	printf("%s\n", ea_texture);
}

void	save_south_texture(char **texture)
{
	int i;

	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		printf("There is a problem in the north texture element (number of informations is incorrect)\n");
	so_texture = texture[1];
	printf("%s\n", so_texture);
}

void	save_sprite_texture(char **texture)
{
	int i;

	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		printf("There is a problem in the north texture element (number of informations is incorrect)\n");
	sprite_texture = texture[1];
	printf("%s\n", sprite_texture);
}

void	save_resolution(char **resolution)
{
	int i;
	int j;

	i = 1;
	while (resolution[i])
	{
		if (i > 2)
			printf("There is a problem in the resolution (number of informations is invalid)\n");
		j = 0;
		while (resolution[i][j])
		{
			if (resolution[i][j] < '0' || resolution[i][j] > '9')
				printf("There is a problem in the resolution\n");
			j++;
		}
		if (i == 1)
			win_height = atoi(resolution[i]);
		else if (i == 2)
			win_width = atoi(resolution[i]);
		i++;
	}
	printf("%d %d\n", win_height, win_width);
}

void	save_floor_color(char **element)
{
	int i;
	char **floor_color_char;

	i = 0;
	while (element[i])
		i++;
	if (i != 2)
		printf("A problem with the number of informations of the floor color element\n");
	i = 0;
	while (element[1][i])
	{
		if (element[1][i] != ',' && (element[1][i] < '0' || element[1][i] > '9'))
			printf("A problem with the number of informations of the floor color element\n");
		i++;
	}
	floor_color_char = ft_split(element[1], ',');
	floor_color[0] = atoi(floor_color_char[0]);
	floor_color[1] = atoi(floor_color_char[1]);
	floor_color[2] = atoi(floor_color_char[2]);
	printf("%d %d %d\n", floor_color[0], floor_color[1], floor_color[2]);
}

void	save_ceilling_color(char **element)
{
	int i;
	char **floor_ceilling_char;

	i = 0;
	while (element[i])
		i++;
	if (i != 2)
		printf("A problem with the number of informations of the floor color element\n");
	i = 0;
	while (element[1][i])
	{
		if (element[1][i] != ',' && (element[1][i] < '0' || element[1][i] > '9'))
			printf("A problem with the number of informations of the floor color element\n");
		i++;
	}
	floor_ceilling_char = ft_split(element[1], ',');
	ceilling_color[0] = atoi(floor_ceilling_char[0]);
	ceilling_color[1] = atoi(floor_ceilling_char[1]);
	ceilling_color[2] = atoi(floor_ceilling_char[2]);
	printf("%d %d %d\n", ceilling_color[0], ceilling_color[1], ceilling_color[2]);
}

void	check_element(char **element)
{
	if (strcmp(element[0], "R") == 0)
		save_resolution(element);
	else if (strcmp(element[0], "NO") == 0)
		save_south_texture(element);
	else if (strcmp(element[0], "SO") == 0)
		save_south_texture(element);
	else if (strcmp(element[0], "EA") == 0)
		save_east_texture(element);
	else if (strcmp(element[0], "WE") == 0)
		save_west_texture(element);
	else if (strcmp(element[0], "S") == 0)
		save_west_texture(element);
	else if (strcmp(element[0], "F") == 0)
		save_floor_color(element);
	else if (strcmp(element[0], "C") == 0)
		save_floor_color(element);
}

char	**ft_reallocate(int i)
{
	char **new_map;
	int j;

	j = 0;
	new_map = (char **)malloc((i + 1) * sizeof(char *));
	while (j < i)
	{
		new_map[j] = ft_strdup(map[j]);
		j++;
	}
	free(map);
	return (new_map);
}

void 	parse_map(int fd, char *line)
{
	int i;

	i = 1;
	map = (char **)malloc(2 * sizeof(char *));
	map[0] = ft_strdup(line);
	free(line);
	while (get_next_line(fd, &line))
	{
		map[i] = ft_strdup(line);
		i += 1;
		map = ft_reallocate(i);
		free(line);
	}
	map[i] = ft_strdup(line);
	i += 1;
	map = ft_reallocate(i);
	free(line);
	map[i] = 0;
	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
	check_map_errors();
}

void	parse_file()
{
	//int i;
	int fd;
	char *line;
	char **element;

	fd = open("file.cub", O_RDONLY);
	if (fd)
	{
		while (get_next_line(fd, &line))
		{
			if (*line)
			{
				if (*line == '1' || *line == '0')
				{
					parse_map(fd, line);
					break;
				}
				else
				{
					element = ft_split(line, ' ');
					check_element(element);
				}
			}
			free(line);
		}
	}
	else
		printf("invalid file\n");
}

void	check_map_errors()
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (map[0][i] != '1')
			printf("Error in row 0\n");
		if (map[NUM_ROWS - 1][i] != '1')
			printf("Error in last row\n");
		if (map[i][NUM_COLS - 1] != '1')
			printf("Error in last column\n");
		if (map[i][0] != '1')
			printf("error in first collumn\n");
		while (map[i][j])
		{
			if (map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E' &&
			 	map[i][j] != 'W' && map[i][j] != '1' && map[i][j] != '0' &&
				map[i][j] != '0' && map[i][j] != '2')
				printf("ERROR\n");
				j++;
		}
		i++;
	}
}

int main(void)
{
	int a, b, c;
	parse_file();
//	check_map_errors();
	mlx = mlx_init();
	window = mlx_new_window(mlx, WINDOW_WIDTH3D, WINDOW_HEIGHT3D, "Cub3D");
	mlx_hook(window, 2, 0, keyPressed, NULL);
	mlx_hook(window, 3, 0, keyReleased, NULL);
	image = mlx_new_image(mlx, WINDOW_WIDTH3D, WINDOW_HEIGHT3D);
	data = (int *)mlx_get_data_addr(image, &a, &b, &c);
	render();
	mlx_loop_hook(mlx, update, (void *)0);
	mlx_loop(mlx);
	return (0);
}
