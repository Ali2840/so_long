/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:08:23 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/10 12:22:20 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	del_content(void *content)
{
	free(content);
}
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*node1;
	t_list	*node2;

	lst = NULL;
	node1 = ft_lstnew(ft_strdup("SLB"));
	node2 = ft_lstnew(ft_strdup("SCP"));
	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);
	while(lst)
	{
		printf("%s\n", (char*)(lst ->content));
		lst = lst -> next;
	}
	ft_lstclear(&lst, del_content);
	if(!lst)
		printf("Lista Limpa");
}
*/