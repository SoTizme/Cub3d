/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:26:36 by mmoumani          #+#    #+#             */
/*   Updated: 2023/07/29 15:03:49 by mmoumani         ###   ########.fr       */
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

t_intrf    init_intrf(float angle)
{
    t_intrf r_interface;

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
t_horz	init_hor(void)
{
	t_horz	horz;

	horz.wall = 0;
	horz.x_wall = 0;
	horz.y_wall = 0;
	return (horz);
}
t_vert	init_ver(void)
{
	t_vert	vert;

	vert.wall = 0;
	vert.x_wall = 0;
	vert.y_wall = 0;
	return (vert);
}

void	v_init_intrs(t_data *data, t_intrs *intrs, t_intrf r_face, float angle)
{
	intrs->x = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
	if (r_face.right)
		intrs->x += TILE_SIZE;
	intrs->y = data->player.y + (intrs->x - data->player.x) * tan(angle);

	// vertical intersection steps
	intrs->x_step = TILE_SIZE;
	if (r_face.left)
		intrs->x_step *= -1;
	intrs->y_step = intrs->x_step * tan(angle);
	if (r_face.up && intrs->y_step > 0)
		intrs->y_step *= -1;
	if (r_face.down && intrs->y_step < 0)
		intrs->y_step *= -1;
	
	intrs->next_x = intrs->x;
	intrs->next_y = intrs->y;
	if (r_face.left)
		intrs->next_x--;
}

void	h_init_intrs(t_data *data, t_intrs *intrs, t_intrf r_face, float angle)
{
	intrs->y = floor(data->player.y / TILE_SIZE)  * TILE_SIZE;
	if (r_face.down)
		intrs->y += TILE_SIZE;
	intrs->x = data->player.x + (intrs->y - data->player.y) / tan(angle);
	intrs->y_step = TILE_SIZE;
	if (r_face.up)
		intrs->y_step *= -1;
	intrs->x_step = intrs->y_step / tan(angle);
	if (r_face.left && intrs->x_step > 0)
		intrs->x_step *= -1;
	if (r_face.right && intrs->x_step < 0)
		intrs->x_step *= -1;
	
	intrs->next_x = intrs->x;
	intrs->next_y = intrs->y;
	if (r_face.up)
		intrs->next_y--;
}
void	cast_one_ray(t_data *data, float angle, int i)
{
    t_intrf		r_face;
	t_intrs		intrs;
	t_horz		horz;
	t_vert		vert;

	angle = update_angle(angle);
    r_face = init_intrf(angle);
	horz = init_hor();
	h_init_intrs(data, &intrs, r_face, angle);
	while (1337)
	{
		if (has_wall_at(data, intrs.next_x, intrs.next_y))
		{
			horz.wall = 1;
			horz.x_wall = intrs.next_x;
			horz.y_wall = intrs.next_y;
			break;
		}
		else
		{
			intrs.next_x += intrs.x_step;
			intrs.next_y += intrs.y_step;
		}
	}
	vert = init_ver();
	v_init_intrs(data, &intrs, r_face, angle);
	while (1337)
	{
		if (has_wall_at(data, intrs.next_x, intrs.next_y))
		{
			vert.wall = 1;
			vert.x_wall = intrs.next_x;
			vert.y_wall = intrs.next_y;
			break;
		}
		else
		{
			intrs.next_x += intrs.x_step;
			intrs.next_y += intrs.y_step;
		}
	}
	horz.dist = INT_MAX;
	if (horz.wall)
		horz.dist = dist_between_two_point(data->player.x, data->player.y, horz.x_wall, horz.y_wall);
	vert.dist = INT_MAX;
	if (vert.wall)
		vert.dist = dist_between_two_point(data->player.x, data->player.y, vert.x_wall, vert.y_wall); 
	if (vert.dist < horz.dist)
	{
        data->rays[i].dist = vert.dist;
        data->rays[i].x = vert.x_wall;
        data->rays[i].y = vert.y_wall;
        data->rays[i].is_vert = 1;
    }
	else
	{
        data->rays[i].dist = horz.dist;
        data->rays[i].x = horz.x_wall;
        data->rays[i].y = horz.y_wall;
        data->rays[i].is_vert = 0;
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
