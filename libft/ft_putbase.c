/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:26:25 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/02/27 19:40:52 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putbase(long long int n, char *base)
{
	int	ret;

	ret = 0;
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
		ret++;
	}
	if (n >= (long long int)ft_strlen(base))
		ret += ft_putbase(n / ft_strlen(base), base);
	ret += write(1, &base[n % ft_strlen(base)], 1);
	return (ret);
}
