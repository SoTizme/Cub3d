#ifndef CUB3D_H
# define CUB3D_H

# include "../src/get_line/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <errno.h>

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

typedef struct s_check
{
	int			t_c;
	int			t_f;
	int			t_no;
	int			t_so;
	int			t_we;
	int			t_ea;
	int			y;
	int			x;
}				t_check;


typedef struct s_data
{
	t_txtur		*txtur;
	char		**map;
	t_check		*check;
}				t_data;

// Parsing :

int		check_file_format(char *file_name, char *ext);
void	get_map(t_data *data, int len, t_list *tmp);
void	check_texture(t_data *dataa, t_list **map);
int		parser(t_data *dataa, char *file_name);
void	check_map(t_data *data, t_list **map);
void	texture_error(char *chr, char **s);

// Utils parsing :
void	cont_texture(t_data *data, char c);
int		get_the_tall_line(t_list **map);
char	*my_strdup(char *s, int len);
void	ft_error(char *error_msg);
int		my_lstsize(t_list *lst);
void	double_free(char **s);
char	*is_dgit(char *s);

#endif