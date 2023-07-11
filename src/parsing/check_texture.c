/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:50:51 by shilal            #+#    #+#             */
/*   Updated: 2023/07/11 18:08:27 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	north_texture(char *line, t_elem *val)
{
	char	**l;
	char	*t;

	(void)val;
	t = ft_strtrim(line, "\n");
	l = ft_split(t, ' ');
	if (!ft_strcmp(l[0], "NO") && !l[2])
	{
		if (l[1])
		{ 
			if (check_file_format(l[1], ".xpm"))
			{
			//	path = ft_strdup(l[1]);
				return ;
			}
			else
				ft_error("Please check texture format .xpm");
		}
	}
	else
		ft_error("Path to the north texture missing");
}

int	check_texture(t_elem *val, t_list *map)
{
	t_list *tmp;

	tmp = map;
	while (tmp)
	{
		north_texture(tmp->content, val);
		tmp = tmp->next;
	}
	return (0);
}