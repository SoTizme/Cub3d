/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:06:14 by shilal            #+#    #+#             */
/*   Updated: 2023/08/03 20:02:13 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void    my_mlx_pixel_put(t_img data, int x, int y, unsigned int color)
{
    int     pos;
    char    *mlx_data_addr;

    pos = (y * data.size_line + x * (data.bits_per_pixel / 8));
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
	{
		my_mlx_pixel_put(data->img, draw->x, i, BLUE);
		i++;
	}
	s += draw->w_height;
	while (i < s)
	{
		my_mlx_pixel_put(data->img, draw->x, i, GREEN);
		i++;
	}
	s += draw->f_height;
	while (i < s)
	{
		my_mlx_pixel_put(data->img, draw->x, i, 0);
		i++;
	}
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