/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:49:21 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/22 19:20:24 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	img;
	t_vars	vars;
	t_map	map;
	int		fd;

	map.map = NULL;
	fd = open(argv[1], O_RDONLY);
	if (protections1(argc, fd) == 0)
		return (0);
	map.map = new_map(fd, map.map, 0);
	if (validate_map(map.map) == 0)
		return (0);
	window_and_background(&vars, &img, &map);
}
