/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 12:03:56 by shilal            #+#    #+#             */
/*   Updated: 2023/08/17 22:07:24 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../src/get_line/get_next_line.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <errno.h>
# include <limits.h>

// keys press

# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100
# define R_LOOK 65363
# define L_LOOK 65361
# define KEY 32
# define ESC 65307

# define PI 3.14159265359
# define M_SPEED 4
# define R_SPEED 0.016
# define FOV 1.0471975511965976

# define NO 4.72
# define EA 0
# define SO 1.57
# define WE 3.14

# define TILE_SIZE 64

# define WMAP 1920
# define HMAP 1080

// Colors

# define GREEN 0x6D9886
# define TEAL 0x116D6E
# define W_RED 0xCD1818
# define WHITE 0xF7F7F7
# define GREY 0x4D4D4D

// -----Drawing Minimap-----

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}	t_rect;

// -----Drawing Wall Struct-----

typedef struct s_draw
{
	int		x;
	float	h_wall;
	float	t_wall;
	float	b_wall;
}		t_draw;

// render struct

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}			t_img;

// player struct

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	int		v_walk;
	int		h_walk;
	int		turn;
}			t_player;

// ray struct

typedef struct s_ray
{
	float	x;
	float	y;
	float	angle;
	float	dist;
	int		is_vert;
	int		up;
	int		down;
	int		left;
	int		right;
	int		content;
}			t_ray;

// ------Raycasting Struct------ 

// inter facing

typedef struct s_intrf
{
	int	up;
	int	down;
	int	left;
	int	right;
}		t_intrf;

// inter section

typedef struct s_intrs
{
	float	x;
	float	y;
	float	next_x;
	float	next_y;
	float	x_step;
	float	y_step;
}			t_intrs;

typedef struct s_horz
{
	int		wall;
	float	x_wall;
	float	y_wall;
	char	content;
	float	dist;
}			t_horz;

typedef struct s_vert
{
	int		wall;
	float	x_wall;
	float	y_wall;
	char	content;
	float	dist;
}			t_vert;

// ------Parsering Struct------ 

typedef struct s_txtur
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*dr;
	int		*f;
	int		*c;
}			t_txtur;

typedef struct s_check
{
	int	t_c;
	int	t_f;
	int	t_no;
	int	t_dr;
	int	t_so;
	int	t_we;
	int	t_ea;
}		t_check;

typedef struct s_data
{
	t_txtur		*txtur;
	t_list		*s_map;
	t_check		*check;
	t_player	player;
	t_ray		*rays;
	void		*mlx;
	void		*win;
	char		**map;
	int			px;
	int			py;
	int			width;
	int			height;
	int			floor;
	int			ceil;
	t_img		img;
	t_img		*no;
	t_img		*so;
	t_img		*we;
	t_img		*ea;
	t_img		*door;
	t_img		*tex;
	int			old_x;
}				t_data;

// ------------main function------------

void	init_data(t_data *data);
void	get_angel(t_data *data, int i, int j);
t_img	*new_img(t_data *data, char *path);

// move function :

int		move_player(t_data *data);
void	move_hor(t_data *data);
void	move_ver(t_data *data);
void	look(t_data *data);

// check part :

int		has_wall(t_data *data, float x, float y);

// Displaying :

void	drawing(t_data *data);
void	display(t_data *data);
void	cast_rays(t_data *data);

// raycasting function :

float	update_angle(float angle);
t_intrf	init_intrf(float angle);
float	dist_2point(float x1, float y1, float x2, float y2);
int		has_wall_at(t_data *data, float x, float y);
void	initialition(t_data *data, t_horz *horz, t_vert *vert, int i);

void	h_init_intrs(t_data *data, t_intrs *intrs, t_intrf r_face, float angle);
void	horizontal(t_data *data, t_intrs *intrs, t_horz *horz, int up);
t_horz	init_hor(void);

void	v_init_intrs(t_data *data, t_intrs *intrs, t_intrf r_face, float angle);
void	vertical(t_data *data, t_intrs *intrs, t_vert *vert, int left);
t_vert	init_ver(void);

// ------------Parsing function------------

int		check_file_format(char *file_name, char *ext);
void	parser(t_data *data, char *file_name);
void	texture_error(char *chr, char **s);
void	check_texture(t_data *data);
void	check_map(t_data *data);
void	get_map(t_data *data);

// Utils parsing :
void	ft_add_textur(t_data *data, char *s, char *chr);
void	cont_texture(t_data *data, char c);
int		get_the_tall_line(t_data *data);
char	*my_strdup(char *s, int len);
int		cher_if_line_valid(char *s);
void	ft_error(char *error_msg);
long	my_atoi(const char *str);
t_list	*skp_utils(t_list *lst);
char	**get_texture(char *s);
void	double_free(char **s);
char	*is_dgit(char *s);

// ------------Wall function------------

void	draw_wall(t_data *data, int i);
int		mouse(int x, int y, t_data *data);
char	get_content(t_data *data, float x, float y);
void	draw_mini_map(t_data *data);
void	my_mlx_pixel_put(t_img data, int x, int y, unsigned int color);

#endif