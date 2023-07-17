/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:42:32 by shilal            #+#    #+#             */
/*   Updated: 2023/07/17 10:14:05 by shilal           ###   ########.fr       */
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

// int	my_lstsize(t_list *lst)
// {
// 	int	i;
// 	if (!lst)
// 		return (0);
// 	i = 1;
// 	while (lst->next)
// 	{
// 		if (lst->content[0])
// 			i++;
// 		lst = lst->next;
// 	}
// 	return (i);
// }

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

void	get_map(t_data *data, int len, t_list *tmp)
{
	int		i;
	int		j;
	int		c;

	i = 0;
	while (tmp)
	{
		j = 0;
		data->map[i] = malloc(len + 1);
		if (!tmp->content[j])
			data->map[i] = ft_strdup("\n");
		while (tmp->content[j])
		{
			c = tmp->content[j];
			if (c != ' ' && c != '1' && c != '0' && c != 'S' && c != 'N' && 
				c != 'W' && c != 'E' && c != 9)
				ft_error("there's a letter either than '1' '0' 'S' 'N' 'W' 'E'");
			j++;
		}
		data->map[i] = my_strdup(tmp->content, len);
		tmp = tmp->next;
		i++;
	}
	data->map[i] = NULL;
}

void	check_map(t_data *data, t_list **map)
{
	t_list	*tmp;
	t_list	*check;
	int		i;
	int		len;

	tmp = *map;
	i = 0;
	len = ft_lstsize(tmp) - 6;
	data->map = (char **)malloc((len + 1) * sizeof(char *));
	while (i < 6 || (!tmp->content[0]))
	{
		if (tmp->content[0])
			i++;
		tmp = tmp->next;
	}
	check = tmp;
	len = get_the_tall_line(&check);
	get_map(data, len, tmp);
	i = 0;
	while(data->map[i])
	{
		printf("%s|\n", data->map[i]);
		i++;
	}
}
