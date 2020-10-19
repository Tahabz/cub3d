#include "../cub.h"
#include "../cub1.h"

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
