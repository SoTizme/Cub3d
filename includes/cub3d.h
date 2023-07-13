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
	int			*f;
	int			*c;
}				t_txtur;

typedef struct s_elem
{
	t_txtur		*txtur;
	char		*map;
	int			t_c;
	int			t_f;
	int			t_no;
	int			t_so;
	int			t_we;
	int			t_ea;
}				t_elem;

// Parsing :

int		check_file_format(char *file_name, char *ext);
void	check_texture(t_elem *val, t_list **map);
int		parser(t_elem *val, char *file_name);
void	texture_error(char *chr, char **s);
void	ft_error(char *error_msg);
void	double_free(char **s);
char	*is_dgit(char *s);

#endif