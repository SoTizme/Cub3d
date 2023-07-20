/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:42:32 by shilal            #+#    #+#             */
/*   Updated: 2023/07/20 18:03:51 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_the_end(char *s, t_data *data, int j)
{
	int	i;
	int	len;

	i = 0;
	len = data->x;
	if (j == 0 || j == (data->y - 2))
	{
		while (i <= --len)
		{
			if (s[len] != '1' && s[len] != ' ')
				ft_error("Close map");
		}
	}
	while (i <= --len)
	{
		while (s[len] == ' ' && len >= 0)
			len--;
		if (len >= 0 && s[len] == '1')
			break ;
		else
			ft_error("Close map");
	}
}

int	the_middle(char **s, int j, int i, int len)
{
	if (s[i][j + 1] != '\0' && (s[i][j + 1] == '1' || s[i][j + 1] == ' '))
	{
		if (j != 0 && (s[i][j - 1] == ' ' || s[i][j - 1] == '1'))
		{
			if (i != 0 && (s[i - 1][j] == ' ' || s[i - 1][j] == '1'))
			{
				if (i != len && (s[i + 1][j] == ' ' || s[i + 1][j] == '1'))
				{
					return (1);
				}
				else if (i == len)
					return (1);
			}
			else if (i == 0)
				return (1);
		}
		else if (j == 0)
			return (1);
	}
	else if (s[i][j + 1] == '\0')
		return (1);
	return (0);
}

void	check_the_middle(t_data *data, int i, int j)
{
	while (data->map[i][j])
	{
		if (data->map[i][j] == ' ')
		{
			if (the_middle(data->map, j, i, data->y - 2) == 0)
				ft_error("Close your map");
		}
		j++;
	}
}

void	check_the_map(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j])
		{
			while (data->map[i][j] == ' ')
				j++;
			if (data->map[i][j] == '1')
			{
				check_the_end(data->map[i], data, i);
				check_the_middle(data, i, j);
				break ;
			}
			else if (data->map[i][j] && data->map[i][j] == '0')
				ft_error("Close your map");
		}
	}
}

void	check_map(t_data *data, t_list **map)
{
	t_list	*tmp;
	t_list	*check;
	int		i;

	tmp = *map;
	i = 0;
	data->y = (my_lstsize(tmp));
	data->map = (char **)malloc((data->y + 1) * sizeof(char *));
	while (i < 6 || (!tmp->content[0]))
	{
		if (tmp->content[0])
			i++;
		tmp = tmp->next;
	}
	check = tmp;
	data->x = get_the_tall_line(&check);
	get_map(data, data->x, tmp);
	i = data->check->t_ea + data->check->t_no + data->check->t_so;
	if ((i + data->check->t_we) != 5)
		ft_error("The position of player missing or is double in the map");
	check_the_map(data);
}
