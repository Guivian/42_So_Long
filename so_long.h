/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:47:28 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/22 15:54:24 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
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
	int		map_size;
}	t_map;

char	**new_map(int fd, char **map, int nline);
char	*creating_map(char*src);
int		validate_map(char **map);
int		validate_map_line(char *map_line, int strlen);
int		validate_unique(char **map, int y);
int		validate_map_surroundings(char **map, int x_len);
void	put_background(t_vars *vars, t_data *img);

#endif

/*
W - 119
A - 97
S -115
D - 100
Esc - 65307
0, 1, p, e, c, x
*/
