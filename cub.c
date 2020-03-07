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
		if (tileY >= 0 && tileY < win_height && tileX >= 0 && tileX < win_width)
			data[(int)((tileY)*win_width + tileX)] = tilecol;
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
	//render_grid();
}

//-------------------------------------grid functions---------------------------------------------

int grid_hasWallAt(int x, int y)
{
	int i;

	i = 0;
	x = x / TILE_SIZE;
	y = y / TILE_SIZE;
	if (y >= 0 && y < NUM_ROWS)
	{
		while (map[y][i])
			i++;
		if (x >= 0 && x < i)
		{
			//printf("%d\n", map[y][x] == '1');
			return (map[y][x] == '1');
		}
	}
	//printf("x=%d y=%d\n", x, y);
	return 1;
}

void render_grid()
{
	int j, i = 0;
	int tileX;
	int tileY;
	unsigned int tilecol;

	while (map[i])
	{
		j = 0;
		while (map[i][j])
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
	float hor_wall_hit_x, hor_wall_hit_y, horDistance = 1000000000;

	//---------------CLOSEST HORIZONTAL GRID INTERSECTION------------------------
	yintersection = floorf(player.y / TILE_SIZE) * TILE_SIZE;
	yintersection += (ray.isRayFacingDown ? TILE_SIZE : 0);
	xintersection = player.x + (yintersection - player.y) / tan(ray.rayAngle);
	ystep = TILE_SIZE;
	ystep *= (ray.isRayFacingUp ? - 1 : 1);
	xstep = TILE_SIZE / tan(ray.rayAngle);
	xstep *= (ray.isRayFacingLeft && xstep > 0) ? -1 : 1;
	xstep *= (ray.isRayFacingRight && xstep < 0) ? -1 : 1;

	hor_wall_hit_x = xintersection;
	hor_wall_hit_y = yintersection;
	while (hor_wall_hit_y >= 0 && hor_wall_hit_y < WINDOW_HEIGHT2D && hor_wall_hit_x >= 0 && hor_wall_hit_x < WINDOW_WIDTH2D)
	{
		if (grid_hasWallAt(hor_wall_hit_x, ray.isRayFacingUp ? hor_wall_hit_y - 1: hor_wall_hit_y))
		{
			horDistance = distance(hor_wall_hit_x, hor_wall_hit_y);
			break;
		}
		hor_wall_hit_x += xstep;
		hor_wall_hit_y += ystep;
	}
	//---------------CLOSEST ------------------------

	float ver_wall_hit_x, verwall_hit_y, verDistance = 1000000000;

	xintersection = floorf(player.x / TILE_SIZE) * TILE_SIZE;
	xintersection += (ray.isRayFacingRight ? TILE_SIZE : 0);
	yintersection = player.y + (xintersection - player.x) * tan(ray.rayAngle);
	xstep = TILE_SIZE;
	xstep *= (ray.isRayFacingLeft ? -1 : 1);
	ystep = TILE_SIZE * tan(ray.rayAngle);
	ystep *= (ray.isRayFacingUp && ystep > 0) ? -1 : 1;
	ystep *= (ray.isRayFacingDown && ystep < 0) ? -1 : 1;

	ver_wall_hit_x = xintersection;
	verwall_hit_y = yintersection;
	while (verwall_hit_y >= 0 && verwall_hit_y < WINDOW_HEIGHT2D && ver_wall_hit_x >= 0 && ver_wall_hit_x < WINDOW_WIDTH2D)
	{
		if (grid_hasWallAt(ray.isRayFacingLeft ? ver_wall_hit_x -1 : ver_wall_hit_x , verwall_hit_y))
		{
			verDistance = distance(ver_wall_hit_x, verwall_hit_y);
			break;
		}
		ver_wall_hit_x += xstep;
		verwall_hit_y += ystep;
	}
	if (verDistance > horDistance)
	{
	//	line(ray.rayAngle, hor_wall_hit_x, hor_wall_hit_y);
		ray.wall_hit_x = 1;
		ray.distance = horDistance;
	}
	else
	{
		ray.wall_hit_y = 1;
		ray.distance = verDistance;
	//	line(ray.rayAngle, ver_wall_hit_x, verwall_hit_y);
	}
}

void init_ray(float rayAngle)
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
	float rayAngle = player.rotationAngle - (FOV_ANGLE / 2);
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
//----------------------------------------rendering the Walls----------------------------------------
void render_walls()
{
	int i;
	float ray_distance;
	float distance_proj_plane;
	float wall_strip_height;
	i = 0;
	distance_proj_plane = (win_width / 2) / tan(FOV_ANGLE / 2);
	while (i < win_width)
	{
		ray = rays[i];
		ray_distance = ray.distance * cos(ray.rayAngle - player.rotationAngle);
		wall_strip_height = (TILE_SIZE / ray_distance) * distance_proj_plane;
		if (wall_strip_height > win_height)
			wall_strip_height = win_height;
		line3d(i, 0, (win_height - wall_strip_height) / 2, 0);
		line3d(i, (win_height - wall_strip_height) / 2, wall_strip_height, ray.wall_hit_x ? 0xffffff : 0xD3D3D3);
		line3d(i, (win_height + wall_strip_height) / 2, (win_height - wall_strip_height) / 2, 200);
		i++;
	}
}

//----------------------------------------rendering and updating-------------------------------------


void	save_north_texture(char **texture)
{
	int i;

	i = 1;
	while (texture[i])
		i++;
	if (i != 2)
		printf("There is a problem in the north texture element (number of informations is incorrect)\n");
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
		printf("There is a problem in the north texture element (number of informations is incorrect)\n");
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
		printf("There is a problem in the north texture element (number of informations is incorrect)\n");
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
		printf("There is a problem in the north texture element (number of informations is incorrect)\n");
	so_image.texture = texture[1];
	printf("%s\n", so_image.texture);
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
			win_width = atoi(resolution[i]);
		else if (i == 2)
			win_height = atoi(resolution[i]);
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
		save_north_texture(element);
	else if (strcmp(element[0], "SO") == 0)
		save_south_texture(element);
	else if (strcmp(element[0], "EA") == 0)
		save_east_texture(element);
	else if (strcmp(element[0], "WE") == 0)
		save_west_texture(element);
	else if (strcmp(element[0], "S") == 0)
		save_sprite_texture(element);
	else if (strcmp(element[0], "F") == 0)
		save_floor_color(element);
	else if (strcmp(element[0], "C") == 0)
		save_ceilling_color(element);
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
	int j;

	j = 1;
	i = 1;
	map = (char **)malloc(2 * sizeof(char *));
	map[0] = ft_strdup(line);
	free(line);
	while (j)
	{
		j = get_next_line(fd, &line);
		map[i] = ft_strdup(line);
		i += 1;
		map = ft_reallocate(i);
		free(line);
	}
	map[i] = 0;
	i = 0;
	while (map[i])
		printf("%s\n", map[i++]);
	check_map_errors();
}

void	parse_file()
{
	int fd;
	char *line;
	char **element;
	int i;

	fd = open("file.cub", O_RDONLY);
	if (fd)
	{
		while (get_next_line(fd, &line))
		{
			if (*line)
			{
				i = 0;
				while (line[i] == ' ')
					i++;
				if (line[i] == '1' || line[i] == '0')
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
	int t;

	t = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		if (map[0][i] != '1')
		{
		 	if (map[0][i] == ' ')
			{
			 	if (map[1][i] == '0')
				 	printf("Error in row 0\n");
			}
			else
				printf("Error in row 0\n");
		}		
		if (map[NUM_ROWS - 1][i] != '1')
		{
			if (map[NUM_ROWS - 1][i] == ' ')
			{
				if (map[NUM_ROWS - 2][i] == '0')
					printf("Error in last row i=%d j=%d\n", i, j);
			}
			else
				printf("Error in last row i=%d j=%d\n", i, j);
		}
		if (map[i][0] != '1' && map[i][0] != ' ')
			printf("error in first collumn\n");
		while (map[i][j])
		{
			if (map[i][j + 1] == '\0')
			{
				t = j;
				if (map[i][j] != '1')
					printf("Error in last column\n");
			}
			if (map[i][j] == ' ')
			{
				printf("i = %d, j = %d\n", i, j);
				if (j <= t && map[i][j + 1])		
					if (j > 0 && i > 0 && i < NUM_ROWS - 1)
						if (map[i][j + 1] == '0' || map[i][j - 1] == '0' || map[i + 1][j] == '0' || map[i - 1][j] == '0')
							printf("ERROR MAP SPACE i = %d j = %d\n", i, j);
			}
			if (map[i][j] == '0')
			{
				if (j > t && t != 0)
					printf("ERROR LOL i = %d j = %d\n", i, j);
				else if (map[i - 1][j] == ' ')
					printf("ERROR LOL i = %d j = %d\n", i, j);
			}
			if (map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'E' &&
			 	map[i][j] != 'W' && map[i][j] != '1' && map[i][j] != '0' &&
				map[i][j] != '0' && map[i][j] != '2' && map[i][j] != ' ')
				printf("ERROR\n");
				j++;
		}
		i++;
	}
}

void	get_image()
{
	no_image.image = (int *)mlx_xpm_file_to_image(mlx, no_image.texture, &(no_image.width), &(no_image.height));
	printf("%d\n", no_image.height);
	// no_image.data = mlx_get_data_addr(mlx, &no_image.bpp, &no_image.sl, &no_image.end);
	// ea_image.image = mlx_xpm_file_to_image(mlx, ea_image.texture, &(ea_image.width), &(ea_image.height));
	// ea_image.data = mlx_get_data_addr(mlx, &ea_image.bpp, &ea_image.sl, &ea_image.end);
	// so_image.image = mlx_xpm_file_to_image(mlx, so_image.texture, &(so_image.width), &(so_image.height));
	// so_image.data = mlx_get_data_addr(mlx, &so_image.bpp, &so_image.sl, &so_image.end);
	// we_image.image = mlx_xpm_file_to_image(mlx, we_image.texture, &(we_image.width), &(we_image.height));
	// we_image.data = mlx_get_data_addr(mlx, &we_image.bpp, &we_image.sl, &we_image.end);  
}

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
	//render_grid();
	render_player();
	castAllRays();
	render_walls();
}

int main(void)
{
	int a, b, c;
	parse_file();
//	check_map_errors();
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
