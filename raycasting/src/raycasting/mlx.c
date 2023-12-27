/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 17:23:11 by mmoumani          #+#    #+#             */
/*   Updated: 2023/08/17 13:22:01 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_img data, int x, int y, unsigned int color)
{
	char	*mlx_data_addr;
	int		pos;

	pos = y * data.size_line + x * (data.bits_per_pixel / 8);
	mlx_data_addr = data.addr + pos;
	*(unsigned int *)mlx_data_addr = color;
}

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

void	display(t_data *data)
{
	data->player.dx = data->player.x + cos(data->angle) * 30;
	data->player.dy = data->player.y + sin(data->angle) * 30;
	drawing(data);
	mlx_hook(data->win, 2, 1L << 0, key_down, data);
	mlx_hook(data->win, 3, 1L << 1, key_up, data);
	mlx_hook(data->win, 17, 0, ft_close, NULL);
	mlx_loop_hook(data->mlx, move_player, data);
	mlx_loop(data->mlx);

}
