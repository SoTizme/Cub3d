/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:31:54 by shilal            #+#    #+#             */
/*   Updated: 2023/07/20 11:04:33 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	my_lstsize(t_list *lst)
{
	int	i;
	int	j;

	if (!lst)
		return (0);
	i = 1;
	j = 1;
	while (lst)
	{
		if (i > 6 && lst->content[0])
			break;
		if (lst->content[0])
			i++;
		j++;
		lst = lst->next;
	}
	i = 1;
	while (lst)
	{
		i++;
		if (!lst->content[0])
			ft_error("You have a newline in your map");
		lst = lst->next;
	}
	return (i);
}

char	*my_strdup(char *s, int len)
{
	int		i;
	char	*str;

	i = -1;
	str = malloc(len + 1);
	while (s[++i])
		str[i] = s[i];
	if (i == -1)
		ft_error("You have a newline in your map");
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

void	cont_texture(t_data *data, char c)
{
	if (c == 'E' || c == 'N' || c == 'W' || c == 'S')
	{
		if (c == 'E' && data->check->t_ea < 2)
			data->check->t_ea++;
		else if (c == 'N' && data->check->t_no < 2)
			data->check->t_no++;
		else if (c == 'W' && data->check->t_we < 2)
			data->check->t_we++;
		else if (c == 'S' && data->check->t_so < 2)
			data->check->t_so++;
		else
			ft_error("Check the map");
	}
	else
		return ;
}

void	get_map(t_data *data, int len, t_list *tmp)
{
	int		i;
	int		j;
	int		c;

	i = -1;
	while (tmp)
	{
		j = 0;
		data->map[++i] = malloc(len + 1);
		if (!tmp->content[j])
			data->map[i] = ft_strdup("\n");
		while (tmp->content[j])
		{
			c = tmp->content[j];
			if (c != ' ' && c != '1' && c != '0' && c != 'S' && c != 'N' && 
				c != 'W' && c != 'E' && c != 9)
				ft_error("there's a letter either than '1' '0' 'S' 'N' 'W' 'E'");
			cont_texture(data, c);
			j++;
		}
		data->map[i] = my_strdup(tmp->content, len);
		tmp = tmp->next;
	}
	data->map[i + 1] = NULL;
}