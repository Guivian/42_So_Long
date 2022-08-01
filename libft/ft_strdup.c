/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:44:20 by lbarbosa          #+#    #+#             */
/*   Updated: 2021/11/05 20:45:20 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s);
static char		*ft_strcpy(char *dest, const char *src);

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = ft_strlen(s1);
	s2 = malloc(sizeof(char) * i + 1);
	if (s2 == NULL)
		return (NULL);
	ft_strcpy(s2, s1);
	return (s2);
}

static size_t	ft_strlen(const char *s)
{
	int	nc;

	nc = 0;
	while (*s != 0)
	{
		s++;
		nc++;
	}
	return (nc);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
