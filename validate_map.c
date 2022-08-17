/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:21:11 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/17 22:31:04 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**new_map(int fd, char **map, int count)
{
	char	*line;
	
	line = get_next_line(fd);
	if (line)
		new_map(fd, map, count + 1);
	/*else
	{
		map = malloc(sizeof(char *) * count + 1);
		map[count] = line;
	}*/
	return (NULL);
}
	