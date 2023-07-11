#include "../../includes/cub3d.h"

int	parser(t_elem *val)
{
	int		fd;
	char	*line;

	(void)val;
	fd = open("../../utils/map.cub", O_RDONLY);
	printf("hello world! %d\n", fd);
	// while ((line = get_next_line(fd)))
	// {
	// 	printf("%s\n", line);
	// }
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%s\n", line);
	}
	return (0);
}