/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horiz_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:37:50 by mmoumani          #+#    #+#             */
/*   Updated: 2023/11/09 15:45:12 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_horz	init_hor(void)
{
	t_horz	horz;

	horz.wall = 0;
	horz.x_wall = 0;
	horz.y_wall = 0;
	return (horz);
}

void	h_init_intrs(t_data *data, t_intrs *intrs, t_intrf r_face, float angle)
{
	intrs->y = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
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
}

void	horizontal(t_data *data, t_intrs *intrs, t_horz *horz, int up)
{
	float	next_y;

	while (1337)
	{
		next_y = intrs->next_y;
		if (up)
			next_y = intrs->next_y - 1;
		if (has_wall_at(data, intrs->next_x, next_y))
		{
			horz->wall = 1;
			horz->x_wall = intrs->next_x;
			horz->y_wall = intrs->next_y;
			break ;
		}
		else
		{
			intrs->next_x += intrs->x_step;
			intrs->next_y += intrs->y_step;
		}
	}
}
