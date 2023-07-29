/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:23:11 by mmoumani          #+#    #+#             */
/*   Updated: 2023/07/29 15:34:31 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_close(void)
{
	printf("The game is closed\n");
	exit (0);
}

void	look(t_data *data)
{
	data->angle += data->player.turn * R_SPEED;
	data->player.dx = data->player.x + cos(data->angle) * 30;
	data->player.dy = data->player.y + sin(data->angle) * 30;
	drawing(data);
}

int	has_wall(t_data *data, float x, float y)
{
	int	fx;
	int	fy;
	int	fx2;
	int	fy2;

	if (x < 0 || x > data->width || y < 0 || y > data->height)
		return (1);
	fx = floor((data->player.x) / TILE_SIZE);
	fy = floor((data->player.y) / TILE_SIZE);
	fx2 = floor(x / TILE_SIZE);
	fy2 = floor(y / TILE_SIZE);
	if (data->map[fy][fx] == '1' || data->map[fy2][fx2] == '1'
		|| data->map[fy2][fx] == '1' || data->map[fy][fx2] == '1')
		return (1);
	if (data->map[fy][fx] == ' ' || data->map[fy2][fx2] == ' '
		|| data->map[fy2][fx] == ' ' || data->map[fy][fx2] == ' ')
		return (1);
	return (0);
}

void	move_ver(t_data *data)
{
	float	move_step;
	float	x;
	float	y;

	move_step = data->player.v_walk * M_SPEED;
	data->angle += data->player.turn * R_SPEED;
	x = data->player.x + cos(data->angle) * move_step;
	y = data->player.y + sin(data->angle) * move_step;
	if (!has_wall(data, x, y))
	{
		data->player.x = x;
		data->player.y = y;
	}
	data->player.dx = data->player.x + cos(data->angle) * 30;
	data->player.dy = data->player.y + sin(data->angle) * 30;
	drawing(data);
}

void	move_hor(t_data *data)
{
	float	move_step;
	float	x;
	float	y;

	move_step = data->player.h_walk * M_SPEED;
	data->angle += data->player.turn * R_SPEED;
	x = data->player.x + cos(data->angle + EA) * move_step;
	y = data->player.y + sin(data->angle + EA) * move_step;
	if (!has_wall(data, x, y))
	{
		data->player.x = x;
		data->player.y = y;
	}
	data->player.dx = data->player.x + cos(data->angle) * 30;
	data->player.dy = data->player.y + sin(data->angle) * 30;
	drawing(data);
}

void	move_player(t_data *data)
{
	// if (data->player.v_walk == 1)
	// 	move_up(data);
	// else if (data->player.v_walk == -1)
	// 	move_down(data);
	// else if (data->player.h_walk == 1)
	// 	move_right(data);
	// else if (data->player.h_walk == -1)
	// 	move_left(data);
	if (data->player.v_walk != 0)
		move_ver(data);
	else if (data->player.h_walk != 0)
		move_hor(data);
	else
	{
		if (data->player.turn != 0)
			look(data);
	}
}

int	key_down(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_close();
	if (keycode == UP)
		data->player.v_walk = 1;
	if (keycode == DOWN)
		data->player.v_walk = -1;
	if (keycode == RIGHT)
		data->player.h_walk = 1;
	if (keycode == LEFT)
		data->player.h_walk = -1;
	if (keycode == R_LOOK)
		data->player.turn = 1;
	if (keycode == L_LOOK)
		data->player.turn = -1;
	return (0);
}

int	key_up(int keycode, t_data *data)
{
	if (keycode == UP)
		data->player.v_walk = 0;
	if (keycode == DOWN)
		data->player.v_walk = 0;
	if (keycode == RIGHT)
		data->player.h_walk = 0;
	if (keycode == LEFT)
		data->player.h_walk = 0;
	if (keycode == R_LOOK)
		data->player.turn = 0;
	if (keycode == L_LOOK)
		data->player.turn = 0;
	return (0);
}

void	draw_map2d(t_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = -1;
	y = 0;
	while (data->map[++i])
	{
		j = -1;
		x = 0;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == '1')
				render_rect(data, (t_rect){x, y, TILE_SIZE, TILE_SIZE, YELLOW});
			else
				render_rect(data, (t_rect){x, y, TILE_SIZE, TILE_SIZE, BLUE});
			x += TILE_SIZE;
		}
		y += TILE_SIZE;
	}
}

void	draw_player(t_data *d)
{
	int	x;
	int	y;

	x = d->player.x - 4;
	y = d->player.y - 4;
	render_rect(d, (t_rect){x, y, 8, 8, RED});
}

int	game(t_data *data)
{
	mlx_hook(data->win, 2, 0, key_down, data);
	mlx_hook(data->win, 3, 0, key_up, data);
	mlx_hook(data->win, 17, 0, ft_close, NULL);
	move_player(data);
	return (0);
}

void	display(t_data *data)
{
	data->player.dx = data->player.x + cos(data->angle) * 30;
	data->player.dy = data->player.y + sin(data->angle) * 30;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "cub3d");
	drawing(data);
	mlx_loop_hook(data->mlx, game, data);
	mlx_loop(data->mlx);
}
