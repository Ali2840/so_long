/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:08:35 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/01 18:08:31 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	to_uppercase(void *content)
{
	char	*str;
	int		i;

	str = (char*)content;
	i = 0;
	while(str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
gcc -Wall -Werror
	-Wextra ft_lstnew.c ft_lstiter.c ft_toupper.c ft_lstadd_back.c 
	ft_lstclear.c ft_strdup.c ft_lstlast.c ft_lstdelone.c

int	main(void)
{
	t_list	*lst;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*tmp;

	lst = NULL;
	node1 = ft_lstnew(ft_strdup("Hello"));
	node2 = ft_lstnew(ft_strdup("world"));
	node3 = ft_lstnew(ft_strdup("42"));
	if (!node1 || !node2 || !node3)
	{
		printf("Erro a criar nós.\n");
		return (1);
	}
	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);
	ft_lstadd_back(&lst, node3);
	ft_lstiter(lst, to_uppercase);
	tmp = lst;
	while(tmp)
	{
		printf("%s\n", (char*)tmp->content);
		tmp = tmp -> next;
	}
	ft_lstclear(&lst, free);
	return(0);
}
*/
