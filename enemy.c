/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:58:57 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/03 13:52:36 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_enemy(t_vars *vars, t_data *img)
{
	int	x;
	int	y;

	y = 0;
	vars->y = -1;
	while (vars->map[++vars->y])
	{
		vars->x = -1;
		x = 0;
		while (vars->map[vars->y][++vars->x])
		{
			if (vars->map[vars->y][vars->x] == 'X')
				mlx_put_image_to_window(vars->mlx, vars->win, img->e_c, x, y);
			x = x + 64;
		}
		y = y + 64;
	}
}

void	open_enemy(t_vars *vars, t_data *img)
{
	img->e_c = mlx_xpm_file_to_image(vars->mlx, E0, &img->w, &img->h);
	img->e_0 = mlx_xpm_file_to_image(vars->mlx, E0, &img->w, &img->h);
	img->e_1 = mlx_xpm_file_to_image(vars->mlx, E1, &img->w, &img->h);
	img->e_2 = mlx_xpm_file_to_image(vars->mlx, E2, &img->w, &img->h);
	img->e_3 = mlx_xpm_file_to_image(vars->mlx, E3, &img->w, &img->h);
	img->e_4 = mlx_xpm_file_to_image(vars->mlx, E4, &img->w, &img->h);
	img->e_5 = mlx_xpm_file_to_image(vars->mlx, E5, &img->w, &img->h);
	img->e_6 = mlx_xpm_file_to_image(vars->mlx, E6, &img->w, &img->h);
}

int	animation(t_vars	*vars)
{
	if (vars->frames >= 0 && vars->frames <= 33)
		vars->data->e_c = vars->data->e_0;
	else if (vars->frames >= 34 && vars->frames <= 67)
		vars->data->e_c = vars->data->e_1;
	else if (vars->frames >= 68 && vars->frames <= 99)
		vars->data->e_c = vars->data->e_2;
	else if (vars->frames >= 100 && vars->frames <= 133)
		vars->data->e_c = vars->data->e_3;
	else if (vars->frames >= 134 && vars->frames <= 167)
		vars->data->e_c = vars->data->e_4;
	else if (vars->frames >= 168 && vars->frames <= 199)
		vars->data->e_c = vars->data->e_5;
	else if (vars->frames >= 200 && vars->frames <= 239)
		vars->data->e_c = vars->data->e_6;
	else if (vars->frames == 240)
		vars->frames = 0;
	vars->frames++;
	put_enemy(vars, vars->data);
	return (1);
}
