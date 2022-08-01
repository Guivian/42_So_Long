/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:35:42 by lbarbosa          #+#    #+#             */
/*   Updated: 2021/11/13 18:35:45 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*lst_next;

	if (lst == NULL || del == NULL)
		return ;
	lst_next = *lst;
	while (lst_next)
	{
		temp = lst_next->next;
		del(lst_next->content);
		free(lst_next);
		lst_next = temp;
	}
	*lst = NULL;
}
