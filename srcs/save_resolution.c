#include "../cub.h"
#include "../cub1.h"

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
