/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:53:56 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/02/20 19:38:25 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

static char	*trim(const char *s1, const char *set, char *trimmed);
static char	*trimmed_malloc(const char *s1, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;

	if (s1 == NULL)
		return (NULL);
	trimmed = trimmed_malloc(s1, set);
	if (trimmed == NULL)
		return (NULL);
	trim(s1, set, trimmed);
	return (trimmed);
}

static char	*trim(const char *s1, const char *set, char *trimmed)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (s1[j])
		j++;
	j = j - 1;
	while (s1[k])
	{
		if (ft_strchr(set, s1[i]))
			i++;
		if (ft_strchr(set, s1[j]))
			j--;
		k++;
	}
	k = 0;
	while (i <= j)
		trimmed[k++] = s1[i++];
	trimmed[k] = 0;
	return (trimmed);
}

static char	*trimmed_malloc(const char *s1, const char *set)
{
	char	*trimmed;
	int		trimmedlen;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[j])
	{
		if (ft_strchr(set, s1[i]))
			i++;
		j++;
	}
	j = j - 1;
	while (j > i)
	{
		if (ft_strchr(set, s1[j]))
			j--;
		else
			break ;
	}
	trimmedlen = j - i;
	trimmed = (char *)malloc(sizeof(char) * (trimmedlen + 2));
	return (trimmed);
}
