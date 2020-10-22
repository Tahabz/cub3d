#include "../cub.h"
#include "../cub1.h"

void	check_map_errors()
{
	int i;
	int j;
	int t;
	int r;

	r = 0;
	t = 0;
	i = 0;
	while (map[r])
	{
		j = 0;
		while (map[r][j])
		{
			if (map[r][j] == 'N' || map[r][j] == 'W' || map[r][j] == 'E' || map[r][j] == 'S')
			{
				g_player.x = j * 200 + 100; /*WINDOW_WIDTH2D / 2.5 - 200;*/
				g_player.y = r * 200 + 100;/*WINDOW_HEIGHT2D / 2.5 + 90;*/
				if (map[r][j] == 'N')
					g_player.rotationAngle = (3  * M_PI) / 2;
				else if (map[r][j] == 'S')
					g_player.rotationAngle = M_PI / 2;
				else if (map[r][j] == 'E')
					g_player.rotationAngle = 0;
				else if (map[r][j] == 'W')
					g_player.rotationAngle = M_PI;
			}
			j++;
		}
		r++;
	}
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
		if (map[r - 1][i] != '1')
		{
			if (map[r - 1][i] == ' ')
			{
				if (map[r - 2][i] == '0')
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
				if (j <= t && map[i][j + 1])		
					if (j > 0 && i > 0 && i < r - 1)
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
