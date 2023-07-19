/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:31:54 by shilal            #+#    #+#             */
/*   Updated: 2023/07/19 16:38:48 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*my_strdup(char *s, int len)
{
	int		i;
	char	*str;

	i = -1;
	str = malloc(len + 1);
	while (s[++i])
		str[i] = s[i];
	while (i < len)
	{
		str[i] = ' ';
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	get_the_tall_line(t_list **map)
{
	t_list	*tmp;
	int		i;
	int		len;

	tmp = *map;
	i = 0;
	len = 0;
	while (tmp)
	{
		if (tmp->content[0])
		{
			if ((i = ft_strlen(tmp->content)) > len)
				len = i;
		}
		tmp = tmp->next;
	}
	return (len);
}
