/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:26:42 by shilal            #+#    #+#             */
/*   Updated: 2023/07/21 14:35:15 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_file_format(char *file_name, char *ext)
{
	char	*last_accur;

	last_accur = ft_strrchr(file_name, '.');
	if (!last_accur || ft_strlen(last_accur) < ft_strlen(ext))
		return (0);
	if (ft_strcmp(last_accur, ext) != 0)
		return (0);
	return (1);
}

void	get_position(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == 'N' || data->map[i][j] == 'W' || 
				data->map[i][j] == 'S' || data->map[i][j] == 'E')
			{
				data->x_player = j;
				data->y_player = i;
			}
		}
	}
}

int	parser(t_data *data, char *file_name)
{
	int		fd;
	char	*line;

	if (!check_file_format(file_name, ".cub"))
		ft_error("Please check file format .cub");
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_error(strerror(errno));
	while ((line = get_next_line(fd)))
	{
		ft_lstadd_back(&data->s_map, ft_lstnew(ft_strtrim(line, "\n")));
		free(line);
	}
	if (!data->s_map)
		ft_error("We have a empty file");
	check_texture(data);
	get_position(data);
	//ft_lstclear(&data->s_map, free);
	return (0);
}