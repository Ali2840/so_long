/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:08:57 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/16 11:10:59 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
void	*to_uppercase(void *content)
{
	char	*str;
	char	*new_str;
	int		i;

	str = (char *)content;
	new_str = ft_strdup(str);
	i = 0;
	if (!new_str)
		return (NULL);
	while (new_str[i])
	{
		new_str[i] = ft_toupper(new_str[i]);
		i++;
	}
	return (new_str);
}

void	del_cont(void *content)
{
	free(content);
}
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*elem;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		elem = ft_lstnew(new_content);
		if (!elem)
		{
			del(new_content);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, elem);
		lst = lst->next;
	}
	return (new_lst);
}
/*
int	main(void)
{
	t_list	*lst;
	t_list	*node1;
	t_list	*node2;
	t_list	*map;

	lst = NULL;
	node1 = ft_lstnew(ft_strdup("slb"));
	node2 = ft_lstnew(ft_strdup("scp"));
	ft_lstadd_back(&lst, node1);
	ft_lstadd_back(&lst, node2);
	map = ft_lstmap(lst, to_uppercase, del_cont);
	printf("%s\n", (char*)map -> content);
}
*/