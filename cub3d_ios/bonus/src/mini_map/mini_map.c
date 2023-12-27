/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:55:14 by mmoumani          #+#    #+#             */
/*   Updated: 2023/08/15 18:40:28 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_rect(t_data *data, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			my_mlx_pixel_put(data->img, j++, i, rect.color);
		i++;
	}
}

void	draw_player(t_data *d)
{
	int	x;
	int	y;

	x = (7.5 * 15) - 7.5;
	y = (7.5 * 15) - 7.5;
	render_rect(d, (t_rect){x, y, 15, 15, W_RED});
}

void	render_minimap(t_data *data, int x, int y, char c)
{
	if (c == '1')
		render_rect(data, (t_rect){x, y, 15, 15, TEAL});
	else if (c == '2')
		render_rect(data, (t_rect){x, y, 15, 15, GREY});
	else if (c == ' ')
		render_rect(data, (t_rect){x, y, 15, 15, GREEN});
	else
		render_rect(data, (t_rect){x, y, 15, 15, WHITE});
}

void	draw_map2d(t_data *data, int wd, int hg)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = data->px - 7;
	x = 0;
	while (i < data->px + 7)
	{
		j = data->py - 7;
		y = 0;
		while (j < data->py + 7)
		{
			if (j >= 0 && i >= 0 && i < wd && j < hg)
				render_minimap(data, x, y, data->map[j][i]);
			else
				render_rect(data, (t_rect){x, y, 15, 15, GREEN});
			y += 15;
			j++;
		}
		x += 15;
		i++;
	}
}

void	draw_mini_map(t_data *data)
{
	data->px = data->player.x / TILE_SIZE;
	data->py = data->player.y / TILE_SIZE;
	draw_map2d(data, data->width / TILE_SIZE, data->height / TILE_SIZE);
	draw_player(data);
}
