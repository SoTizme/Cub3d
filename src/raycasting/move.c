/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:30:22 by mmoumani          #+#    #+#             */
/*   Updated: 2023/08/07 11:43:31 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	look(t_data *data)
{
	data->angle += data->player.turn * R_SPEED;
	data->player.dx = data->player.x + cos(data->angle) * 30;
	data->player.dy = data->player.y + sin(data->angle) * 30;
	drawing(data);
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
