/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:01:37 by lbarbosa          #+#    #+#             */
/*   Updated: 2021/10/28 20:24:22 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	int		i;
	char	*dest1;
	char	*src1;

	dest1 = (char *)dest;
	src1 = (char *)src;
	i = 0;
	if (src == NULL && dest == NULL)
		return (0);
	while ((size_t)i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	dest = (void *)dest1;
	return (dest);
}
