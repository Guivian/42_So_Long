/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:46:35 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/24 14:15:37 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_background(t_vars *vars, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	img->img = mlx_xpm_file_to_image(vars->mlx, BG, &img->width, &img->height);
	while (y < vars->height)
	{
		x = 0;
		while (x < vars->width)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, img->img, x, y);
			x = x + 64;
		}
		y = y + 64;
	}
}

void	put_walls(t_vars *vars, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	img->img = mlx_xpm_file_to_image(vars->mlx, WL, &img->width, &img-> height);
	vars->y = -1;
	while (vars->map[++vars->y])
	{
		vars->x = -1;
		x = 0;
		while (vars->map[vars->y][++vars->x])
		{
			if (vars->map[vars->y][vars->x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, img->img, x, y);
			x = x + 64;
		}
		y = y + 64;
	}
}

void	put_collectables(t_vars *vars, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	img->img = mlx_xpm_file_to_image(vars->mlx, CL, &img->width, &img-> height);
	vars->y = -1;
	while (vars->map[++vars->y])
	{
		vars->x = -1;
		x = 0;
		while (vars->map[vars->y][++vars->x])
		{
			if (vars->map[vars->y][vars->x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, img->img, x, y);
			x = x + 64;
		}
		y = y + 64;
	}
}

void	put_exit(t_vars *vars, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	img->img = mlx_xpm_file_to_image(vars->mlx, EX, &img->width, &img-> height);
	vars->y = -1;
	while (vars->map[++vars->y])
	{
		vars->x = -1;
		x = 0;
		while (vars->map[vars->y][++vars->x])
		{
			if (vars->map[vars->y][vars->x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, img->img, x, y);
			x = x + 64;
		}
		y = y + 64;
	}
}

void	put_player(t_vars *vars, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	img->img = mlx_xpm_file_to_image(vars->mlx, P, &img->width, &img->height);
	vars->y = -1;
	while (vars->map[++vars->y])
	{
		vars->x = -1;
		x = 0;
		while (vars->map[vars->y][++vars->x])
		{
			if (vars->map[vars->y][vars->x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, img->img, x, y);
			x = x + 64;
		}
		y = y + 64;
	}
}
