/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 13:26:36 by mmoumani          #+#    #+#             */
/*   Updated: 2023/08/02 16:19:07 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	cast_one_ray(t_data *d, float angle, int i)
{
	t_intrf		r_face;
	t_intrs		intrs;
	t_horz		h;
	t_vert		v;

	angle = update_angle(angle);
	r_face = init_intrf(angle);
	h = init_hor();
	h_init_intrs(d, &intrs, r_face, angle);
	horizontal(d, &intrs, &h);
	v = init_ver();
	v_init_intrs(d, &intrs, r_face, angle);
	verical(d, &intrs, &v);
	h.dist = INT_MAX;
	if (h.wall)
		h.dist = dist_2point(d->player.x, d->player.y, h.x_wall, h.y_wall);
	v.dist = INT_MAX;
	if (v.wall)
		v.dist = dist_2point(d->player.x, d->player.y, v.x_wall, v.y_wall);
	initialition(d, &h, &v, i);
	d->rays[i].angle = angle;
	d->rays[i].down = r_face.down;
	d->rays[i].up = r_face.up;
	d->rays[i].left = r_face.left;
	d->rays[i].right = r_face.right;
}

void	cast_rays(t_data *d)
{
	float	angle;
	int		i;

	d->n_rays = 120;
	angle = d->angle - (FOV / 2);
	d->rays = malloc(sizeof(t_ray) * d->n_rays);
	d->size = 1920 / d->n_rays;
	i = 0;
	while (i < d->n_rays)
	{
		cast_one_ray(d, angle, i);
		draw_wall(d, i);
		// render_line(d, (t_line){
		// 	d->player.x, d->player.y, d->rays[i].x, d->rays[i].y, RED
		// });
		angle += FOV / d->n_rays;
		i++;
	}
}
