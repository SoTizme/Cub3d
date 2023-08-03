/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:03:56 by shilal            #+#    #+#             */
/*   Updated: 2023/08/03 19:56:38 by mmoumani         ###   ########.fr       */
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
# include <limits.h>

// COLORS

# define BLUE 0x7eabf2
# define RED 0xFF0000
# define YELLOW 0xF0FF00
# define GREEN 0x4e947e

// keys press

# define UP 13
# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define R_LOOK 124
# define L_LOOK 123
# define ESC 53

# define PI 3.14159265359
# define M_SPEED 3
# define R_SPEED 0.016
# define FOV 1.0471975511965976

# define NO 0
# define EA 1.57
# define SO 3.14
# define WE 4.72

# define TILE_SIZE 64
# define STRIP_WIDTH 1

# define WMAP 1920
# define HMAP 1080

// structs :

typedef struct    s_img {
	void    *img;
	char    *addr;
	int     bits_per_pixel;
	int        size_line;
	int        endian;
	int        width;
	int        height;
}    t_img;

// render struct

typedef struct s_draw
{
	int	x;
	int	f_height;
	int	w_height;
}	t_draw;

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

// distence struct

typedef struct s_distence
{
	int	dis;
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	color;
}	t_distence;

// player struct

typedef struct s_player
{
	float		x;
	float		y;
	int			dx;
	int			dy;
	int			v_walk;
	int			h_walk;
	int			turn;
}	t_player;

// ray struct

typedef struct s_ray
{
	float		x;
	float		y;
	float		angle;
	float		dist;
	int			is_vert;
	int			up;
	int			down;
	int			left;
	int			right;
	int			content;
}	t_ray;

// ray casting struct

// inter facing

typedef struct s_intrf
{
	int	up;
	int	down;
	int	left;
	int	right;
}	t_intrf;

// inter section

typedef struct s_intrs
{
	float	x;
	float	y;
	float	next_x;
	float	next_y;
	float	x_step;
	float	y_step;
}	t_intrs;

typedef struct s_horz
{
	int		wall;
	float	x_wall;
	float	y_wall;
	float	dist;
}	t_horz;

typedef struct s_vert
{
	int		wall;
	float	x_wall;
	float	y_wall;
	float	dist;
}	t_vert;

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
	t_img       img;
	int			px;
	int			py;
	int			width;
	int			height;
	int			n_rays;
	float		angle;
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

void	move_player(t_data *data);
void	move_hor(t_data *data);
void	move_ver(t_data *data);
void	look(t_data *data);

// check part :

int		has_wall(t_data *data, float x, float y);

// Displaying

void	display(t_data *data);
void	cast_rays(t_data *data);

// raycasting function :

float	update_angle(float angle);
t_intrf	init_intrf(float angle);
float	dist_2point(float x1, float y1, float x2, float y2);
int		has_wall_at(t_data *data, float x, float y);
void	initialition(t_data *data, t_horz *horz, t_vert *vert, int i);

void	h_init_intrs(t_data *data, t_intrs *intrs, t_intrf r_face, float angle);
void	horizontal(t_data *data, t_intrs *intrs, t_horz *horz);
t_horz	init_hor(void);

void	v_init_intrs(t_data *data, t_intrs *intrs, t_intrf r_face, float angle);
void	verical(t_data *data, t_intrs *intrs, t_vert *vert);
t_vert	init_ver(void);

void	draw_wall(t_data *data, int i);

#endif