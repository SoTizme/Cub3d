/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:18:36 by mmoumani          #+#    #+#             */
/*   Updated: 2023/08/02 16:16:37 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	drawing(t_data *data)
{
	// draw_map2d(data);
	cast_rays(data);
	// draw_player(data);
	// init_line(data, 0);
	// render_line(data, data->line);
}

t_distence	init_distence(t_line line)
{
	t_distence	d;

	d.dx = abs(line.x2 - line.x1);
	d.dy = abs(line.y2 - line.y1);
	d.dis = d.dx - d.dy;
	d.sx = 1;
	if (line.x1 > line.x2)
		d.sx = -1;
	d.sy = 1;
	if (line.y1 > line.y2)
		d.sy = -1;
	return (d);
}

void	render_line(t_data *data, t_line line)
{
	t_distence	d;
	int			dis2;

	d = init_distence(line);
	while (!(line.x1 == line.x2 && line.y1 == line.y2))
	{
		mlx_pixel_put(data->mlx, data->win, line.x1, line.y1, line.color);
		dis2 = 2 * d.dis;
		if (dis2 > -d.dy)
		{
			d.dis -= d.dy;
			line.x1 += d.sx;
		}
		if (dis2 < d.dx)
		{
			d.dis += d.dx;
			line.y1 += d.sy;
		}
	}
}

void	render_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
		{
			// if (i != rect.y && j != rect.x)
				mlx_pixel_put(data->mlx, data->win, j++, i, rect.color);
			// else
			// 	mlx_pixel_put(data->mlx, data->win, j++, i, 0);
		}
		i++;
	}
}
