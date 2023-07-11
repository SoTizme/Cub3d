#ifndef CUB3D_H
# define CUB3D_H

# include "../src/get_line/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>

// structs :

// typedef struct s_list
// {
// 	char			*content;
// 	struct s_list	*next;
// }					t_list;

typedef struct s_elem
{
	t_list		*map;
}				t_elem;


int		parser(t_elem *val, char *file_name);
void	ft_error(char *error_msg);

#endif