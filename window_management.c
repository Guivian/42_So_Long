/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:52:54 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/04 15:22:34 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_management(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, NAME);
	refresh_window(vars);
	vars->p_moves = 0;
	vars->frames = 0;
	vars->t_collectable = total_collectables(vars);
	mlx_loop_hook(vars->mlx, animation, vars);
	mlx_hook(vars->win, 2, (1L << 0), &key_handler, vars);
	mlx_hook(vars->win, 17, 0, &win_close, vars);
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
	char	*str;

	if (keycode == 65307)
		exit(0);
	else if (keycode == 100 || keycode == 65363)
		move_right(vars);
	else if (keycode == 115 || keycode == 65364)
		move_down(vars);
	else if (keycode == 97 || keycode == 65361)
		move_left(vars);
	else if (keycode == 119 || keycode == 65362)
		move_up(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->data->walls, 0, 0);
	str = ft_itoa(vars->p_moves);
	mlx_string_put(vars->mlx, vars->win, 32, 32, 1, str);
	free(str);
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

int	refresh_window(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	put_background(vars, vars->data);
	put_walls(vars, vars->data);
	put_collectables(vars, vars->data);
	put_exit(vars, vars->data);
	put_player(vars, vars->data);
	open_enemy(vars, vars->data);
	put_enemy(vars, vars->data);
	return (1);
}
