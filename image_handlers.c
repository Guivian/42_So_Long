/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:46:35 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/22 19:52:42 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_background(t_vars *vars, t_data *img)
{
	img->img = mlx_xpm_file_to_image(vars->mlx, BACKGROUND, &img->width, &img->height);
	vars->y = 0;
	while (vars->y < vars->height)
	{
		vars->x = 0;
		while (vars->x < vars->width)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, img->img, vars->x, vars->y);
			vars->x = vars->x + 64;
		}
		vars->y = vars->y + 64;
	}
}

void	put_walls(t_vars *vars, t_data *img, t_map *map)
{
	img->img = mlx_xpm_file_to_image(vars->mlx, "./Images/Walls.xpm", &img->width, &img-> height);
	vars->y = 0;
	while (map->map[vars->y])
	{
		vars->x = 0;
		while (map->map[vars->y][vars->x])
		{
			if (map->map[vars->y][vars->x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, img->img, vars->x, vars->y);
			vars->x = vars->x + 1;
		}
		vars->y = vars->y + 1;
	}
}
