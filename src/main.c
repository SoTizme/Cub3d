/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:51:28 by shilal            #+#    #+#             */
/*   Updated: 2023/07/25 18:04:36 by mmoumani         ###   ########.fr       */
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
	data->player.x = data->px * TILE_SIZE + 12;
	data->player.y = data->py * TILE_SIZE + 12;
	data->player.fov = 60 * (PI / 180);
	data->n_rays *= data->width / STRIP_WIDTH;
}

void	get_angel(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'N')
		data->angel = NO;
	else if (data->map[i][j] == 'S')
		data->angel = SO;
	else if (data->map[i][j] == 'E')
		data->angel = EA;
	else if (data->map[i][j] == 'W')
		data->angel = WE;
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
	system("leaks cub3d");
}


//         111111111       11111111111111
//         1000000001      10000000000001
//        110110000011     10000000000001
//       11100100000011    10000000000011
// 111111111011000001111   11110000000011
// 10000000001100000111011   1111111111
// 111101111111110111000001
// 1111011111111110111010101
// 1100000111110101110000001
// 1000000000000000110000001
// 10000000000000001101010W1
// 1100000111010101111101111111
// 11110111 1110101  10111101111
// 111111111 1111111 11111111111