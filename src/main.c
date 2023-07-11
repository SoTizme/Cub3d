#include "../includes/cub3d.h"

void	ft_error(char *error_msg)
{
	printf("Error : %s\n", error_msg);
	exit (0);
}

int	main(int ac, char **av)
{
	t_elem val;

	if (ac != 2)
		ft_error("You have more/less 2 argument");
	
	parser(&val, av[1]);
	//printf("hello world!\n");
}