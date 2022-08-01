/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:55:51 by lbarbosa          #+#    #+#             */
/*   Updated: 2021/10/31 20:55:26 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stddef.h>

int	ft_strncmp(const char	*s1, const char	*s2, size_t n)
{
	unsigned int	i;

	i = 0;
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
