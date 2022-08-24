/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 18:49:21 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/24 14:07:03 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	img;
	t_vars	vars;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (protections(argc, fd, argv) == 0)
		return (0);
	vars.map = new_map(fd, vars.map, 0);
	if (validate_map(vars.map) == 0)
		return (0);
	window_management(&vars, &img);
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

int	ft_strncmp(const char	*s1, const char	*s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (1);
	while (s1[i] == s2[i] && i < n - 1)
	{
		if (s1[i] == 0 || s2[i] == 0)
			break ;
		i++;
	}
	if (n == 0)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)s;
	while (ptr[i])
		i++;
	while (i >= 0)
	{
		if (ptr[i] == (unsigned char)c)
			return (&ptr[i]);
		i--;
	}
	return (NULL);
}
