/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:49:21 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/22 16:00:38 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	main(int argc, char **argv)
{
	t_data	img;
	t_vars	vars;
	t_map	map;
	int		fd;

	if (argc != 2)
	{
		write(1, "Invalid number of Arguments\n", 29);
		return (0);
	}
	map.map = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "ERROR\nFile does not exist / File is corrupted\n", 47);
		return (0);
	}
	map.map = new_map(fd, map.map, 0);
	if (validate_map(map.map) == 0)
	{
		write (1, "ERROR\nProblem in Map Validation\n", 33);
		return (0);
	}
	vars.mlx = mlx_init();
	vars.height = 320;
	vars.width = 832;
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "Hangry Girlfriend");
	put_background(&vars, &img);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.endian);
	mlx_key_hook(vars.win, win_esc_close, &vars);
	mlx_hook(vars.win, 17, 0, win_close, &vars);
	mlx_loop(vars.mlx);
}
