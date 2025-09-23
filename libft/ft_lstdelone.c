/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:08:28 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/11 19:38:36 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	del_content(void *content)
{
	printf("A apagar conteudo: %s\n", (char *)content);
	free(content);
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
int main()
{
	t_list *cont = ft_lstnew(ft_strdup("SLB"));
	ft_lstdelone(cont, del_content);
}
	*/