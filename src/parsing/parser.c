#include "../../includes/cub3d.h"

void	check_file_format(char *file_name)
{
	char	*last_accur;
	char	*ext;

	ext = ".cub";
	last_accur = ft_strrchr(file_name, '.');
	if (!last_accur || ft_strlen(last_accur) < ft_strlen(ext))
		ft_error("Please check file format .cub");
	else if (ft_strcmp(last_accur, ext) != 0)
		ft_error("Please check file format .cub");
}

int	parser(t_elem *val, char *file_name)
{
	int		fd;
	char	*line;

	(void)val;
	check_file_format(file_name);
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_error("File doesn't exict");
	while ((line = get_next_line(fd)))
	{
		ft_lstadd_back(&val->map, ft_lstnew(line));
	}
	return (0);
}