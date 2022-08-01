/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_number.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 19:07:58 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/02/27 19:39:22 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_unsigned_number(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 10)
		ret += ft_put_unsigned_number(n / 10);
	ret += ft_write(n % 10 + '0');
	return (ret);
}
