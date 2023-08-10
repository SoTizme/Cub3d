/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:06:43 by mmoumani          #+#    #+#             */
/*   Updated: 2023/08/09 20:56:36 by mmoumani         ###   ########.fr       */
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

t_img	*new_img(t_data *data, char *path)
{
	t_img	*img;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_error(strerror(errno));
	close(fd);
	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		ft_error(strerror(errno));
	img->img = mlx_xpm_file_to_image(data->mlx, path,
			&img->width, &img->height);
	if (!img->img)
		ft_error("invalid texture path");
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->size_line, &img->endian);
	return (img);
}

void	init_data(t_data *data)
{
	data->mlx = mlx_init();
	data->width *= TILE_SIZE;
	data->height *= TILE_SIZE;
	data->player.x = data->px * TILE_SIZE + (TILE_SIZE / 2);
	data->player.y = data->py * TILE_SIZE + (TILE_SIZE / 2);
	data->no = new_img(data, data->txtur->no);
	data->so = new_img(data, data->txtur->so);
	data->we = new_img(data, data->txtur->we);
	data->ea = new_img(data, data->txtur->ea);
	data->win = mlx_new_window(data->mlx, WMAP, HMAP, "cub3d");
}

void	get_angel(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'N')
		data->player.angle = NO;
	else if (data->map[i][j] == 'S')
		data->player.angle = SO;
	else if (data->map[i][j] == 'E')
		data->player.angle = EA;
	else if (data->map[i][j] == 'W')
		data->player.angle = WE;
}
