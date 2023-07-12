/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:38:08 by shilal            #+#    #+#             */
/*   Updated: 2023/07/12 18:39:10 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_error(char *error_msg)
{
	printf("Error : %s\n", error_msg);
	exit (0);
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
}
