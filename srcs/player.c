#include "../cub.h"
#include "../cub1.h"

// void render_player()
// {
// 	//rect(player.x, player.y, 200, 20);
// 	//data[(int)((player.y)*WINDOW_WIDTH2D + player.x)] = 200;
// 	//line(player.rotationAngle);
// }

void init_player()
{
	player.turnDirection = 0;
	player.walkDirection = 0;
	player.moveSpeed = 30;
	player.rotationSpeed = 1 * (M_PI / 180);
}

void player_update()
{
	player.rotationAngle += player.turnDirection * player.rotationSpeed;
	int movestep = player.walkDirection * player.moveSpeed;
	double x = player.x + cosf(player.rotationAngle) * movestep;
	double y = player.y + sinf(player.rotationAngle) * movestep;
	if (!grid_has_wall_at(x, player.y) && !grid_has_sprite_at(x, player.y))
		player.x = x;
	if (!grid_has_wall_at(player.x, y) && !grid_has_sprite_at(player.x, y))
		player.y = y;
	render_walls();
	//render_grid();
}
