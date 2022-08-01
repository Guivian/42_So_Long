/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:55:12 by lbarbosa          #+#    #+#             */
/*   Updated: 2021/11/05 19:15:38 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*str1;

	str1 = (char *)b;
	i = 0;
	while ((size_t)i < len)
	{
		str1[i] = c;
		i++;
	}
	b = (void *)str1;
	return (b);
}
