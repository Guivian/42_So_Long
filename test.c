/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:49:21 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/01 20:04:04 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	other_dudes_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}


int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		x = -1;
	int		y = -1;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Testing");
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.endian);
	while (y++ < 600)
	{
		x = -1;
		while (x++ < 800)
			other_dudes_mlx_pixel_put(&img, x, y, 0x0b59e0fc);
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
