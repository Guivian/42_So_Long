/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:34:33 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/05 20:56:53 by lbarbosa         ###   ########.fr       */
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
			if (vars->map[vars->y][vars->x] == 'P' \
			&& vars->map[vars->y][vars->x + 1] != '1')
			{
				if (check_tile(vars, vars->x + 1, vars->y))
				{
					temp = vars->map[vars->y][vars->x + 1];
					vars->map[vars->y][vars->x + 1] = 'P';
					vars->map[vars->y][vars->x] = temp;
					mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->data->p_d, ((vars->x + 1) * 64), (vars->y * 64));
					mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->data->bg, ((vars->x) * 64), (vars->y * 64));
					return ;
				}
			}
		}
	}
}

void	move_down(t_vars *vars)
{
	char	temp;

	vars->y = -1;
	while (vars->map[++vars->y])
	{
		vars->x = -1;
		while (vars->map[vars->y][++vars->x])
		{
			if (vars->map[vars->y][vars->x] == 'P' \
			&& vars->map[vars->y + 1][vars->x] != '1')
			{
				if (check_tile(vars, vars->x, vars->y + 1))
				{
					temp = vars->map[vars->y + 1][vars->x];
					vars->map[vars->y + 1][vars->x] = 'P';
					vars->map[vars->y][vars->x] = temp;
					mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->data->p_s, (vars->x * 64), ((vars->y + 1) * 64));
					mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->data->bg, (vars->x * 64), (vars->y * 64));
					return ;
				}
			}
		}
	}
}

void	move_left(t_vars *vars)
{
	char	temp;

	vars->y = -1;
	while (vars->map[++vars->y])
	{
		vars->x = -1;
		while (vars->map[vars->y][++vars->x])
		{
			if (vars->map[vars->y][vars->x] == 'P' \
			&& vars->map[vars->y][vars->x - 1] != '1')
			{
				if (check_tile(vars, vars->x - 1, vars->y) != 0)
				{
					temp = vars->map[vars->y][vars->x - 1];
					vars->map[vars->y][vars->x - 1] = 'P';
					vars->map[vars->y][vars->x] = temp;
					mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->data->p_a, ((vars->x - 1) * 64), (vars->y * 64));
					mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->data->bg, (vars->x * 64), (vars->y * 64));
					return ;
				}
			}
		}
	}
}

void	move_up(t_vars *vars)
{
	char	temp;

	vars->y = -1;
	while (vars->map[++vars->y])
	{
		vars->x = -1;
		while (vars->map[vars->y][++vars->x])
		{
			if (vars->map[vars->y][vars->x] == 'P' \
			&& vars->map[vars->y - 1][vars->x] != '1')
			{
				if (check_tile(vars, vars->x, vars->y - 1) != 0)
				{
					temp = vars->map[vars->y - 1][vars->x];
					vars->map[vars->y - 1][vars->x] = 'P';
					vars->map[vars->y][vars->x] = temp;
					mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->data->p_w, (vars->x * 64), ((vars->y - 1) * 64));
					mlx_put_image_to_window(vars->mlx, vars->win, \
					vars->data->bg, (vars->x * 64), (vars->y * 64));
					return ;
				}
			}
		}
	}
}

int	check_tile(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'C')
	{
		vars->c_collectable++;
		vars->map[y][x] = '0';
	}
	else if (vars->map[y][x] == 'E')
	{
		if (vars->t_collectable != vars->c_collectable)
			return (0);
		else
		{
			free_so_long(vars);
			write(1, "You Won! :D\n", 13);
			exit (0);
		}
	}
	else if (vars->map[y][x] == 'X')
	{
		free_so_long(vars);
		write(1, "You Lost!? O.O\n", 16);
		exit (0);
	}
	vars->p_moves++;
	return (1);
}
