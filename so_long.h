/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:47:28 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/23 13:58:31 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define NAME "Hangry Girlfriend"
# define BACKGROUND "./Images/Tiles1_64x64.xpm"
# include "mlx_linux/mlx.h"
# include "GNL/get_next_line.h"
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <stdbool.h>
# include <fcntl.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
	int		width;
	int		height;
}	t_data;

typedef struct s_vars{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		x;
	int		y;
}				t_vars;

typedef struct s_map{
	char	**map;
}	t_map;

char	**new_map(int fd, char **map, int nline);
char	*creating_map(char*src);
int		validate_map(char **map);
int		validate_map_line(char *map_line, int strlen);
int		validate_unique(char **map, int y);
int		validate_map_surroundings(char **map, int x_len);
void	put_background(t_vars *vars, t_data *img);
int		win_esc_close(int keycode, t_vars *vars);
int		win_close(int keycode, t_vars *vars);
void	window_and_background(t_vars *vars, t_data *img, t_map *map);
void	window_size(t_map *map, t_vars *vars);
int		protections(int argc, int fd);
void	put_walls(t_vars *vars, t_data *img, t_map *map);
void	put_collectables(t_vars *vars, t_data *img, t_map *map);
void	put_exit(t_vars *vars, t_data *img, t_map *map);
void	put_player(t_vars *vars, t_data *img, t_map *map);
void	refresh_window(t_vars *vars, t_data *img, t_map *map);
int		move_player(int keycode, t_vars *vars, t_data *img, t_map *map);
void	move_right(t_vars *vars, t_data *img, t_map *map);

#endif

/*
W - 119
A - 97
S -115
D - 100
Esc - 65307
0, 1, p, e, c, x
*/
