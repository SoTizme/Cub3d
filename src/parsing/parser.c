/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:26:42 by shilal            #+#    #+#             */
/*   Updated: 2023/07/13 14:01:13 by mmoumani         ###   ########.fr       */
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

int	parser(t_data *data, char *file_name)
{
	int		fd;
	char	*line;
	t_list	*map;

	map = NULL;
	if (!check_file_format(file_name, ".cub"))
		ft_error("Please check file format .cub");
	if ((fd = open(file_name, O_RDONLY)) == -1)
		ft_error(strerror(errno));
	while ((line = get_next_line(fd)))
	{
		ft_lstadd_back(&map, ft_lstnew(ft_strtrim(line, "\n")));
		free(line);
	}
	check_texture(data, &map);
	ft_lstclear(&map, free);
	return (0);
}