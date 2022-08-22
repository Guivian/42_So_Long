/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:46:35 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/22 16:00:03 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_background(t_vars *vars, t_data *img)
{
	img->img = mlx_xpm_file_to_image(vars->mlx, "./Images/Tiles1_64x64.xpm", &vars->width, &vars->height);
	vars->y = 0;
	while (vars->y < 320)
	{
		vars->x = 0;
		while (vars->x < 832)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, img->img, vars->x, vars->y);
			vars->x = vars->x + 64;
		}
		vars->y = vars->y + 64;
	}
}
