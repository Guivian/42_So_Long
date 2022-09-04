/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:49:21 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/04 15:23:24 by lbarbosa         ###   ########.fr       */
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

	if (map)
	{
		y = -1;
		while (map[++y])
			free(map[y]);
		free(map);
	}
}

/*void	free_so_long(t_vars *vars)
{
	check_if_image_exist(vars->mlx, vars->data->bg);
	check_if_image_exist(vars->mlx, vars->data->walls);
	check_if_image_exist(vars->mlx, vars->data->food);
	check_if_image_exist(vars->mlx, vars->data->exit);
	check_if_image_exist(vars->mlx, vars->data->p_a);
	check_if_image_exist(vars->mlx, vars->data->p_d);
	check_if_image_exist(vars->mlx, vars->data->p_s);
	check_if_image_exist(vars->mlx, vars->data->p_w);
	check_if_image_exist(vars->mlx, vars->data->e_c);
	check_if_image_exist(vars->mlx, vars->data->e_0);
	check_if_image_exist(vars->mlx, vars->data->e_1);
	check_if_image_exist(vars->mlx, vars->data->e_2);
	check_if_image_exist(vars->mlx, vars->data->e_3);
	check_if_image_exist(vars->mlx, vars->data->e_4);
	check_if_image_exist(vars->mlx, vars->data->e_5);
	check_if_image_exist(vars->mlx, vars->data->e_6);
	if (vars->win)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}

void	check_if_image_exist(void	*mlx, void *img)
{
	if (img)
	{
		mlx_destroy_image(mlx, img);
		free(img);
	}
}*/
