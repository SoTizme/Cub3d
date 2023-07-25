/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:03:56 by shilal            #+#    #+#             */
/*   Updated: 2023/07/25 18:10:15 by mmoumani         ###   ########.fr       */
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
# include <math.h>
# include <errno.h>

# define BLUE 0x0000FF
# define RED 0xFF0000
# define YELLOW 0xF0FF00

# define TILE_SIZE 32
# define UP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define R_LOOK 124
# define L_LOOK 123
# define ESC 53
# define PI 3.14159265359
# define M_SPEED 3
# define R_SPEED 0.066
# define NO 0
# define EA 1.57
# define SO 3.14
# define WE 4.72
# define STRIP_WIDTH 1

// structs :

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

typedef struct s_line
{
	int	x1;
	int	y1;
	int	x2;
	int	y2;
	int	color;
}	t_line;

typedef struct s_distence
{
	int	dis;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	color;
}	t_distence;

typedef struct s_player
{
	float		x;
	float		y;
	int			dx;
	int			dy;
	int			v_walk;
	int			h_walk;
	int			turn;
	int			fov;
}	t_player;

typedef struct s_ray
{
	float		x;
	float		y;
	float		angel;
	float		dist;
	int			is_ver;
	int			up;
	int			down;
	int			left;
	int			right;
	int			content;
}	t_ray;

// parser 

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
	void		*mlx;
	void		*win;
	int			px;
	int			py;
	int			width;
	int			height;
	int			n_rays;
	float		angel;
	t_player	player;
	t_line		line;
	t_ray		*rays;
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

// render function :

// void	init_line(t_data *data, int dx, int dy, int color);
void	init_line(t_data *data, int color);
void	render_rect(t_data *data, t_rect rect);
void	render_line(t_data *data, t_line line);
void	draw_map2d(t_data *data);
void	draw_player(t_data *data);
void	drawing(t_data *data);

// move function :

void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

// check part : 

int		has_wall(t_data *data, float x, float y);

// Displaying

void	display(t_data *data);

#endif