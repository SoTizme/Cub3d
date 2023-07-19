/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:42:32 by shilal            #+#    #+#             */
/*   Updated: 2023/07/19 17:46:43 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	data->map[i] = NULL;
}


// this fonction check id the line lwl dyalha fih '1' 
void	check_the_map(t_data *data, int len)
{
	int		i;
	int		j;

	i = 0;
	(void)len;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			while (data->map[i][j] && data->map[i][j] == ' ')
				j++;
			if (data->map[i][j] && data->map[i][j] == '1')
				break ;
			else if (data->map[i][j] && data->map[i][j] == '0')
				ft_error("Close your map");
			j++;
		}
		i++;
	}
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
	i = data->check->t_ea + data->check->t_no + data->check->t_so;
	if ((i + data->check->t_we) != 5)
		ft_error("The position of player missing or is double in the map");
	check_the_map(data, len);
	// check na9sso wah line msdooda aussi and wach lfaragat valid ta homa.
}
