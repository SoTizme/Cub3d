/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:42:29 by mmoumani          #+#    #+#             */
/*   Updated: 2023/11/09 15:43:50 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	update_angle(float angle)
{
	angle = remainder(angle, PI * 2);
	if (angle < 0)
		angle += PI * 2;
	return (angle);
}

t_intrf	init_intrf(float angle)
{
	t_intrf	r_interface;

	r_interface.down = (angle > 0 && angle < PI);
	r_interface.up = !r_interface.down;
	r_interface.right = (angle < 0.5 * PI || angle > 1.5 * PI);
	r_interface.left = !r_interface.right;
	return (r_interface);
}

// float rad(int deg)
// {
// 	float	rad;
	
// 	rad = deg * (PI/180);
// 	return (rad);
// }

// t_intrf	ray_intrf(float angle)
// {
// 	t_intrf	r_interface;

// 	r_interface.up = (angle > rad(45) && angle < rad(135));
// 	r_interface.down = (angle > rad(225) / 4 && angle < rad(315));
// 	// r_interface.right = (angle < 0.5 * PI || angle > 1.5 * PI);
// 	// r_interface.left = !r_interface.right;
// 	return (r_interface);
// }


float	dist_2point(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

	// int	check_behind(t_data *data, float x, float y)
	// {
	// 	float	hypo;
	// 	float	r;

	// 	hypo = dist_2point(data->player.x, data->player.y, x, y);
	// 	r = tan(data->angle) * hypo;
	// 	(void)r;
	// 	return (0);
	// }

// int	has_wall(t_data *data, float x, float y)
// {
// 	int	fx;
// 	int	fy;
// 	int	fx2;
// 	int	fy2;

// 	if (x < 0 || x > data->width || y < 0 || y > data->height)
// 		return (1);
// 	fx = floor((data->player.x) / TILE_SIZE);
// 	fy = floor((data->player.y) / TILE_SIZE);
// 	fx2 = floor(x / TILE_SIZE);
// 	fy2 = floor(y / TILE_SIZE);
// 	if (data->map[fy][fx] == '1' || data->map[fy2][fx2] == '1'
// 		|| data->map[fy2][fx] == '1' || data->map[fy][fx2] == '1')
// 		return (1);
// 	if (data->map[fy][fx] == ' ' || data->map[fy2][fx2] == ' '
// 		|| data->map[fy2][fx] == ' ' || data->map[fy][fx2] == ' ')
// 		return (1);
// 	return (0);
// }

int	has_wall_at(t_data *data, float x, float y)
{
	int		fx;
	int		fy;
	char	c;

	if (x < 0 || x >= data->width || y < 0 || y >= data->height)
		return (1);
	fx = floor(x / TILE_SIZE);
	fy = floor(y / TILE_SIZE);
	c = data->map[fy][fx];
	if (!c || (c == '1' || c == ' '))
		return (1);
	return (0);
}

void	initialition(t_data *data, t_horz *horz, t_vert *vert, int i)
{
	if (vert->dist <= horz->dist)
	{
		data->rays[i].dist = vert->dist;
		data->rays[i].x = vert->x_wall;
		data->rays[i].y = vert->y_wall;
		data->rays[i].is_vert = 1;
	}
	else
	{
		data->rays[i].dist = horz->dist;
		data->rays[i].x = horz->x_wall;
		data->rays[i].y = horz->y_wall;
		data->rays[i].is_vert = 0;
	}
}
