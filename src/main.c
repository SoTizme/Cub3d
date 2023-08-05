/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:51:28 by shilal            #+#    #+#             */
/*   Updated: 2023/08/05 17:08:51 by mmoumani         ###   ########.fr       */
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
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "cub3d");
	data->width *= TILE_SIZE;
	data->height *= TILE_SIZE;
	data->player.x = data->px * TILE_SIZE + (TILE_SIZE / 2);
	data->player.y = data->py * TILE_SIZE + (TILE_SIZE / 2);
	data->n_rays = data->width / STRIP_WIDTH;
	// data->tex = NULL;
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

t_img *new_img(t_data *data, char *path)
{
    t_img *img;
	int fd;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error(strerror(errno));
	close(fd);
	img = (t_img *)malloc(sizeof(t_img));
    if (!img)
        ft_error(strerror(errno));
    img->img = mlx_xpm_file_to_image(data->mlx, path, &img->width, &img->height);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->size_line, &img->endian);

    return img;
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
	if (!t.c || !t.f)
        ft_error(strerror(errno));
	data.txtur = &t;
	data.check = &check;
	parser(&data, av[1]);
	get_angel(&data, data.py, data.px);
	init_player(&data);
	// printf("%s\n", data.txtur->no);
	// data.txtur->no = ft_strdup("planks.xpm");
	// data.txtur->so = ft_strdup("greystone.xpm");
	// data.txtur->we = ft_strdup("wood.xpm");
	// data.txtur->ea = ft_strdup("planks.xpm");
	data.no = new_img(&data, data.txtur->no);
	data.so = new_img(&data, data.txtur->so);
	data.we = new_img(&data, data.txtur->we);
	data.ea = new_img(&data, data.txtur->ea);
	
	display(&data);
}
