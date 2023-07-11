#include "../../includes/cub3d.h"

int	is_valid_ext(char *file_name, char *ext)
{
	char	*last_accur;

	last_accur = ft_strrchr(file_name, '.');
	if (!last_accur || ft_strlen(last_accur) < ft_strlen(ext))
		return (0);
	return (ft_strcmp(last_accur, ext) == 0);
}

void	check_file_format(char *file_name)
{
	if (!is_valid_ext(file_name, ".cub"))
		ft_error("Please check file format .cub");
}

int	parser(t_elem *val, char *file_name)
{
	int		fd;
	char	*line;

	(void)val;
	check_file_format(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_error("File doesn't exict");
	while ((line = get_next_line(fd)))
	{
		ft_lstadd_back(&val->map, ft_lstnew(line));
	}
	return (0);
}