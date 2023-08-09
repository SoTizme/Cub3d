/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:23:11 by mmoumani          #+#    #+#             */
/*   Updated: 2023/08/09 15:34:39 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_close(void)
{
	printf("The game is closed\n");
	exit (0);
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
	drawing(data);
	mlx_loop_hook(data->mlx, game, data);
	mlx_loop(data->mlx);
}
