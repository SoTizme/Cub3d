/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:06:14 by shilal            #+#    #+#             */
/*   Updated: 2023/08/03 13:19:58 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_3d_map(t_data *data, t_draw *draw)
{
	int	i;
	int	s;

	i = 0;
	s = draw->f_height;
	while (i < s)
	{
		mlx_pixel_put(data->mlx, data->win, draw->x, i, YELLOW);
		i++;
	}
	s += draw->w_height;
	while (i < s)
	{
		mlx_pixel_put(data->mlx, data->win, draw->x, i, RED);
		i++;
	}
	s += draw->f_height;
	while (i < s)
	{
		mlx_pixel_put(data->mlx, data->win, draw->x, i, YELLOW);
		i++;
	}
}

void	draw_wall(t_data *data, int i)
{
	float	r;
	float	a;
	float	wall_height;
	float	distance;
	float	correct_d;

	correct_d = data->rays[i].dist * cos(data->rays[i].angle - data->angle);
	distance  = fabs((WMAP / 2) / tan(FOV / 2));
	wall_height = (TILE_SIZE / correct_d) * distance;
	if (wall_height > 1080)
		wall_height = 1080;
	r = (HMAP / 2) - (wall_height / 2);
	a = (HMAP - wall_height) / 2;
	render_3d_map(data, &(t_draw){i, r, a, wall_height});
	// render_rect(data, (t_rect){i * data->size, 0, data->size, a, YELLOW});
	// render_rect(data, (t_rect){i * data->size, r, data->size, wall_height, RED});
	// render_rect(data, (t_rect){i * data->size, r + wall_height, data->size, a, BLUE});
}