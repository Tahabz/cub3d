#include "../cub.h"
#include "../cub1.h"

int grid_has_sprite_at(int x, int y)
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
			return (map[y][x] == '2');
		}
	}
	//printf("x=%d y=%d\n", x, y);
	return 1;
}

//-------------------------------------grid functions---------------------------------------------

int grid_has_wall_at(int x, int y)
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
			return (map[y][x] == '1') ;
		}
	}
	//printf("x=%d y=%d\n", x, y);
	return 1;
}
