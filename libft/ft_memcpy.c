/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gocaetan <gocaetan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:09:29 by gocaetan          #+#    #+#             */
/*   Updated: 2025/05/07 16:53:03 by gocaetan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
esta funcao copia um certo valor de memoria de src para dest
dest_str - boco de memoria a ser preenchido
src_str - bloco de memoria a ser copiado par dest
n - numero de bytes a aser copiado
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_str;
	const unsigned char	*src_str;
	size_t				i;

	dest_str = (unsigned char *)dest;
	src_str = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_str[i] = src_str[i];
		i++;
	}
	return (dest_str);
}

/*
int	main(void)
{
	char	src[50] = "Alentejo";
	char	dest[50];

	printf("Before memcpy dest = %s\n", dest);
	ft_memcpy(dest, src, strlen(src)+1);
	printf("After memcpy dest = %s\n", dest);
	return(0);
}
	*/