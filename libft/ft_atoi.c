/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:46:48 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/24 20:45:21 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c);

int	ft_atoi(const char *str)
{
	int	i;
	int	value;
	int	fakestring;

	i = 0;
	fakestring = 0;
	value = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' && str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		value = 0;
		i++;
	}
	else if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		fakestring = (fakestring * 10) + (str[i] - '0');
		i++;
	}
	if (value == 0)
		fakestring = -fakestring;
	return (fakestring);
}

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	else if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}
