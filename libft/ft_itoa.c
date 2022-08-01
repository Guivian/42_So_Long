/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 20:56:28 by lbarbosa          #+#    #+#             */
/*   Updated: 2021/11/11 17:20:31 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

static int	count_char(int n);
static void	reverse_string(char *str, int len);
static char	*convert_int(int n, int i, char *str);

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		cc;

	i = 0;
	if (n == 0)
	{
		str = (char *)malloc(sizeof(char) * 2);
		str[0] = '0';
		str[1] = 0;
		return (str);
	}
	cc = count_char(n);
	str = (char *)malloc(sizeof(char) * (cc + 1));
	if (str == NULL)
		return (NULL);
	str = convert_int(n, i, str);
	while (str[i])
		i++;
	reverse_string(str, i);
	return (str);
}

static int	count_char(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	reverse_string(char *str, int len)
{
	int		start;
	int		end;
	char	store;

	start = 0;
	end = len - 1;
	while (start < end)
	{
		store = str[start];
		str[start] = str[end];
		str[end] = store;
		start++;
		end--;
	}
}

static char	*convert_int(int n, int i, char *str)
{
	int	temp;
	int	isnegative;

	isnegative = 0;
	if (n < 0)
		isnegative = 1;
	while (n != 0)
	{
		if (n < 0)
			temp = (n % 10) * (-1);
		else
			temp = n % 10;
		str[i++] = temp + 48;
		n = n / 10;
	}
	if (isnegative == 1)
		str[i++] = 45;
	str[i] = 0;
	return (str);
}
