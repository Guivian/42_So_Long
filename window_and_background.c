/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_and_background.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:52:54 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/22 22:12:19 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	window_and_background(t_vars *vars, t_data *img, t_map *map)
{
	vars->mlx = mlx_init();
	window_size(map, vars);
	vars->win = mlx_new_window(vars->mlx, vars->width, vars->height, NAME);
	put_background(vars, img);
	put_walls(vars, img, map);
	put_collectables(vars, img, map);
	put_exit(vars, img, map);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->ll, &img->endian);
	mlx_key_hook(vars->win, win_esc_close, &vars);
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

int	win_esc_close(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == 65307)
		exit(0);
	return (0);
}

void	window_size(t_map *map, t_vars *vars)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (map->map[++y])
		;
	while (map->map[0][++x])
		;
	vars->height = y * 64;
	vars->width = (x - 1) * 64;
}
