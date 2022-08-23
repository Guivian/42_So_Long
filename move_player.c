/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:34:33 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/23 13:57:43 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_player(int keycode, t_vars *vars, t_data *img, t_map *map)
{
	if (keycode == 100)
		move_right(vars, img, map);
	return (1);
}

void	move_right(t_vars *vars, t_data *img, t_map *map)
{
	char temp;

	temp = '0';
	vars->y = -1;
	while (map->map[++vars->y])
	{
		vars->x = -1;
		while (map->map[vars->y][++vars->x])
		{
			if (map->map[vars->y][vars->x] == 'P')
				break ;
		}
		if (map->map[vars->y][vars->x] == 'P')
			break ;
	}
	if (map->map[vars->y][vars->x + 1] != '1')
	{
		temp = map->map[vars->y][vars->x + 1];
		map->map[vars->y][vars->x + 1] = 'P';
		map->map[vars->y][vars->x] = temp;
	}
	refresh_window(vars, img, map);
}
