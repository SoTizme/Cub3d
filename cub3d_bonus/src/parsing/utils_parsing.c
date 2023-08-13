/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:31:54 by shilal            #+#    #+#             */
/*   Updated: 2023/08/13 18:46:55 by mmoumani         ###   ########.fr       */
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

int	get_the_tall_line(t_data *data)
{
	t_list	*tmp;
	int		i;
	int		len;

	i = 0;
	len = 0;
	tmp = skp_utils(data->s_map);
	len = ft_strlen(tmp->content);
	while (tmp)
	{
		if (!tmp->content[0])
			ft_error("Invalid map");
		i = ft_strlen(tmp->content);
		if (len < i)
			len = i;
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

void	get_map(t_data *data)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		c;

	i = -1;
	tmp = skp_utils(data->s_map);
	while (tmp)
	{
		j = 0;
		while (tmp->content[j])
		{
			c = tmp->content[j];
			if (c != ' ' && c != '1' && c != '2' && c != '0' && c != 'S' && c != 'N'
				&& c != 'W' && c != 'E' && c != 9)
				ft_error("Ther's an  error in your map");
			cont_texture(data, c);
			j++;
		}
		data->map[++i] = my_strdup(tmp->content, data->width);
		tmp = tmp->next;
	}
	data->map[i + 1] = NULL;
}

char	**get_texture(char *s)
{
	char	**str;
	int		i;
	int		j;

	str = (char **)malloc(3 * sizeof(char *));
	i = -1;
	j = -1;
	str[0] = malloc(3);
	while (j < 2 && s[++i])
		str[0][++j] = s[i];
	str[0][j] = '\0';
	if (s[j] == ' ')
	{
		while (s[i] && s[i] == ' ')
			i++;
		str[1] = ft_strdup(s + i);
		str[2] = NULL;
	}
	else
		str[1] = NULL;
	return (str);
}
