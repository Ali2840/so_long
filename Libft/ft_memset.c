/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:25:28 by gocaetan          #+#    #+#             */
/*   Updated: 2025/04/29 17:59:52 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
esta funcao preenche espacos de memoria
str - bloco de memoria a ser usado
c - valor para preencher str com n bytes
n - numero de bytes a preencher
*/
void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*
int	main(void)
{
	char	str[20];

	ft_memset(str, 'Z', 10); // preenche 10 espacos da memoria com Z
	str[10] = '\0';          // da o fim a string
	printf("String after memset(): %s\n", str);
	return (0);
}
*/