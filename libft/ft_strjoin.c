/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:25:39 by lbarbosa          #+#    #+#             */
/*   Updated: 2021/11/06 18:03:06 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s1s2;

	if (s1 == NULL)
		return (NULL);
	i = (ft_strlen(s1)) + (ft_strlen(s2));
	s1s2 = (char *)malloc((sizeof(char) * i) + 1);
	if (s1s2 == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
	{
		s1s2[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s1s2[i + j] = s2[j];
		j++;
	}
	s1s2[i + j] = 0;
	return (s1s2);
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
