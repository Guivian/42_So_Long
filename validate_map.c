/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:21:11 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/18 19:10:50 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**new_map(int fd, char **map, int count)
{
	char	*line;
	
	line = get_next_line(fd);
	if (line)
		new_map(fd, map, count + 1);
	else
	{
		map = malloc(sizeof(char) * (count + 1));
		if (map == NULL)
			return (NULL);
	}
	if (line)
		map[count] = creating_map(map[count], line);
//	free(line);
	return (map);
}
	