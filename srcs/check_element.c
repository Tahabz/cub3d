#include "../cub.h"
#include "../cub1.h"

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
