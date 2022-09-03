/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 09:37:02 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/03 17:19:23 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(t_vars *vars)
{
	vars->y = -1;
	vars->x = -1;

	while (vars->map[++vars->y])
		;
	while (vars->map[0][++vars->x])
		;
	vars->valid_path = malloc(sizeof(char *) * (vars->y));
	vars->y = -1;
	while (vars->map[++vars->y])
		vars->valid_path[vars->y] = ft_strdup(vars->map[vars->y]);
}

void	locate_player(t_vars *vars)
{
	vars->y = -1;
	while (vars->valid_path[++vars->y])
	{
		vars->x = -1;
		while (vars->valid_path[vars->y][++vars->x] && \
		vars->valid_path[vars->y][vars->x] != 'P')
			;
		if (vars->valid_path[vars->y][vars->x] == 'P')
			break ;
	}
}

void	prepare_path_validation(t_vars *vars, int y, int x)
{
	vars->valid_path[y][x] = 'P';
	if (x - 1 > -1 && (vars->valid_path[y][x - 1] == 'C' || \
	vars->valid_path[y][x - 1] == '0'))
		prepare_path_validation(vars, y, x - 1);
	if (y - 1 > -1 && (vars->valid_path[y - 1][x] == 'C' || \
	vars->valid_path[y - 1][x] == '0'))
		prepare_path_validation(vars, y - 1, x);
	if (x + 1 < (vars->width / 64) && \
	(vars->valid_path[y][x + 1] == 'C' || vars->valid_path[y][x + 1] == '0'))
		prepare_path_validation(vars, y, x + 1);
	if (y + 1 < (vars->height / 64) && \
	(vars->valid_path[y + 1][x] == 'C' || vars->valid_path[y + 1][x] == '0'))
		prepare_path_validation(vars, y + 1, x);
	return ;
}

int	validate_path(t_vars *vars, int y, int x)
{
	if (vars->valid_path[y][x] == 'C')
		return (0);
	if (vars->valid_path[y][x] == 'E')
	{
		if (vars->valid_path[y][x - 1] != 'P' \
		&& vars->valid_path[y - 1][x] != 'P' \
		&& vars->valid_path[y][x + 1] != 'P' \
		&& vars->valid_path[y + 1][x] != 'P')
			return (0);
	}
	return (1);
}

int	path(t_vars *vars)
{
	int	y;
	int	x;

	y = -1;
	copy_map(vars);
	locate_player(vars);
	prepare_path_validation(vars, vars->y, vars->x);
	while (++y < (vars->height / 64))
	{
		x = -1;
		while (vars->valid_path[y][++x])
			if (validate_path(vars, y, x) == 0)
			{
				free(vars->valid_path);
				return (0);
			}
	}
	return (1);
}
