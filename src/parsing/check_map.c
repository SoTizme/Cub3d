/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:42:32 by shilal            #+#    #+#             */
/*   Updated: 2023/07/13 17:42:48 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// 0 for an empty space, 1 for a wall, and N,S,E or W
int	my_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next)
	{
		if (lst->content[0])
			i++;
		lst = lst->next;
	}
	return (i);
}

void	get_map(t_data *data, int len, t_list *map)
{
	t_list	*tmp;
	int		i;
	int		j;
	char	c;

	tmp = map;
	while (tmp)
	{
		i = -1;
		j = -1;
		while (tmp->content[++i])
		{
			c = tmp->content[i];
			data->map[i] = malloc(len);
			if (c != ' ' || c != '1' || c != '0' || c != 'N' 
				|| c != 'S' || c != 'E' || c != 'W')
			{
				data->map[i][++j] = c;
				printf("%c ", tmp->content[i]);
			}
			else
				ft_error("there's a letter either than '1' '0' 'S' 'N' 'W' 'E'");
		}
		tmp = tmp->next;
	}
}

void	check_map(t_data *data, t_list **map)
{
	t_list *tmp;
	int		i;
	int		len;

	tmp = *map;
	i = 0;
	len = my_lstsize(tmp) - 6;
	data->map = (char **)malloc((len + 1) * sizeof(char *));
	while (i < 6)
	{
		if (tmp->content[0])
			i++;
		tmp = tmp->next;
	}
	len = 0;
	i = 0;
	// u should have a fanction to get the begest numure of line
	// ----->
	while (tmp)
	{
		if (tmp->content[0])
		{
			if ((i = ft_strlen(tmp->content)) > len)
				len = i;
		}
		tmp = tmp->next;
	}
	// ----->
	get_map(data, len, *map);
	// this is the result of this fonction :
	// N O   . / p a t h _ t o _ t h e _ n o r t h _ t e x t u r e . x p m S O   . / p a t h _ t o _ t h e _ s o u t h _ t e x t u r e . x p m W E   
	// . / p a t h _ t o _ t h e _ w e s t _ t e x t u r e . x p m E A   . / p a t h _ t o _ t h e _ e a s t _ t e x t u r e . x p m F   2 2 0   , 1 0 0   , 2 5 0 C
	// 2 2 5 , 3 0 , 01 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 11 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 11 0 1 1 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0
	// 0 11 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 0 1 1 0 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 1 1 1
	// 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1 1 1 1 1 1 1 0 1 1 1 0 0 0 0 0 0 1 0 0 0 1 1 1 1 1 0 1 1 1 11 1 1 1 1 0 1 1 1 0 1 0 1 0 0 1 0 0 0 1 1 1 0 0 0 0 0 0 1
	// 1 0 1 0 1 0 1 1 1 0 0 0 0 0 0 1 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 1 0 1 0 0 1 0 0 0 1 1 1
	// 0 0 0 0 0 1 1 1 0 1 0 1 0 1 1 1 1 1 0 1 1 1 1 0 N 0 1 1 1 1 1 1 1 0 1 1 1 1 1 1 0 1 0 11 0 1 1 1 1 0 1 0 0 0 1 1 1 1 1 1 1 1 11 1 1 1 1 1 11 1 1 1 1 1
}
