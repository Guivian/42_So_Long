/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:37:15 by lbarbosa          #+#    #+#             */
/*   Updated: 2021/10/25 10:26:41 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	*ft_memmove(void	*dst, const void	*src, size_t len)
{
	size_t				i;
	unsigned char		*chardst;
	const unsigned char	*charsrc;

	i = 0;
	chardst = (unsigned char *)dst;
	charsrc = (unsigned char *)src;
	if (!chardst && !charsrc)
		return (NULL);
	if (charsrc < chardst)
		while (++i <= len)
			chardst[len - i] = charsrc[len - i];
	else
		while (len-- > 0)
			*(chardst++) = *(charsrc++);
	return (dst);
}
