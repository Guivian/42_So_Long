/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:34:33 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/23 21:22:16 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_vars *vars)
{
	char	temp;

	vars->y = -1;
	while (vars->map[++vars->y])
	{
		vars->x = -1;
		while (vars->map[vars->y][++vars->x])
		{
			if (vars->map[vars->y][vars->x] == 'P')
			{
				if (vars->map[vars->y][vars->x + 1] != '1')
				{
					temp = vars->map[vars->y][vars->x + 1];
					vars->map[vars->y][vars->x + 1] = 'P';
					vars->map[vars->y][vars->x] = temp;
					return ;
				}
			}
		}
	}
}
