/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:49:21 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/03 17:07:04 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	img;
	t_vars	vars;
	int		fd;

	vars.data = &img;
	fd = open(argv[1], O_RDONLY);
	if (protections(argc, fd, argv) == 0)
		return (0);
	vars.map = new_map(fd, vars.map, 0);
	close(fd);
	if (validate_map(&vars) == 0)
	{
		write (1, "ERROR\nProblem in Map Validation\n", 33);
		free_map(vars.map);
		return (0);
	}
	window_management(&vars);
}

int	protections(int argc, int fd, char **argv)
{
	if (argc != 2)
	{
		write(1, "Invalid number of Arguments\n", 29);
		return (0);
	}
	if (fd == -1)
	{
		write(1, "ERROR\nFile does not exist / File is corrupted\n", 47);
		return (0);
	}
	if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4) != 0)
	{
		write (1, "ERROR\nInvalid file type\n", 25);
		return (0);
	}
	return (1);
}

void	free_map(char **map)
{
	int	y;

	y = -1;
	while (map[++y])
		free(map[y]);
	free(map);
}

void	free_so_long(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->data->bg);
	mlx_destroy_image(vars->mlx, vars->data->e_0);
	mlx_destroy_image(vars->mlx, vars->data->e_1);
	mlx_destroy_image(vars->mlx, vars->data->e_2);
	mlx_destroy_image(vars->mlx, vars->data->e_3);
	mlx_destroy_image(vars->mlx, vars->data->e_4);
	mlx_destroy_image(vars->mlx, vars->data->e_5);
	mlx_destroy_image(vars->mlx, vars->data->e_6);
	mlx_destroy_image(vars->mlx, vars->data->e_c);
	mlx_destroy_image(vars->mlx, vars->data->exit);
	mlx_destroy_image(vars->mlx, vars->data->food);
	mlx_destroy_image(vars->mlx, vars->data->walls);
	mlx_destroy_image(vars->mlx, vars->data->p_a);
	mlx_destroy_image(vars->mlx, vars->data->p_d);
	mlx_destroy_image(vars->mlx, vars->data->p_s);
	mlx_destroy_image(vars->mlx, vars->data->p_w);
	mlx_destroy_window(vars->mlx, vars->win);
}
