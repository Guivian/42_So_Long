/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:46:35 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/31 19:13:59 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_background(t_vars *vars, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	img->bg = mlx_xpm_file_to_image(vars->mlx, BG, &img->w, &img->h);
	vars->y = -1;
	while (vars->map[++vars->y])
	{
		vars->x = -1;
		x = 0;
		while (vars->map[vars->y][++vars->x])
		{
			if (vars->map[vars->y][vars->x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, img->bg, x, y);
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
	img->walls = mlx_xpm_file_to_image(vars->mlx, WL, &img->w, &img-> h);
	vars->y = -1;
	while (vars->map[++vars->y])
	{
		vars->x = -1;
		x = 0;
		while (vars->map[vars->y][++vars->x])
		{
			if (vars->map[vars->y][vars->x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, img->walls, x, y);
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
	img->food = mlx_xpm_file_to_image(vars->mlx, CL, &img->w, &img-> h);
	vars->y = -1;
	while (vars->map[++vars->y])
	{
		vars->x = -1;
		x = 0;
		while (vars->map[vars->y][++vars->x])
		{
			if (vars->map[vars->y][vars->x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, img->food, x, y);
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
	img->exit = mlx_xpm_file_to_image(vars->mlx, EX, &img->w, &img-> h);
	vars->y = -1;
	while (vars->map[++vars->y])
	{
		vars->x = -1;
		x = 0;
		while (vars->map[vars->y][++vars->x])
		{
			if (vars->map[vars->y][vars->x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, img->exit, x, y);
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
	img->p_s = mlx_xpm_file_to_image(vars->mlx, PS, &img->w, &img->h);
	img->p_d = mlx_xpm_file_to_image(vars->mlx, PD, &img->w, &img->h);
	img->p_w = mlx_xpm_file_to_image(vars->mlx, PW, &img->w, &img->h);
	img->p_a = mlx_xpm_file_to_image(vars->mlx, PA, &img->w, &img->h);
	vars->y = -1;
	while (vars->map[++vars->y])
	{
		vars->x = -1;
		x = 0;
		while (vars->map[vars->y][++vars->x])
		{
			if (vars->map[vars->y][vars->x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, img->p_s, x, y);
			x = x + 64;
		}
		y = y + 64;
	}
}
