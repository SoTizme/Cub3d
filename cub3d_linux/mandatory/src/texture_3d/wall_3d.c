/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:21:14 by mmoumani          #+#    #+#             */
/*   Updated: 2023/08/17 22:53:17 by mmoumani         ###   ########.fr       */
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

void	render_3d_map(t_data *d, t_draw *draw, int x)
{
	int		i;
	int		distance_center_wall;
	int		correspanding_y_coordinate;
	char	*dst;

	i = 0;
	while (i < draw->t_wall)
		my_mlx_pixel_put(d->img, draw->x, i++, d->ceil);
	while (i < draw->b_wall)
	{
		distance_center_wall = i + (draw->h_wall / 2) - (HMAP / 2);
		correspanding_y_coordinate = (int)(distance_center_wall
				* (float)d->tex->height / draw->h_wall)
			% d->tex->height;
		dst = d->tex->addr + correspanding_y_coordinate * d->tex->size_line
			+ x * (d->tex->bits_per_pixel / 8);
		my_mlx_pixel_put(d->img, draw->x, i, *(unsigned int *)dst);
		i++;
	}
	while (i < HMAP)
		my_mlx_pixel_put(d->img, draw->x, i++, d->floor);
}

int	config_data(t_data *d, int i)
{
	int	x;

	if (!d->rays[i].is_vert)
	{
		if (d->rays[i].angle >= EA && d->rays[i].angle < WE)
			d->tex = d->so;
		else
			d->tex = d->no;
		x = (int)(d->rays[i].x * d->tex->width / TILE_SIZE) % d->tex->width;
	}
	else
	{
		if (d->rays[i].angle > SO && d->rays[i].angle <= NO)
			d->tex = d->we;
		else
			d->tex = d->ea;
		x = (int)(d->rays[i].y * d->tex->width / TILE_SIZE) % d->tex->width;
	}
	return (x);
}

// to find height of the wall need this operation :
// (wall height / distance to wall) * distance to projection plane 

// distance to wall = ray distance * cos(angle - player angle)
// wall height = TILE_SIZE
// distance to projection plane = (WMAP / 2) / tan(FOV / 2);

void	draw_wall(t_data *data, int i)
{
	float	h_wall;
	float	t_wall;
	float	b_wall;
	float	distance_to_wall;
	int		config;

	distance_to_wall = data->rays[i].dist
		* cos(data->rays[i].angle - data->player.angle);
	h_wall = (TILE_SIZE / distance_to_wall) * (WMAP / 2) / tan(FOV / 2);
	t_wall = ((HMAP / 2) - (h_wall / 2));
	if (t_wall < 0)
		t_wall = 0;
	b_wall = ((HMAP / 2) + (h_wall / 2));
	if (b_wall > HMAP)
		b_wall = HMAP;
	config = config_data(data, i);
	render_3d_map(data, &(t_draw){i, h_wall, t_wall, b_wall}, config);
}
