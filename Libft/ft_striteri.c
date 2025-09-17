/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:11:00 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/10 12:29:35 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	to_upperifeven(unsigned int c, char *a)
{
	if (c % 2 == 0)
		*a = ft_toupper(*a);
	else
		*a = ft_tolower(*a);
}
		*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int	main(void){
	char str[] = "aaabbbcccc";
	ft_striteri(str, to_upperifeven);
	printf("%s\n", str);
}
	*/