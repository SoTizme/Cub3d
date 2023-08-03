/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:06:14 by shilal            #+#    #+#             */
/*   Updated: 2023/08/03 16:32:56 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	render_3d_map(t_data *data, t_draw *draw)
{
	int	i;
	int	s;

	i = 0;
	s = draw->f_height;
	while (i <= s)
		mlx_pixel_put(data->mlx, data->win, draw->x, i++, YELLOW);
	s += draw->w_height;
	while (i <= s)
		mlx_pixel_put(data->mlx, data->win, draw->x, i++, RED);
	s += draw->f_height;
	while (i <= s)
		mlx_pixel_put(data->mlx, data->win, draw->x, i++, YELLOW);
}

void	draw_wall(t_data *data, int i)
{
	float	p_wall;
	float	p_floor;
	float	wall_height;
	float	correct_d;

	correct_d = data->rays[i].dist * cos(data->rays[i].angle - data->angle);
	wall_height = (TILE_SIZE / correct_d) * fabs((WMAP / 2) / tan(FOV / 2));
	if (wall_height > 1080)
		wall_height = 1080;
	p_wall = (HMAP / 2) - (wall_height / 2);
	p_floor = (HMAP - wall_height) / 2;
	render_3d_map(data, &(t_draw){i, p_wall, p_floor, wall_height});
}