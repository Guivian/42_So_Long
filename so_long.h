/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:47:28 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/09/04 15:23:12 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define NAME "Hangry Girlfriend"
# define BG "./Images/Tiles1_64x64.xpm"
# define WL "./Images/Walls.xpm"
# define CL "./Images/Collectable.xpm"
# define EX "./Images/Exit.xpm"
# define PS "./Images/Player_Down.xpm"
# define PA "./Images/Player_Left.xpm"
# define PW "./Images/Player_Up.xpm"
# define PD "./Images/Player_Right.xpm"
# define E0 "./Images/Slime_0.xpm"
# define E1 "./Images/Slime_1.xpm"
# define E2 "./Images/Slime_2.xpm"
# define E3 "./Images/Slime_3.xpm"
# define E4 "./Images/Slime_4.xpm"
# define E5 "./Images/Slime_5.xpm"
# define E6 "./Images/Slime_6.xpm"
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
	void	*bg;
	void	*walls;
	void	*food;
	void	*exit;
	void	*p_s;
	void	*p_d;
	void	*p_a;
	void	*p_w;
	void	*e_c;
	void	*e_0;
	void	*e_1;
	void	*e_2;
	void	*e_3;
	void	*e_4;
	void	*e_5;
	void	*e_6;
	int		w;
	int		h;
}	t_data;

typedef struct s_vars{
	t_data	*data;
	void	*mlx;
	void	*win;
	int		height;
	int		width;
	int		x;
	int		y;
	char	**map;
	char	**valid_path;
	int		p_moves;
	int		t_collectable;
	int		c_collectable;
	int		frames;
}				t_vars;

char	**new_map(int fd, char **map, int nline);
char	*creating_map(char*src);
int		validate_map(t_vars *vars);
int		validate_map_line(char *map_line, int strlen);
int		validate_unique(char **map, int y);
int		validate_map_surroundings(char **map, int x_len);
void	put_background(t_vars *vars, t_data *img);
int		key_handler(int keycode, t_vars *vars);
int		win_close(int keycode, t_vars *vars);
void	window_management(t_vars *vars);
void	window_size(t_vars *vars);
int		protections(int argc, int fd, char **argv);
void	put_walls(t_vars *vars, t_data *img);
void	put_collectables(t_vars *vars, t_data *img);
void	put_exit(t_vars *vars, t_data *img);
void	put_player(t_vars *vars, t_data *img);
void	put_enemy(t_vars *vars, t_data *img);
int		refresh_window(t_vars *vars);
void	move_right(t_vars *vars);
void	move_down(t_vars *vars);
void	move_left(t_vars *vars);
void	move_up(t_vars *vars);
int		ft_strncmp(const char	*s1, const char	*s2, size_t n);
char	*ft_strrchr(const char *s, int c);
int		check_tile(t_vars *vars, int x, int y);
int		total_collectables(t_vars *vars);
char	*ft_itoa(int n);
void	open_enemy(t_vars *vars, t_data *img);
int		animation(t_vars	*vars);
void	free_so_long(t_vars *vars);
int		path(t_vars *vars);
int		validate_path(t_vars *vars, int y, int x);
void	prepare_path_validation(t_vars *vars, int y, int x);
void	locate_player(t_vars *vars);
int		path(t_vars *vars);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *s1);
void	copy_map(t_vars *vars);
void	free_map(char **map);

#endif
