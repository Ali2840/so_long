/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:06:53 by gocaetan          #+#    #+#             */
/*   Updated: 2025/04/29 17:03:43 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

/*
int	main(void)
{
	char	str[20];

	ft_bzero(str, 10);
	str[10] = '\0';
	printf("String after ft_bzero():");
	for (int i = 0; i < 5; i++)
		printf("%d ", str[i]);
	return (0);
}
*/