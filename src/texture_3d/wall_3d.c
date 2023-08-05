/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:06:14 by shilal            #+#    #+#             */
/*   Updated: 2023/08/05 17:13:59 by mmoumani         ###   ########.fr       */
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

void	render_3d_map(t_data *data, float topwall, float bottomwall, t_draw *draw, int x)
{
	int	i;
	// int	s;
	int distance_center_wall;
	int correspanding_y_coordinate;
	char *dst;
	i = 0;
	// s = draw->f_height;
	while (i < topwall)
		my_mlx_pixel_put(data->img, draw->x, i++, data->ceil);
	// s += draw->w_height;
	while (i < bottomwall)
	{
		distance_center_wall = i + (draw->w_height / 2) - (HMAP / 2);
		correspanding_y_coordinate = (int)(distance_center_wall
				* (float)data->tex->height / draw->w_height)
			% data->tex->height;
		// printf("%s ** %d ** %d\n", dst, x, i);
		dst = data->tex->addr + correspanding_y_coordinate * data->tex->size_line
			+ x * (data->tex->bits_per_pixel / 8);
		// printf("%s **\n", dst);
		my_mlx_pixel_put(data->img, draw->x, i, *(unsigned int *)dst);
		// my_mlx_pixel_put(data->img, draw->x, i++, 0);
		i++;
	}
	while (i < HMAP)
		my_mlx_pixel_put(data->img, draw->x, i++, data->floor);
}

int	configure_data(t_data *data, int i)
{
	int		x;

	if (!data->rays[i].is_vert)
	{
		if (data->rays[i].angle > 0 && data->rays[i].angle < SO)
			data->tex = data->no;
		else
			data->tex = data->so;
		x = (int)(data->rays[i].x * data->tex->width / TILE_SIZE) % data->tex->width;
	}
	else
	{
		if (data->rays[i].angle > EA && data->rays[i].angle < WE)
			data->tex = data->we;
		else
			data->tex = data->ea;
		x = (int)(data->rays[i].y * data->tex->width / TILE_SIZE) % data->tex->width;
	}
	return x;
}

void	draw_wall(t_data *data, int i)
{
	// float	p_floor;
	float	wall_height;
	float	correct_d;
	float	topwall;
	float	bottomwall;

	correct_d = data->rays[i].dist * cos(data->rays[i].angle - data->angle);
	wall_height = (TILE_SIZE / correct_d) * fabs((WMAP / 2) / tan(FOV / 2));
	topwall = ((HMAP / 2) - (wall_height / 2));
	if (topwall < 0)
		topwall = 0;
	bottomwall = ((HMAP / 2) + (wall_height / 2));
	if (bottomwall > HMAP)
		bottomwall = HMAP;
	// p_floor = (HMAP - wall_height) / 2;
	// render_3d_map(data, &(t_draw){i, topwall, wall_height}, configure_data(data, data->no, i));
	render_3d_map(data, topwall, bottomwall, &(t_draw){i, topwall, wall_height}, configure_data(data, i));
}