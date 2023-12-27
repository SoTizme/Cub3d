/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 07:58:46 by shilal            #+#    #+#             */
/*   Updated: 2023/07/11 09:33:33 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_1(const char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i] != '\0')
			i++;
	}
	return (i);
}

char	*ft_strdup_1(const char *s1)
{
	char	*p;
	char	*cpy;
	int		len;
	int		i;

	p = (char *)s1;
	len = ft_strlen_1(s1);
	cpy = (char *)malloc(len + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (p[i] != '\0')
	{
		cpy[i] = p[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*ft_strjoin_1(char *st1, char *st2)
{
	char	*cpy;
	int		i;
	int		j;

	if (!st1 && st2)
		return (ft_strdup_1(st2));
	cpy = malloc((ft_strlen_1(st1) + ft_strlen_1(st2)) + 1);
	if (!cpy)
		return (NULL);
	i = 0;
	while (st1[i] != '\0')
	{
		cpy[i] = st1[i];
		i++;
	}
	j = 0;
	while (st2[j] != '\0')
		cpy[i++] = st2[j++];
	cpy[i] = '\0';
	free(st1);
	return (cpy);
}

char	*ft_strchr_1(const char *s, int c)
{
	char	*cpy;
	char	l;
	int		i;

	i = 0;
	if (s)
	{
		cpy = (char *)s;
		l = (unsigned char)c;
		while (cpy[i] != '\0')
		{
			if (cpy[i] == l)
				return (cpy + i);
			i++;
		}
		if (l == '\0')
			return (cpy);
	}
	return (0);
}
