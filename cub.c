/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobaz <marvin@41.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 10,,10,/0,1/0,4 1,5:41:0,6 by mobaz             #+#    #+#             */
/*   Updated: 2020/02/05 15:56:10 by mobaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int map[NUM_ROWS][NUM_COLS] =
	{
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
			{1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
			{1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1},
			{1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
			{1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void *image;
int *data;
void *window;
void *mlx;


typedef struct s_player {
	float x;
	float y;
	int turnDirection;
	int walkDirection;
	float rotationAngle;
	float rotationSpeed;
	int moveSpeed;
}				t_player;
t_player player;
int rendered = 0;

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
			//printf("%d\n", tilecol);
			b--;
			tempx++;
		}
		tempy++;
		a--;
	}
}

//Drawing a line
void	line(float x, float y)
{
	int i = 90;
	int x1, y1;
	while (i)
	{
		x1 = player.x + cos(player.rotationAngle)*i;
		y1 = player.y + sin(player.rotationAngle)*i;
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
	else if (key == LEFT_ARROW)
		player.turnDirection = 0;
	else if (key == RIGHT_ARROW)
		player.turnDirection = 0;
	return 0;
}

void render_player()
{
	rect(player.x, player.y, 200, 20);
	 line(
		player.x,
		player.y
		);
}

void	init_player()
{
	player.x = WINDOW_WIDTH / 2;
	player.y = WINDOW_HEIGHT / 2;
	player.turnDirection = 0;
	player.walkDirection = 0;
	player.rotationAngle = M_PI / 2;
	player.moveSpeed = 2.0;
	player.rotationSpeed = 2 * (M_PI / 180);
}

void	player_update()
{
	player.rotationAngle += player.turnDirection * player.rotationSpeed;
	int movestep = player.walkDirection * player.moveSpeed;
	player.x += cos(player.rotationAngle) * movestep;
	player.y += sin(player.rotationAngle) * movestep;  
	
	/*if (player.walkDirection == 1 || player.walkDirection == -1)
	{
		player.x = player.x + 1;
		render_player();
	}*/	
	grid_render();
	render_player();
	// ft_putnbr(player.x);
	// ft_putchar('\n');
	
}


//-------------------------------------grid functions---------------------------------------------


void	grid_render()
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


//----------------------------------------rendering and updating-------------------------------------

int	update()
{
	mlx_hook(window, 2, 0, keyPressed, (void *)0);
	mlx_hook(window, 3, 0, keyReleased, (void *)0);
	mlx_put_image_to_window(mlx,window,image,0,0);
	player_update();
	return (0);	
}

void	render()
{
	//if (!rendered)
	//{
		init_player();
		grid_render();
		render_player();
		rendered = 1;
		printf("IM HERE!\n");
//	}
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