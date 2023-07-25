/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:30:22 by mmoumani          #+#    #+#             */
/*   Updated: 2023/07/25 15:34:10 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_line(t_data *data, int color)
{
	data->line.x1 = data->player.x + 4;
	data->line.y1 = data->player.y + 4;
	data->line.x2 = data->player.dx;
	data->line.y2 = data->player.dy;
	data->line.color = color;
}

void	move_up(t_data *data)
{
	float	move_step;
	float	x;
	float	y;

	move_step = data->player.v_walk * M_SPEED;
	data->angel += data->player.turn * R_SPEED;
	x = data->player.x + cos(data->angel) * move_step;
	y = data->player.y + sin(data->angel) * move_step;
	if (!has_wall(data, x + 4, y + 4))
	{
		data->player.x = x;
		data->player.y = y;
	}
	data->player.dx = data->player.x + cos(data->angel) * 30 + 4;
	data->player.dy = data->player.y + sin(data->angel) * 30 + 4;
	drawing(data);
}

void	move_down(t_data *data)
{
	float	move_step;
	float	x;
	float	y;

	move_step = data->player.v_walk * M_SPEED;
	data->angel += data->player.turn * R_SPEED;
	x = data->player.x + cos(data->angel) * move_step;
	y = data->player.y + sin(data->angel) * move_step;
	if (!has_wall(data, x + 4, y + 4))
	{
		data->player.x = x;
		data->player.y = y;
	}
	data->player.dx = data->player.x + cos(data->angel) * 30 + 4;
	data->player.dy = data->player.y + sin(data->angel) * 30 + 4;
	drawing(data);
}

void	move_left(t_data *data)
{
	float	move_step;
	float	x;
	float	y;

	move_step = data->player.h_walk * M_SPEED;
	data->angel += data->player.turn * R_SPEED;
	x = data->player.x + cos(data->angel + EA) * move_step;
	y = data->player.y + sin(data->angel + EA) * move_step;
	if (!has_wall(data, x + 4, y + 4))
	{
		data->player.x = x;
		data->player.y = y;
	}
	data->player.dx = data->player.x + cos(data->angel) * 30 + 4;
	data->player.dy = data->player.y + sin(data->angel) * 30 + 4;
	drawing(data);
}

void	move_right(t_data *data)
{
	float	move_step;
	float	x;
	float	y;

	move_step = data->player.h_walk * M_SPEED;
	data->angel += data->player.turn * R_SPEED;
	x = data->player.x + cos(data->angel + EA) * move_step;
	y = data->player.y + sin(data->angel + EA) * move_step;
	if (!has_wall(data, x + 4, y + 4))
	{
		data->player.x = x;
		data->player.y = y;
	}
	data->player.dx = data->player.x + cos(data->angel) * 30 + 4;
	data->player.dy = data->player.y + sin(data->angel) * 30 + 4;
	drawing(data);
}
