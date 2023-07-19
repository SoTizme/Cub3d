/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:51:28 by shilal            #+#    #+#             */
/*   Updated: 2023/07/19 15:19:46 by shilal           ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_data	data;
	t_txtur	t;
	t_check	check;

	data = (t_data){0};
	t = (t_txtur){0};
	check = (t_check){0};
	t.c = (int *)malloc(3 * sizeof(int));
	t.f = (int *)malloc(3 * sizeof(int));
	data.txtur = &t;
	data.check = &check;
	if (ac != 2)
		ft_error("You have more/less 2 argument");
	parser(&data, av[1]);
	//system("leaks cub3d");
}