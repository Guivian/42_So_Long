/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:51:19 by lbarbosa          #+#    #+#             */
/*   Updated: 2021/10/28 20:17:12 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stddef.h>

static size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(dest);
	j = 0;
	if (dstsize <= i)
		return (dstsize + ft_strlen(src));
	while (src[j] && i + 1 < dstsize)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (ft_strlen(dest) + ft_strlen(&src[j]));
}

static size_t	ft_strlen(const char *s)
{
	int	nc;

	nc = 0;
	while (*s != '\0')
	{
		s++;
		nc++;
	}
	return (nc);
}
