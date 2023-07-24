/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:03:56 by shilal            #+#    #+#             */
/*   Updated: 2023/07/24 12:06:33 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
}				t_check;

typedef struct s_data
{
	t_txtur		*txtur;
	t_list		*s_map;
	char		**map;
	t_check		*check;
	int			y;
	int			x;
	int			y_player;
	int			x_player;
}				t_data;

// Parsing :

int		check_file_format(char *file_name, char *ext);
int		parser(t_data *dataa, char *file_name);
void	texture_error(char *chr, char **s);
void	check_texture(t_data *data);
void	check_map(t_data *data);
void	get_map(t_data *data);

// Utils parsing :
void	cont_texture(t_data *data, char c);
int		get_the_tall_line(t_data *data);
char	*my_strdup(char *s, int len);
void	ft_error(char *error_msg);
t_list	*skp_utils(t_list *lst);
char	**get_texture(char *s);
void	double_free(char **s);
char	*is_dgit(char *s);

#endif