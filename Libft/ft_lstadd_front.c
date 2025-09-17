/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:08:16 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/09 12:28:51 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list *node1 = ft_lstnew(ft_strdup("S"));
	t_list *node2 = ft_lstnew(ft_strdup("G"));
	t_list *node3 = ft_lstnew(ft_strdup("P"));
	node1 -> next = node2;
	node2 -> next = NULL;
	ft_lstadd_front(&node1, node3);
	t_list *tmp = node3;
	while(tmp)
	{
		printf("%s\n", (char*)tmp -> content);
		tmp = tmp -> next;	
	}
	ft_lstclear(&node3, free);
}
	*/