/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:51:28 by shilal            #+#    #+#             */
/*   Updated: 2023/07/11 16:31:56 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(char *error_msg)
{
	printf("Error : %s\n", error_msg);
	exit (0);
}

int	main(int ac, char **av)
{
	t_elem val;

	val = (t_elem){0};
	if (ac != 2)
		ft_error("You have more/less 2 argument");
	parser(&val, av[1]);
}