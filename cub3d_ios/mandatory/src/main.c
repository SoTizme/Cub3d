/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:51:28 by shilal            #+#    #+#             */
/*   Updated: 2023/08/13 14:22:20 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	if (!t.c || !t.f)
		ft_error(strerror(errno));
	data.txtur = &t;
	data.check = &check;
	parser(&data, av[1]);
	get_angel(&data, data.py, data.px);
	init_data(&data);
	display(&data);
}
