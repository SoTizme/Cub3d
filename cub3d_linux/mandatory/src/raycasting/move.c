/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:30:22 by mmoumani          #+#    #+#             */
/*   Updated: 2023/08/18 23:22:22 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	look(t_data *data)
{
	data->player.angle += data->player.turn * R_SPEED;
}

void	move_ver(t_data *data)
{
	float	move_step;
	float	x;
	float	y;

	move_step = data->player.v_walk * M_SPEED;
	x = data->player.x + cos(data->player.angle) * move_step;
	y = data->player.y + sin(data->player.angle) * move_step;
	if (!has_wall(data, x, y))
	{
		data->player.x = x;
		data->player.y = y;
	}
}

void	move_hor(t_data *data)
{
	float	move_step;
	float	x;
	float	y;

	move_step = data->player.h_walk * M_SPEED;
	x = data->player.x + cos(data->player.angle + 1.57) * move_step;
	y = data->player.y + sin(data->player.angle + 1.57) * move_step;
	if (!has_wall(data, x, y))
	{
		data->player.x = x;
		data->player.y = y;
	}
}

int	move_player(t_data *data)
{
	if (data->player.v_walk || data->player.h_walk || data->player.turn)
	{
		if (data->player.v_walk != 0)
			move_ver(data);
		if (data->player.h_walk != 0)
			move_hor(data);
		if (data->player.turn != 0)
			look(data);
		drawing(data);
	}
	return (0);
}
