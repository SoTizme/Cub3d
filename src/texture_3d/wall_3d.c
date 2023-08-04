/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:06:14 by shilal            #+#    #+#             */
/*   Updated: 2023/08/04 14:36:20 by shilal           ###   ########.fr       */
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

void	render_3d_map(t_data *data, t_draw *draw)
{
	int	i;
	int	s;

	i = 0;
	s = draw->f_height;
	while (i < s)
		my_mlx_pixel_put(data->img, draw->x, i++, data->ceil);
	s += draw->w_height;
	while (i < s)
		my_mlx_pixel_put(data->img, draw->x, i++, GREEN);
	while (i < HMAP)
		my_mlx_pixel_put(data->img, draw->x, i++, data->floor);
}

void	draw_wall(t_data *data, int i)
{
	float	p_floor;
	float	wall_height;
	float	correct_d;

	correct_d = data->rays[i].dist * cos(data->rays[i].angle - data->angle);
	wall_height = (TILE_SIZE / correct_d) * fabs((WMAP / 2) / tan(FOV / 2));
	if (wall_height > 1080)
		wall_height = 1080;
	p_floor = (HMAP - wall_height) / 2;
	render_3d_map(data, &(t_draw){i, p_floor, wall_height});
}
