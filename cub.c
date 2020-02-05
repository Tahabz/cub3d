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


void *image;
int *data;
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
typedef struct s_player {
	int x;
	int y;
	int turnDirection;
	int walkDirection;
	int rotationAngle;
	int rotationSpeed;
	float moveSpeed;
}				t_player;

//------------------------------------------Player functions----------------------------------------

void render_player(t_player player)
{
	int a = 20;
	int b = 20;
	int tempx = player.x;
	int tempy = player.y;

	while (a)
	{
		b = 20;
		tempx = player.x;
		while (b)
		{
			data[(tempy-10)*WINDOW_WIDTH + tempx-10] = 200;
			b--;
			tempx++;
		}
		tempy++;
		a--;
	}
}

void	init_player(t_player *player)
{
	player->x = WINDOW_WIDTH / 2;
	player->y = WINDOW_HEIGHT / 2;
	player->turnDirection = 0;
	player->walkDirection = 0;
	player->rotationAngle = M_PI / 2;
	player->moveSpeed = 2.0;
	player->rotationSpeed = 2 * (M_PI / 180);
}

void	player_update(t_player player)
{
	
}


//-------------------------------------grid functions---------------------------------------------

void	grid_render()
{
	int j,i = 0;
	int tileX;
	int tileY;
	int tilecol;

	while (i < NUM_ROWS)
	{
		j = 0;
		while (j < NUM_COLS)
		{
			tileX = j * TILE_SIZE;
			tileY = i * TILE_SIZE;
			tilecol = map[i][j] == 1 ? 0 : 0xffffff;
			rect(tileX, tileY, tilecol);
			j++;
		}
		i++;
	}
}
void	rect(int tileX, int tileY, int tilecol)
{
	int a = TILE_SIZE;
	int b = TILE_SIZE;
	int tempx = tileX;
	int tempy = tileY;

	while (a)
	{
		b = TILE_SIZE;
		tempx = tileX;
		while (b)
		{
			//mlx_pixel_put(mlx, window, tempx, tempy, tilecol);
			data[(tempy)*WINDOW_WIDTH + tempx] = tilecol;
			b--;
			tempx++;
		}
		tempy++;
		a--;
	}
}

//----------------------------------------rendering and updating-------------------------------------


void	render()
{
	t_player player;
	init_player(&player);

	grid_render();
	render_player(player);

}

int main(void)
{	void *mlx;
	void *window;
	int a;

	mlx = mlx_init();
	window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Title");	
	image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	data = (int *)mlx_get_data_addr(image, &a,&a,&a);
	
	render();

	data[(WINDOW_HEIGHT/2)*WINDOW_WIDTH + WINDOW_WIDTH / 2] = 0xffffff;
	mlx_put_image_to_window(mlx,window,image,0,0);
	mlx_loop(mlx);
	return (0);
}