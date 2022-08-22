/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_protections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:13:17 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/08/22 19:48:49 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	protections1(int argc, int fd)
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
	return (1);
}
