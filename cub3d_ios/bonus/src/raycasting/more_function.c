/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:36:46 by mmoumani          #+#    #+#             */
/*   Updated: 2023/08/18 17:48:37 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	mouse(int x, int y, t_data *data)
{
	(void)y;
	data->player.turn = 0;
	if (x > data->old_x)
	{
		data->player.turn = 1;
		data->old_x = x;
	}
	else if (x < data->old_x)
	{
		data->player.turn = -1;
		data->old_x = x;
	}
	return (0);
}

void	drawing(t_data *data)
{
	void	*img;

	img = mlx_new_image(data->mlx, WMAP, HMAP);
	if (data->img.img)
		mlx_destroy_image(data->mlx, data->img.img);
	data->img.img = img;
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.size_line, &data->img.endian);
	cast_rays(data);
	draw_mini_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
}

char	get_content(t_data *data, float x, float y)
{
	int		map_x;
	int		map_y;
	char	c;

	if (x <= 0 || x >= data->width || y <= 0 || y >= data->height)
		return ('1');
	map_x = floor(x / TILE_SIZE);
	map_y = floor(y / TILE_SIZE);
	c = data->map[map_y][map_x];
	if (!c)
		return ('1');
	return (c);
}

int	has_wall(t_data *data, float x, float y)
{
	int	fx;
	int	fy;
	int	fx2;
	int	fy2;

	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
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
	if (data->map[fy][fx] == '2' || data->map[fy2][fx2] == '2'
		|| data->map[fy2][fx] == '2' || data->map[fy][fx2] == '2')
		return (1);
	if (data->map[fy][fx] == '3' && data->map[fy2][fx2] != '3')
		data->map[fy][fx] = '2';
	return (0);
}
