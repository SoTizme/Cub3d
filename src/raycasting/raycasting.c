/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:26:36 by mmoumani          #+#    #+#             */
/*   Updated: 2023/07/29 12:03:48 by mmoumani         ###   ########.fr       */
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

t_ray_interface    init_ray_interface(float angle)
{
    t_ray_interface r_interface;

	r_interface.down = angle > 0 && angle < PI;
    r_interface.up = !r_interface.down;
	r_interface.right = angle < 0.5 * PI || angle > 1.5 * PI;
    r_interface.left = !r_interface.right;
	return (r_interface);
}

float dist_between_two_point(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

int	has_wall_at(t_data *data, float x, float y)
{
	int	fx;
	int	fy;

	if (x < 0 || x > data->width || y < 0 || y > data->height)
		return (1);
	fx = floor(x / TILE_SIZE);
	fy = floor(y / TILE_SIZE);
	if (data->map[fy][fx] == '1' || data->map[fy][fx] == ' ')
		return (1);
	return (0);
}

void	cast_one_ray(t_data *data, float angle, int i)
{
    t_ray_interface r_face;
	float			xintercept;
	float			yintercept;
	float			next_x;
	float			next_y;
	float			x_step;
	float			y_step;
    
	angle = update_angle(angle);
    r_face = init_ray_interface(angle);
	// horizontal
	
	int		hor_wall = 0;
	float	hor_x_wall = 0;
	float	hor_y_wall = 0;

	// find point A
	yintercept = floor(data->player.y / TILE_SIZE)  * TILE_SIZE;
	if (r_face.down)
		yintercept += TILE_SIZE;
	xintercept = data->player.x + (yintercept - data->player.y) / tan(angle);

	// horizontal intersection steps
	y_step = TILE_SIZE;
	if (r_face.up)
		y_step *= -1;
	x_step = y_step / tan(angle);
	if (r_face.left && x_step > 0)
		x_step *= -1;
	if (r_face.right && x_step < 0)
		x_step *= -1;
	
	next_x = xintercept;
	next_y = yintercept;
	if (r_face.up)
		next_y--;
	while (1337)
	{
		if (has_wall_at(data, next_x, next_y))
		{
			hor_wall = 1;
			hor_x_wall = next_x;
			hor_y_wall = next_y;
			break;
		}
		else
		{
			next_x += x_step;
			next_y += y_step;
		}
	}
	
	// vertical
	
	int		ver_wall = 0;
	float	ver_x_wall = 0;
	float	ver_y_wall = 0;

	// find point A
	xintercept = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
	if (r_face.right)
		xintercept += TILE_SIZE;
	yintercept = data->player.y + (xintercept - data->player.x) * tan(angle);

	// vertical intersection steps
	x_step = TILE_SIZE;
	if (r_face.left)
		x_step *= -1;
	y_step = x_step * tan(angle);
	if (r_face.up && y_step > 0)
		y_step *= -1;
	if (r_face.down && y_step < 0)
		y_step *= -1;
	
	next_x = xintercept;
	next_y = yintercept;
	if (r_face.left)
		next_x--;
	
	while (1337)
	{
		if (has_wall_at(data, next_x, next_y))
		{
			ver_wall = 1;
			ver_x_wall = next_x;
			ver_y_wall = next_y;
			break;
		}
		else
		{
			next_x += x_step;
			next_y += y_step;
		}
	}
	// cmp hori and ver
	int	hor_dist;
	hor_dist = INT_MAX;
	if (hor_wall)
		hor_dist = dist_between_two_point(data->player.x, data->player.y, hor_x_wall, hor_y_wall);
	int	ver_dist;
	ver_dist = INT_MAX;
	if (ver_wall)
		ver_dist = dist_between_two_point(data->player.x, data->player.y, ver_x_wall, ver_y_wall); 
	if (ver_dist < hor_dist)
	{
        data->rays[i].dist = ver_dist;
        data->rays[i].x = ver_x_wall;
        data->rays[i].y = ver_y_wall;
        data->rays[i].is_ver = 1;
    }
	else
	{
        data->rays[i].dist = hor_dist;
        data->rays[i].x = hor_x_wall;
        data->rays[i].y = hor_y_wall;
        data->rays[i].is_ver = 0;
    }
    data->rays[i].angle = angle;
    data->rays[i].down = r_face.down;
    data->rays[i].up = r_face.up;
    data->rays[i].left = r_face.left;
    data->rays[i].right = r_face.right;
}

void	cast_rays(t_data *data)
{
	float	angle;
	int		i;

	angle = data->angle - (data->player.fov / 2);
	data->rays = malloc(sizeof(t_ray) * data->n_rays);
	i = 0;
	while (i < data->n_rays)
	{
		cast_one_ray(data, angle, i);
		render_line(data, (t_line){data->player.x, data->player.y, data->rays[i].x, data->rays[i].y, RED});
		angle += data->player.fov / data->n_rays;
		i++;
	}
}
