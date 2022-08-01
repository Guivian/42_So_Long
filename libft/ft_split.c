/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 19:33:51 by lbarbosa          #+#    #+#             */
/*   Updated: 2021/11/12 21:00:19 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	count_to_be_strings(const char *s1, char c);
static char	*put_string(const char *s1, int start, int finish);
static void	create_splitted(const char *s1, char c, char **splitted);

char	**ft_split(char const *s1, char c)
{
	char	**splitted;

	if (s1 == NULL)
		return (NULL);
	splitted = malloc(sizeof(char *) * ((count_to_be_strings(s1, c)) + 1));
	if (splitted == NULL)
		return (NULL);
	create_splitted(s1, c, splitted);
	return (splitted);
}

static int	count_to_be_strings(const char	*s1, char c)
{
	int	i;
	int	control;

	i = 0;
	control = 0;
	while (*s1)
	{
		if (*s1 != c && control == 0)
		{
			control = 1;
			i++;
		}
		else if (*s1 == c)
			control = 0;
		s1++;
	}
	return (i);
}

static char	*put_string(const char *s1, int start, int finish)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (finish - start) + 1);
	while (start < finish)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}

static void	create_splitted(const char *s1, char c, char **splitted)
{
	size_t	i;
	int		j;
	int		control;

	i = 0;
	j = 0;
	control = -1;
	while (i <= ft_strlen(s1))
	{
		if (s1[i] != c && control < 0)
			control = i;
		else if ((s1[i] == c || i == ft_strlen(s1)) && control >= 0)
		{
			splitted[j++] = put_string(s1, control, i);
			control = -1;
		}
		i++;
	}
	splitted[j] = 0;
}
