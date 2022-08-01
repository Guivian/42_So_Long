/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:05:23 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/05/02 17:39:27 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_arrcpy(int *src, int *dst, int len)
{
	int	i;

	dst = malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
		dst[i] = src[i];
	return (dst);
}
