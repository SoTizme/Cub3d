/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:51:28 by shilal            #+#    #+#             */
/*   Updated: 2023/08/03 16:24:40 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	double_free(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

char	*is_dgit(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!ft_isdigit(s[i]))
			return ("-1");
	}
	return (s);
}

void	init_player(t_data *data)
{
	data->width *= TILE_SIZE;
	data->height *= TILE_SIZE;
	data->player.x = data->px * TILE_SIZE + (TILE_SIZE / 2);
	data->player.y = data->py * TILE_SIZE + (TILE_SIZE / 2);
	//data->n_rays = data->width / STRIP_WIDTH;
}

void	get_angel(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'N')
		data->angle = NO;
	else if (data->map[i][j] == 'S')
		data->angle = SO;
	else if (data->map[i][j] == 'E')
		data->angle = EA;
	else if (data->map[i][j] == 'W')
		data->angle = WE;
}

int	main(int ac, char **av)
{
	t_data	data;
	t_txtur	t;
	t_check	check;

	if (ac != 2)
		ft_error("You have more/less 2 argument");
	data = (t_data){0};
	t = (t_txtur){0};
	check = (t_check){0};
	t.c = (int *)malloc(3 * sizeof(int));
	t.f = (int *)malloc(3 * sizeof(int));
	data.txtur = &t;
	data.check = &check;
	parser(&data, av[1]);
	get_angel(&data, data.py, data.px);
	init_player(&data);
	display(&data);
}
