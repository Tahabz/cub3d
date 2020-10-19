#include "../cub.h"
#include "../cub1.h"

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
