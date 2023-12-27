/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:36:46 by mmoumani          #+#    #+#             */
/*   Updated: 2023/08/17 13:02:00 by mmoumani         ###   ########.fr       */
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

int	move_player(t_data *data)
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
