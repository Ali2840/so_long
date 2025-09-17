/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:08:07 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/09 12:03:27 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*
int	main(void)
{
	t_list *node1 = ft_lstnew(ft_strdup("S"));
	t_list *node2 = ft_lstnew(ft_strdup("L"));
	t_list *node3 = ft_lstnew(ft_strdup("BENFICA"));
	node1 -> next = node2;
	node2 -> next = NULL;
	ft_lstadd_back(&node1, node3);
	t_list *tmp = node1;
	while(tmp)
	{
		printf("%s\n", (char*)tmp -> content);
		tmp = tmp -> next;
	}
	free(node1);
	free(node2);
	free(node3);
}
*/