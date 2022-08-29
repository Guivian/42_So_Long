/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <lbarbosa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:43:00 by lbarbosa          #+#    #+#             */
/*   Updated: 2021/12/18 18:41:17 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*find_nl(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
			return (&s[i]);
		i++;
	}
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*s1s2;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = 0;
	}
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1s2 = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s1s2 == NULL)
		return (NULL);
	if (s1)
		while (s1[++i])
			s1s2[i] = s1[i];
	while (s2[j])
		s1s2[i++] = s2[j++];
	s1s2[i] = 0;
	free(s1);
	return (s1s2);
}
