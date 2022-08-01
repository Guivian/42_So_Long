/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarbosa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:56:46 by lbarbosa          #+#    #+#             */
/*   Updated: 2022/03/07 17:37:39 by lbarbosa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;
	t_list	*temp;

	head = NULL;
	temp = (t_list *)malloc(sizeof(t_list));
	if (temp == NULL)
		return (NULL);
	temp->content = content;
	temp->next = NULL;
	head = temp;
	return (head);
}
