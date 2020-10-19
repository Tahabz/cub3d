#include "../cub.h"
#include "../cub1.h"

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
