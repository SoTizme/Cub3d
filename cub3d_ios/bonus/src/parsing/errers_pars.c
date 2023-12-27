/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errers_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoumani <mmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:38:08 by shilal            #+#    #+#             */
/*   Updated: 2023/08/12 12:02:07 by mmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_add_textur(t_data *data, char *s, char *chr)
{
	if (!ft_strcmp(chr, "EA"))
	{
		if (data->txtur->ea)
			free(data->txtur->ea);
		data->txtur->ea = ft_strdup(s);
		data->check->t_ea++;
	}
	else if (!ft_strcmp(chr, "DR"))
	{
		if (data->txtur->dr)
			free(data->txtur->dr);
		data->txtur->dr = ft_strdup(s);
		data->check->t_dr++;
	}
	else
		return ;
}

long	my_atoi(const char *str)
{
	char	*ptr;
	size_t	i;
	long	nb;
	int		sign;

	ptr = (char *)str;
	i = 0;
	sign = 1;
	nb = 0;
	while (ptr[i] == ' ' || ptr[i] == '\r' || ptr[i] == '\t' || ptr[i] == '\n'
		|| ptr[i] == '\v' || ptr[i] == '\f')
		i++;
	if (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i++] == '-')
			sign = -1;
	}
	while (ft_isdigit(ptr[i]))
	{
		nb = nb * 10 + (ptr[i] - 48);
		i++;
	}
	return (nb * sign);
}

void	ft_error(char *error_msg)
{
	printf("Error : %s\n", error_msg);
	exit (1);
}

void	texture_error(char *chr, char **s)
{
	double_free(s);
	if (!ft_strcmp(chr, "NO"))
		ft_error("Path to the north texture missing or somting wrong");
	else if (!ft_strcmp(chr, "SO"))
		ft_error("Path to the south texture missing or somting wrong");
	else if (!ft_strcmp(chr, "WE"))
		ft_error("Path to the west texture missing or somting wrong");
	else if (!ft_strcmp(chr, "EA"))
		ft_error("Path to the east texture missing or somting wrong");
	else
		ft_error("Path of the color missing or somting wrong");
}
