/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 18:28:52 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/09 11:34:34 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	t_list *node1 = ft_lstnew(ft_strdup("Glorioso"));
	t_list *node2 = ft_lstnew(ft_strdup("SLB"));
	t_list *node3 = ft_lstnew(ft_strdup("Benfica"));
	node1 -> next = node2;
	node2 -> next = node3;
	node3 -> next = NULL;
	int size = ft_lstsize(node1);
	printf("%d", size);
}
	*/