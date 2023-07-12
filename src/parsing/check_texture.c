/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:50:51 by shilal            #+#    #+#             */
/*   Updated: 2023/07/12 19:17:54 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	add_texture(t_elem *val, char *s, char *chr)
{
	if (!ft_strcmp(chr, "NO"))
		val->txtur->no = ft_strdup(s);
	else if (!ft_strcmp(chr, "SO"))
		val->txtur->so = ft_strdup(s);
	else if (!ft_strcmp(chr, "WE"))
		val->txtur->we = ft_strdup(s);
	else if (!ft_strcmp(chr, "EA"))
		val->txtur->ea = ft_strdup(s);
}

void	check_color(t_elem *val, char *s, char *chr)
{
	char	**colrs;
	int		nb;
	int		i;

	i = -1;
	nb = 0;
	colrs = ft_split(s, ',');
	if (!ft_strcmp(chr, "F"))
	{
		while (colrs[++i])
		{
			nb = ft_atoi(colrs[i]);
			if (nb >= 0 && nb < 255)
				val->txtur->f[i] = &nb;
			else
				break ;
		}
	}
	else if (!ft_strcmp(chr, "C"))
	{
		while (colrs[++i])
		{
			nb = ft_atoi(colrs[i]);
			if (nb >= 0 && nb < 255)
				val->txtur->f[i] = &nb;
			else
				break ;
		}
	}
}

void	texture(char *line, t_elem *val, char *chr)
{
	char	**l;
	char	*t;

	t = ft_strtrim(line, "\n");
	l = ft_split(t, ' ');
	free(t);
	if (!ft_strcmp(l[0], chr))
	{
		if (l[1] && !l[2])
		{ 
			if (!ft_strcmp("F", chr) || !ft_strcmp("C", chr))
				return (check_color(val, l[1], chr));
			if (check_file_format(l[1], ".xpm"))
			{
				add_texture(val, l[1], chr);
				return (double_free(l));
			}
			else
				ft_error("Check texture format .xpm");
		}
		else
			texture_error(chr, l);
	}
	double_free(l);
}

int	check_texture(t_elem *val, t_list **map)
{
	t_list *tmp;

	tmp = *map;
	while (tmp)
	{
		if (!val->txtur->no)
			texture(tmp->content, val, "NO");
		else if (!val->txtur->so)
			texture(tmp->content, val, "SO");
		else if (!val->txtur->we)
			texture(tmp->content, val, "WE");
		else if (!val->txtur->ea)
			texture(tmp->content, val, "EA");
		else if (!val->txtur->f)
			texture(tmp->content, val, "F");
		else if (!val->txtur->c)
			texture(tmp->content, val, "C");
		tmp = tmp->next;
	}
	if (!val->txtur->ea || !val->txtur->so || !val->txtur->no || !val->txtur->we)
		ft_error("Check if any texture missing");
	return (0);
}
