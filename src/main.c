/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:51:28 by shilal            #+#    #+#             */
/*   Updated: 2023/07/12 18:38:35 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	double_free(char **s)
{
	int i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

int	main(int ac, char **av)
{
	t_elem val;
	t_txtur t;

	val = (t_elem){0};
	t = (t_txtur){0};
	val.txtur = &t;
	if (ac != 2)
		ft_error("You have more/less 2 argument");
	parser(&val, av[1]);
}