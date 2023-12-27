/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:23:11 by mmoumani          #+#    #+#             */
/*   Updated: 2023/08/13 17:43:26 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_close(void)
{
	printf("The game is closed\n");
	exit (0);
}

void	open_door(t_data *data)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	while (i < TILE_SIZE)
	{
		x = data->player.x + cos(data->player.angle) * i;
		y = data->player.y + sin(data->player.angle) * i;
		x = floor(x / TILE_SIZE);
		y = floor(y / TILE_SIZE);
		if (data->map[y][x] == '2')
		{
			data->map[y][x] = '3';
			break ;
		}
		i += 5;
	}
	drawing(data);
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
	if (keycode == KEY)
		open_door(data);
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

void	display(t_data *data)
{
	drawing(data);
	mlx_hook(data->win, 2, 1L << 0, key_down, data);
	mlx_hook(data->win, 3, 1L << 1, key_up, data);
	mlx_hook(data->win, 6, 1L << 6, mouse, data);
	mlx_hook(data->win, 17, 0, ft_close, NULL);
	mlx_loop_hook(data->mlx, move_player, data);
	mlx_loop(data->mlx);
}
