/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:52:54 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/23 21:51:53 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_management(t_vars *vars, t_data *img)
{
	vars->mlx = mlx_init();
	window_size(vars);
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, NAME);
	refresh_window(vars, img);
	mlx_key_hook(vars->win, key_handler, &vars);
	move_right(vars);
	move_right(vars);
	refresh_window(vars, img);
	mlx_hook(vars->win, 17, 0, win_close, &vars);
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
	if (keycode == 65307)
		exit(0);
	else if (keycode == 100)
		move_right(vars);
	return (0);
}

void	window_size(t_vars *vars)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (vars->map[++y])
		;
	while (vars->map[0][++x])
		;
	vars->height = y * 64;
	vars->width = (x - 1) * 64;
}

void	refresh_window(t_vars *vars, t_data *img)
{
	put_background(vars, img);
	put_walls(vars, img);
	put_collectables(vars, img);
	put_exit(vars, img);
	put_player(vars, img);
}
