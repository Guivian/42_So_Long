/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uli_base.c                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:26:25 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/02/27 19:43:42 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_uli_base(unsigned long int n, char *base)
{
	int	ret;

	ret = 0;
	if (n >= (unsigned long int)ft_strlen(base))
		ret += ft_uli_base(n / ft_strlen(base), base);
	ret += write(1, &base[n % ft_strlen(base)], 1);
	return (ret);
}
