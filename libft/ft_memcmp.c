/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:09:23 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/07 16:53:14 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	size_t				i;
	const unsigned char	*str2;

	i = 0;
	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return ((str1[i]) - (str2[i]));
		}
		i++;
	}
	return (0);
}
/*
int	main(void){
	char a [] = "Bora\0aaaa";
	char b [] = "Bora\0sigaa";
	size_t n = 3;
	int i = ft_memcmp(a, b, n);
	printf("%d\n", i);
}
	*/