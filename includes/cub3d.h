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

typedef struct s_txtur
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			**f;
	int			**c;
}				t_txtur;

typedef struct s_elem
{
	t_txtur		*txtur;
	char		*map;
}				t_elem;

// Parsing :

int		parser(t_elem *val, char *file_name);
int		check_file_format(char *file_name, char *ext);
int		check_texture(t_elem *val, t_list **map);
void	ft_error(char *error_msg);
void	texture_error(char *chr, char **s);
void	double_free(char **s);

#endif