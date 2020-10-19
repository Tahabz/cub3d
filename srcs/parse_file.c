#include "../cub.h"
#include "../cub1.h"

void	parse_file()
{
	int fd;
	char *line;
	char **element;
	int i;

	fd = open("file.cub", O_RDONLY);
	if (fd)
	{
		while (get_next_line(fd, &line))
		{
			if (*line)
			{
				i = 0;
				while (line[i] == ' ')
					i++;
				if (line[i] == '1' || line[i] == '0')
				{
					parse_map(fd, line);
					break;
				}
				else
				{
					element = ft_split(line, ' ');
					check_element(element);
				}
			}
			free(line);
		}
	}
	else
		printf("invalid file\n");
}
