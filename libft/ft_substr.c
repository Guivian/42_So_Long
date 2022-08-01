/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 18:11:34 by lbarbosa          #+#    #+#             */
/*   Updated: 2021/11/06 20:39:22 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	sizemal;

	if (!s)
		return (NULL);
	sizemal = ft_strlen(s) - start;
	i = 0;
	if (start > ft_strlen(s))
	{
		substring = (char *)malloc(1);
		substring[0] = 0;
		return (substring);
	}
	if (sizemal < len)
		substring = (char *)malloc(sizeof(char) * (sizemal + 1));
	else
		substring = ((char *)malloc((sizeof(char) * (len + 1))));
	if (substring == NULL)
		return (NULL);
	else if (substring != NULL)
		while (s[start] && i < len)
			substring[i++] = s[start++];
	substring[i] = 0;
	return (substring);
}
