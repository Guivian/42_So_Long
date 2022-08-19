/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:21:11 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/19 21:31:01 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**new_map(int fd, char **map, int count)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		map = new_map(fd, map, count + 1);
	else
	{
		map = malloc(sizeof(char *) * (count + 1));
		if (map == NULL)
			return (NULL);
		return (map);
	}
	if (line)
		map[count] = line;
	return (map);
}

int	validate_map(char **map)
{
	int	y;

	y = -1;
	while (map[++y])
		if (validate_map_line(map[y], ft_strlen(map[0])) == 0)
			return (0);
	if (validate_map_surroundings(map, ft_strlen(map[0])) == 0)
		return (0);
	y = -1;
	if (validate_unique(map, y) == 0)
		return (0);
	return (1);
}

int	validate_map_line(char *map_line, int strlen)
{
	int	x;
	int	control_char;

	x = -1;
	if (ft_strlen(map_line) != (size_t)strlen)
		return (0);
	while (map_line[++x])
	{
		if (map_line[x] == '0' || map_line[x] == '1' || map_line[x] == 'P')
			control_char = 1;
		else if (map_line[x] == 'E' || map_line[x] == 'C' || map_line[x] == 'X')
			control_char = 1;
		else if (map_line[x] == '\n')
			control_char = 1;
		else
			return (0);
	}
	return (control_char);
}

int	validate_unique(char **map, int y)
{
	int	x;
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
				p++;
			if (map[y][x] == 'E')
				e++;
			if (map[y][x] == 'C')
				c++;
		}
	}
	if (p != 1 || e != 1 || c < 1)
		return (0);
	return (1);
}

int	validate_map_surroundings(char **map, int x_len)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		if (map[y][0] != '1')
			return (0);
		if (map[y][x_len - 2] != '1')
			return (0);
	}
	x = -1;
	while (++x <= x_len - 2)
	{
		if (map[0][x] != '1')
			return (0);
		if (map[y - 1][x] != '1')
			return (0);
	}
	return (1);
}
