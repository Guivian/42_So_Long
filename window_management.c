/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:52:54 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/29 17:42:35 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_management(t_vars *vars, t_data *img)
{
	vars->mlx = mlx_init();
	window_size(vars);
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, NAME);
	refresh_window(vars, img);
	// mlx_key_hook(vars->win, &key_handler, &vars);
	mlx_hook(vars->win, 2, (1L << 0), &key_handler, &vars);
	refresh_window(vars, img);
	mlx_hook(vars->win, 17, 0, &win_close, &vars);
	mlx_loop(vars->mlx);
}

int	win_close(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
	return (0);
}

int	key_handler(int keycode, t_vars *vars)
{
	vars->p_moves = 0;
	if (keycode == 65307)
	{
		if (vars->p_moves > 0)
			vars->p_moves = vars->p_moves - 1;
		exit(0);
	}
	else if (keycode == 100)
		move_right(vars);
	vars->p_moves++;
	return (0);
}

void	window_size(t_vars *vars)
{
	vars->height = -1;
	vars->width = -1;
	while (vars->map[++vars->height])
		;
	while (vars->map[0][++vars->width])
		;
	vars->height = vars->height * 64;
	vars->width = (vars->width - 1) * 64;
}

void	refresh_window(t_vars *vars, t_data *img)
{
	put_background(vars, img);
	put_walls(vars, img);
	put_collectables(vars, img);
	put_exit(vars, img);
	put_player(vars, img);
}
