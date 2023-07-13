/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:50:51 by shilal            #+#    #+#             */
/*   Updated: 2023/07/13 14:06:34 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	util_color(t_data *data, char **colrs, char c, int i)
{
	int	nb;

	if (i > 2)
			ft_error("The prototype of the color is ( N,N,N ) and N (0 -> 255)");
	if (colrs[0] && !colrs[1])
	{
		nb = ft_atoi(is_dgit(colrs[0]));
		if (nb >= 0 && nb <= 255)
		{
			if (c == 'F')
			{
				data->txtur->f[i] = nb;
				data->t_f++;
			}
			else if (c == 'C')
			{
				data->txtur->c[i] = nb;
				data->t_c++;
			}
		}
		else
			ft_error("the color range is (0 -> 255)");
	}
}

void	check_color(t_data *data, char *line, char chr)
{
	char	**colrs;
	char	**s;
	int		i;

	i = 0;
	if (line[ft_strlen(line) - 1] == ',')
		ft_error("The prototype of the color is (N,N,N) and N (0 -> 255)");
	if (line[0] == chr && line[1] == ' ')
	{
		colrs = ft_split(line + 1, ',');
		while (colrs[i])
		{
			s = ft_split(colrs[i], ' ');
			util_color(data, s, chr, i);
			double_free(s);
			i++;
		}
		double_free(colrs);
	}
}

void	add_textur(t_data *data, char *s, char *chr)
{
	if (!ft_strcmp(chr, "NO"))
	{
		data->txtur->no = ft_strdup(s);
		data->t_no++;
	}
	else if (!ft_strcmp(chr, "SO"))
	{
		data->txtur->so = ft_strdup(s);
		data->t_so++;
	}
	else if (!ft_strcmp(chr, "WE"))
	{
		data->txtur->we = ft_strdup(s);
		data->t_we++;
	}
	else if (!ft_strcmp(chr, "EA"))
	{
		data->txtur->ea = ft_strdup(s);
		data->t_ea++;
	}
}

void	texture(char *line, t_data *data)
{
	char	**l;

	l = ft_split(line, ' ');
	if (!ft_strcmp(l[0], "NO") || !ft_strcmp(l[0], "SO") 
		|| !ft_strcmp(l[0], "WE") || !ft_strcmp(l[0], "EA"))
	{
		if (l[1] && !l[2])
		{
			if (check_file_format(l[1], ".xpm"))
			{
				add_textur(data, l[1], l[0]);
				return (double_free(l));
			}
			else
				ft_error("Check texture format .xpm");
		}
		else
			texture_error(l[0], l);
	}
	double_free(l);
}

void	check_texture(t_data *data, t_list **map)
{
	t_list *tmp;
	int		i;

	tmp = *map;
	i = 7;
	while (tmp && i)
	{
		if (tmp->content[0])
		{
			texture(tmp->content, data);
			check_color(data, tmp->content, 'F');
			check_color(data, tmp->content, 'C');
			i--;
		}
		tmp = tmp->next;
	}
	if (data->t_ea != 1 || data->t_so != 1 || data->t_no != 1 || data->t_we != 1 || 
		data->t_c != 3 ||data->t_f != 3)
		ft_error("Check if any texture/color missing Or double");
	else
	{
		int i = 0;
		printf("%s\n", data->txtur->no);
		printf("%s\n", data->txtur->so);
		printf("%s\n", data->txtur->we);
		printf("%s\n", data->txtur->ea);
		while (i < 3)
		{
			printf("F : %d\n", data->txtur->f[i]);
			printf("C : %d\n", data->txtur->c[i]);
			i++;
		}
	}
}
