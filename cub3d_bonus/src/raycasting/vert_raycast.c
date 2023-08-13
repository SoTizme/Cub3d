/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 09:39:26 by mmoumani          #+#    #+#             */
/*   Updated: 2023/08/13 17:28:09 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vert	init_ver(void)
{
	t_vert	vert;

	vert.wall = 0;
	vert.x_wall = 0;
	vert.y_wall = 0;
	return (vert);
}

// vertical intersection steps
void	v_init_intrs(t_data *data, t_intrs *intrs, t_intrf r_face, float angle)
{
	intrs->x = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
	if (r_face.right)
		intrs->x += TILE_SIZE;
	intrs->y = data->player.y + (intrs->x - data->player.x) * tan(angle);
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

void	verical(t_data *data, t_intrs *intrs, t_vert *vert)
{
	while (1337)
	{
		if (has_wall_at(data, intrs->next_x, intrs->next_y))
		{
			vert->wall = 1;
			vert->x_wall = intrs->next_x;
			vert->y_wall = intrs->next_y;
			vert->content = get_content(data, intrs->next_x, intrs->next_y);
			break ;
		}
		else
		{
			intrs->next_x += intrs->x_step;
			intrs->next_y += intrs->y_step;
		}
	}
}
