/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:08:41 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/09 11:53:33 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
/*
int	main(void){
	t_list *node1 = ft_lstnew(ft_strdup("NN"));
	t_list *node2 = ft_lstnew(ft_strdup("SLB"));
	t_list *node3 = ft_lstnew(ft_strdup("VENCER"));
	node1 -> next = node2;
	node2 -> next = node3;
	node3 -> next = NULL;
	t_list *lst = ft_lstlast(node1);
}
	*/