/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:18:58 by lbarbosa          #+#    #+#             */
/*   Updated: 2021/12/18 18:36:56 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	saved = feed_saved(fd, saved);
	if (saved == NULL)
		return (NULL);
	line = find_line(saved);
	saved = after_nl(saved);
	return (line);
}

char	*feed_saved(int fd, char *saved)
{
	char	*buf;
	int		read_ret;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	read_ret = 1;
	while (!find_nl(saved) && read_ret != 0)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[read_ret] = 0;
		saved = gnl_strjoin(saved, buf);
	}
	free(buf);
	return (saved);
}

char	*find_line(char *saved)
{
	char	*line;
	int		i;

	i = 0;
	if (saved[i] == 0)
		return (NULL);
	while (saved[i] != 0 && saved[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (saved[i] != 0 && saved[i] != '\n')
	{
		line[i] = saved[i];
		i++;
	}
	if (saved[i] == '\n')
	{
		line[i] = saved[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

char	*after_nl(char *saved)
{
	char	*new_saved;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (saved[i] != 0 && saved[i] != '\n')
		i++;
	if (saved[i] == 0)
	{
		free(saved);
		return (NULL);
	}
	new_saved = malloc(sizeof(char) * (ft_strlen(saved) - i + 1));
	if (new_saved == NULL)
		return (NULL);
	i++;
	while (saved[i])
		new_saved[j++] = saved[i++];
	new_saved[j] = 0;
	free(saved);
	return (new_saved);
}
