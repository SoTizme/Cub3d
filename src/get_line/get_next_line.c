/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shilal <shilal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:12:28 by shilal            #+#    #+#             */
/*   Updated: 2023/07/11 10:58:54 by shilal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_add_save(char *save, int fd)
{
	char	*buf;
	int		ret;

	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while ((!ft_strchr_1(save, '\n')))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == 0)
			break ;
		if (ret == -1)
		{
			free(buf);
			free(save);
			return (NULL);
		}
		buf[ret] = '\0';
		save = ft_strjoin_1(save, buf);
	}
	free(buf);
	return (save);
}

char	*ft_line(char *c)
{
	char	*line;
	int		j;
	int		i;

	j = 0;
	while (c[j] && c[j] != '\n')
		j++;
	if (c[j] == '\0')
		return (ft_strdup_1(c));
	j += 1;
	line = malloc(j + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < j)
	{
		line[i] = c[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save(char *s, char *line)
{
	char	*tmp;
	int		j;
	int		i;

	i = ft_strlen_1(line);
	j = ft_strlen_1(s) + 1;
	tmp = malloc((j - i));
	if (!tmp)
		return (NULL);
	j = 0;
	while (s[i])
	{
		tmp[j] = s[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	free(s);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (BUFFER_SIZE < 0)
		return (NULL);
	save = ft_add_save(save, fd);
	if (!save || save[0] == '\0')
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	line = ft_line(save);
	save = ft_save(save, line);
	return (line);
}
